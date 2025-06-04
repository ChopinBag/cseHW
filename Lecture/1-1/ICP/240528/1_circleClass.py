import math as m
class circle:
    def __init__(self, radius=1):
        self.__radius = int(radius)
        self.__Area = (self.__radius**2)*m.pi
        self.__Circum = 2*self.__radius*m.pi

    def setRad(self, radius):
        self.__radius = radius
    
    def getRad(self):
        return self.__radius
    def getArea(self):
        return self.__Area
    def getCircum(self):
        return self.__Circum
    
c1 = circle(input('원의 반지름 : '))
print('원의 반지름 : ', c1.getRad())
print('원의 넓이 : ', c1.getArea())
print('원의 둘레 : ', c1.getCircum())
