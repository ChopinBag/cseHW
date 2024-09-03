class Employee:
    empCount = 0
    def __init__(self, name, salary):
        Employee.empCount += 1
        self.name = name
        self.salary = salary
    
    def displayCount():
        print(Employee.empCount)

    def displayEmployee(self):
        print('직원의 이름 : %s, 직원의 월급 : %d' %(self.name, self.salary))

'''
코드를 활용한 예제입니다.
DrYum = Employee('Yum', 9999999)
Employee.displayCount()
DrYum.displayEmployee()
'''