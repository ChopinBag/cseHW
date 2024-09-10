import math
pi = math.pi

def calcArea(r):
    return (r**2)*pi

def calCircum(r):
    return 2*pi*r

radius = int(input('원의 반지름을 입력하시오: '))
print('원의 면적: ',calcArea(radius))
print('원의 둘레: ', calCircum(radius))