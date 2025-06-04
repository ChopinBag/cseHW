import math as m
## 내장함수
value1 = abs(-3)
value2 = round(3.14159)
value3 = max(1, 2, 3)
value4 = min(1, 2, 3)

## math 모듈
value5 = m.sqrt(16)
value6 = m.sin(m.pi/2)

## 템플릿 문자열
'{0} Python!'.format('Hello') ## placeholder
'i like {0} and {1}'.format('python', 'java')
print('-3의 절댓갑은 {0}, 3.14의 반올림값은 {1}, 1,2,3 중 최댓값은 {2}, 최솟값은 {3}'.format(value1, value2, value3, value4))

##정수 포매팅
for i in range(2, 15, 2):
    print('{0:3d} {1:4d} {2:5d}'.format(i, i*i, i*i*i)) 
    ##해당 자리의 글자수와 자료형 설정 가능 
    ##{0 : 3.5f} 와 같이 설정하면 0번에 정수부 3자리 소수부 5자리로 설정
    ##{:,} 과 같이 쉼표 넣으면 1000단위 쉼표 출력

print('위도 : {lat}, 경도 : {long}'.format(lat='35.1N', long='129.07E'))

#원의 부피, 반지름, 둘레 : 4/3 * pi *(r**3), pi*(r**2), 2*pi*r

import random
def genPass():
    alpha = "qwertyuiopasdfghjklzxcvbnm1234567890"
    password = ""
    for i in range(6):
        index = random.randrange(len(alpha))
        password += alpha[index]
    return password
print(genPass())

class student:
    def __init__(self, name=None, age=0):
        self.__name=name
        self.__age=age

    def getName(self):
        return self.__name
    def getAge(self):
        return self.__age

obj = student('tom', 23)
print(obj.getName())