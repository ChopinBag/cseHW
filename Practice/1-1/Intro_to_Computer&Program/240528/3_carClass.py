class car:
    def __init__(self, color, curSpeed, curGear):
        self.color, self.curSpeed, self.curGear = color, curSpeed, curGear
    
    def accel(self, velocity):
        self.curSpeed += velocity
    
    def brake(self, velocity):
        self.curSpeed -= velocity
    
    def changeGear(self, amount):
        self.curGear += amount

    def __str__(self):
        return '(%d, %d, %s)' %(self.curSpeed, self.curGear, self.color)

Benz = car('white', 100, 3)
print(Benz.__str__())
