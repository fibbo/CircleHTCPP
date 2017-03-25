# Basic classes and functionality of DataGenerator

from scipy import stats

import math,random,copy

class Plane(object):
    """ Class representing the rectangle within which data points are stored
    """
    def __init__(self,xmin=-1.0,xmax=1.0,ymin=-1.0,ymax=1.0):
        """ Defining the rectangle
            ValueError if upper boundary is smaller than
            corresponding lower boundary
            
            Keyword arguments:
            xmin -- minimum boundary in x (default -1.0)
            xmax -- maximum boundary in x (default  1.0)
            ymin -- minimum boundary in y (default -1.0)
            ymax -- maximum boundary in y (default  1.0)
        """
        self.xmin = xmin
        self.xmax = xmax
        if xmax<xmin:
            raise ValueError("xmin > xmax")
        self.ymin = ymin
        self.ymax = ymax
        if ymax<ymin:
            raise ValueError("ymin > ymax")


class Generator(object):
    """ Class to handle the generation of the data points
    """
    def __init__(self,plane,xres=0.0,yres=0.0):
        """ Constructor
            
            Keyword arguments:
            plane -- instance of the Plane class
            xres  -- resolution of the points in x modelled by a Gaussian smearing (default: 0.0)
            yres  -- resolution of the points in y modelled by a Gaussian smearing (default: 0.0)
        """
        self.plane = plane
        self.xres = math.fabs(xres)
        self.yres = math.fabs(yres)
        self.nObj = 0
        self.nObjPoisson = False
        self.objFixed = False
        self.nBkg = 0
        self.nBkgPoisson = False
        self.objArray = []
        self.delimiter = " "
        self.pointFmt = "%1.6f"
        self.index = 0
        self.numberObjects = 0
        self.numberBackground = 0

    def setNumberOfObjects(self,nObj=1,nObjPoisson=False):
        """ Defining the number of objects from which points should be stored
            
            Keyword arguments:
            nObj        -- number of objects (default: 1)
            nObjPoisson -- if the number of objects should be drawn from a Poisson distribution with nObj as mean value (default: False)
        """
        self.nObj = nObj
        self.nObjPoisson = nObjPoisson

    def setObjectFixed(self,objFixed=True):
        """ Defining if the objects to be drawn are taken sequentially from the list of available objects (objFixed = True) or drawn randomly from this list (objFixed = False)
            
            Keyword arguments:
            objFixed -- (default: True)
        """
        self.objFixed = objFixed

    def setNumberOfBackgroundHits(self,nBkg,nBkgPoisson=False):
        """ Defining the number of noise hits
            
            Keyword arguments:
            nBkg        -- number of noise hits
            nBkgPoisson -- if the number of noise hits should be drawn from a Poisson distribution with nBkg as mean value (default: False)
        """
        self.nBkg = nBkg
        self.nBkgPoisson = nBkgPoisson
    
    def addObject(self,obj):
        """ Adding an object to the list of available objects
           
            Keyword arguments:
            obj -- object
        """
        self.objArray.append(obj)
        obj.setGenerator(self)

    def addObjectArray(self,objArray):
        """ Adding an array of objects to the list of available objects
            
            Keyword arguments:
            objArray -- array of objects
        """
        for obj in objArray:
            self.addObject(obj)

    def prepare(self):
        """ Preparing of the generator by setting the number of total objects and noise hits as well as setting the index of the points to zero
        """
        self.numberObjects = self.nObj
        if self.nObjPoisson:
            self.numberObjects = stats.poisson(self.nObj).rvs()
        self.numberBackground = self.nBkg
        if self.nBkgPoisson:
            self.numberBackground = stats.poisson(self.nBkg).rvs()
        self.index = 0
        self.writeString = self.pointFmt
        self.writeString+= self.delimiter+self.pointFmt
        # self.writeString = "%1.6f %1.6f"

    def writeToFile(self,fName):
        """ Storing of the obtained points in a file including a header containing information about the objects and the numbe of noise hits
            
            Keyword arguments:
            fName -- file name
        """
        try:
            # Open the file to write
            print "===================================="
            print "Writing to "+fName
            file = open(fName,'w')
            # Select and prepare the objects
            objList = []
            for i in range(self.numberObjects):
                sel = i%len(self.objArray)
                if not self.objFixed:
                    sel = random.choice(range(len(self.objArray)))
                obj = copy.deepcopy(self.objArray[sel])
                obj.prepare()
                objList.append(obj)
            # Writing header
            file.write("# Data file for Hough transforms %s\n"%(fName))
            file.write("#\n")
            file.write("# Boundary coordinates: [xmin,xmax,ymin,ymax] = %6.3f %6.3f %6.3f %6.3f\n"
                       %(self.plane.xmin,self.plane.xmax,self.plane.ymin,self.plane.ymax))
            file.write("# Resolution: [x,y] = %6.3f %6.3f\n"
                                  %(self.xres,self.yres))
            file.write("#\n")
            file.write("# Total number of objects:   %3d\n"%(self.numberObjects))
            file.write("#\n")
            file.write("# List of objects:\n")
            for obj in objList:
                file.write("# * %s\n"%(str(obj)))
            file.write("#\n")
            file.write("# Number of background hits: %3d\n"%(self.numberBackground))
            file.write("#\n")
            for obj in objList:
                print "* "+str(obj)
                points = obj.generate()
                for p in points:
                    if len(p) != 2:
                        print "::: Warning: point has not exactly two entries! Skip it!"
                        continue
                    px = p[0] + stats.norm(0.0,self.xres).rvs()
                    py = p[1] + stats.norm(0.0,self.yres).rvs()
                    print "%6.3f %6.3f"%(px,py)
                    file.write((self.writeString+" \n")%(px,py))
                    self.index += 1
            ufx = stats.uniform(self.plane.xmin,self.plane.xmax-self.plane.xmin)
            ufy = stats.uniform(self.plane.ymin,self.plane.ymax-self.plane.ymin)
            
            print "* Background"
            for _ in range(self.numberBackground):
                p = (ufx.rvs(),ufy.rvs())
                print "%6.3f %6.3f"%(p[0],p[1])
                file.write((self.writeString+" \n")%(p[0],p[1]))
                self.index += 1
            file.write("# End of file %s \n"%(fName))
        finally:
            file.close()
            print fName+" closed"
            print "===================================="

class Object(object):
    """ Generic object class
    """
    def __init__(self):
        self.type = self.__class__.__name__
        self.generator = None

    def __str__(self):
        return ""+self.type
    
    def setGenerator(self,generator):
        """ Setting the generator this object is part of
            Do not use this function by hand, it is done via the adding of the object to the generator
            
            Keyword arguments:
            generator -- Generator
        """
        self.generator = generator
    
    def prepare(self):
        """ Preparing of the object
            NotImplementedError
        """
        raise NotImplementedError("Basic object has nothing to prepare!")

    def generate(self):
        """ Generating a list of points associated to the object
            NotImplementedError
        """
        raise NotImplementedError("Basic object has nothing to generate!")

