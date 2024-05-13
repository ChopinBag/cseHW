dogNames = []
while True:
    dogNames.append(str(input('강아지의 이름을 입력하시오(종료시에는 엔터키) ')))
    if dogNames[-1] == '':
        dogNames.pop()
        break
for i in range(len(dogNames)-1):
    print(dogNames[i], end=', ')
print(dogNames[-1])