import math
pi = math.pi
def sVolume(n):
    return (n**3)*4/3*pi
num=float(input('구의 반지름을 입력하시오: '))
print(sVolume(num))