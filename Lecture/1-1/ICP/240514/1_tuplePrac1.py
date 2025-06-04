import math as m
radius = int(input('원의 반지름을 입력하시오: '))
circleInfo = (m.pi * (radius**2), m.pi * 2 * radius)

print('원의 넓이는 %f이고 원의 둘레는 %f이다.' %(circleInfo[0], circleInfo[1]))