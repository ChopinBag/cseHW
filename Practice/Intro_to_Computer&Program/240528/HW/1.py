class Recatangle:
    def __init__(self, x, y, width, height):
        self.x = float(x)
        self.y = float(y)
        self.width = float(width)
        self.height = float(height)
    
    def calcArea(self):
        return self.width * self.height
    
    def getInfo(self):
        location = (self.x, self.y)
        print('box : ', end='')
        print(location, self.width, self.height, sep=',')

Rec1 = Recatangle(0, 0, 100, 100)
Rec2 = Recatangle(10, 10, 200, 200)
Rec1.getInfo()
Rec2.getInfo()