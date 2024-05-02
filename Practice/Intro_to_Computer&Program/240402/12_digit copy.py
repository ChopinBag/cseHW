num = int(input('세자리 정수를 입력하세요 :'))
digitList=[]
for i in range(len(str(num))):
    digitList.append(int(str(num)[i]))
print(digitList[2])
print(digitList[1])
print(digitList[0])
