numbers = {}
tempKey = 'temp'
while tempKey != '':
    tempKey = input('(입력모드)이름을 입력하시오: ')
    if tempKey == '':
        break
    tempValue = input('전화번호를 입력하시오: ')
    numbers[tempKey] = tempValue
while True:
    search = input('(검색모드)이름을 입력하시오: ')
    if search in numbers:
        print(numbers[search])
    else:
        print('해당 사용자는 존재하지 않습니다.')