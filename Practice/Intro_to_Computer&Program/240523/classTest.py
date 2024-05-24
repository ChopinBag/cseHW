

class student:
    def __init__(self, initSkill=0, initBody=0) :
        self.skill, self.body = initSkill, initBody
    def study(self):
        self.skill += 1
    def exercise(self):
        self.body += 1
    def info(self):
        return self.skill, self.body

sw = student(10, 20)
for i in range(6):
    sw.exercise()
for i in range(3):
    sw.study()
print(sw.info())