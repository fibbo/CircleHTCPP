from DataGenerator.Basic import Plane,Generator
from DataGenerator.Shapes import Circle

NUMBER_OF_CIRCLES = 1
CIRCLE_HITS = 30
POISSON_BACKGROUND_HITS = False
NUMBER_OF_BACKGROUND_HITS = 400


p = Plane(xmin=-.5,xmax=.5,ymin=-.5,ymax=.5)
g = Generator(p)
g.setNumberOfBackgroundHits(NUMBER_OF_BACKGROUND_HITS,POISSON_BACKGROUND_HITS)
for _ in range(NUMBER_OF_CIRCLES):
  circle = Circle(CIRCLE_HITS, False, 0.08, 0.08,centerFixed=True,xCent=0.,yCent=0.)
  g.addObject(circle)
g.setNumberOfObjects(NUMBER_OF_CIRCLES)
g.prepare()
path = "CircleHT/data/"
if NUMBER_OF_CIRCLES == 1:
  filename = "%s_circle_" % NUMBER_OF_CIRCLES
else:
  filename = "%s_circles_" % NUMBER_OF_CIRCLES
bg = "_bg"
hits = "_hits_"
extension = ".txt"
filename = path+filename+str(NUMBER_OF_BACKGROUND_HITS)+bg+extension

filename = '../data/1circle400bg.txt'
g.writeToFile(filename)
#g.prepare()
#g.writeToFile("exampleB.txt")
