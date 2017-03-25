# Circle object for Hough Transforms

from DataGenerator.Basic import Object

from scipy import stats

import math

class Circle(Object):
    """ Class representing circles
    """
    def __init__(self,nPoints=10,nPointsPoisson=False,r=1.0,\
                 rmax=-1.0,inPlane=True,centerFixed=False,xCent=0.0,yCent=0.0):
        """ Defining the circle
            
            Keyword arguments:
            nPoints        -- number of points on the total circle (not just the section in the rectanle; default: 10)
            nPointsPoisson -- indicates if the number of points is drawn from a poisson distribution with mean nPoints (default: False)
            r              -- Radius of the circle (default: 1.0)
            rmax           -- if rmax > r, radius is uniformly distributed between r and rmax (default: -1.0)
            centerFixed    -- indicates if the circle center is fixed (default: False)
            xCent          -- x-coordinate of the center (only relevant if centerFixed = true; default: 0.0)
            yCent          -- y-coordinate of the center (only relevant if centerFixed = true; default: 0.0)
        """
        super(Circle,self).__init__()
        self.inPlane = inPlane
        self.r    = r
        self.rmin = math.fabs(r)
        self.rmax = rmax
        self.nPoints = nPoints
        self.nPointsPoisson = nPointsPoisson
        self.centerFixed = centerFixed
        self.xCent = xCent
        self.yCent = yCent
        self.numberPoints = 0
        self.radius = 0.0
        self.xcenter = 0.0
        self.ycenter = 0.0
        self.numberPointsSelected = 0

    def __str__(self):
        s = ""+self.type+":"
        s+= " %d Points "%(self.numberPoints)
        s+= " Radius: %1.3f"%(self.radius)
        s+= " Center: %1.3f %1.3f" % (self.xcenter,self.ycenter)
        return s

    def setGenerator(self,generator):
        """ Setting the generator this object is part of
            Do not use this function by hand, it is done via the adding of the object to the generator
            
            Keyword arguments:
            generator -- Generator
        """
        super(Circle,self).setGenerator(generator)
        if self.inPlane:
            pass
# ToDo: change the circle to fit in the rectangle

    def prepare(self):
        """ Preparing by setting the radius of the circle, the number of points and the position of the center
        """
        self.radius = self.r
        if self.rmax > self.r:
            self.radius = stats.uniform(self.r,self.rmax-self.r).rvs()
        self.numberPoints = self.nPoints
        if self.nPointsPoisson:
            self.numberPoints = stats.poisson(self.nPoints).rvs()
        self.xcenter,self.ycenter = self.xCent,self.yCent
        if not self.centerFixed:
            self.xcenter = stats.uniform(self.generator.plane.xmin,self.generator.plane.xmax-self.generator.plane.xmin).rvs()
            self.ycenter = stats.uniform(self.generator.plane.ymin,self.generator.plane.ymax-self.generator.plane.ymin).rvs()

    def generate(self):
        """ Generate the list of random points on the circle
            
            Return values:
            list of 2-entry tuples representing the points
        """
        pointList = []
        for _ in range(self.numberPoints):
            phi = stats.uniform(0.0,2*math.pi).rvs()
            x,y = self.xcenter+self.radius*math.cos(phi),self.ycenter+self.radius*math.sin(phi)
            if x>self.generator.plane.xmax or x<self.generator.plane.xmin or y>self.generator.plane.ymax or y<self.generator.plane.ymin:
                continue
            pointList.append((x,y))
        return pointList
