num = int(input('세자리 정수를 입력하세요 :'))
digitList=[]
for i in range(len(str(num))):
    digitList.append(int(str(num)[i]))
print('백의 자리 : ', digitList[0])
print('십의 자리 : ', digitList[1])
print('일의 자리 : ', digitList[2])
