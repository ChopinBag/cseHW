sen = input('문자열을 입력하시오: ')
result = 0
senL = sen.lower()
for i in range(len(senL)):
    if senL[i] == 'o':
        result += 1
print(result)