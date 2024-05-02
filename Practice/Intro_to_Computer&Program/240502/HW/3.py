def getGCD(a, b):
    r = a%b
    while r != 0:
        a = b
        b = r
        r = a%r
    return b

firstNum = int(input('첫 번째 정수: '))
SecondNum = int(input('두 번째 정수: '))
print(getGCD(firstNum, SecondNum))