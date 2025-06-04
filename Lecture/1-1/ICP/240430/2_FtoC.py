fahrenheit = float(input('화씨온도를 입력하시오: '))
def FtoC(fahrenheit):
    return ((fahrenheit - 32)*5/9)
print(FtoC(fahrenheit))