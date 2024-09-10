from random import randint
userChoice = str(input('(가위, 바위 ,보) 중에서 하나를 선택하세요. : '))
comChoice = randint(1,4)
if comChoice == 1: comChoice = '가위'
elif comChoice == 2 : comChoice = '바위'
else : comChoice = '보'

if userChoice == '가위':
    if comChoice == '가위':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('비겼음!')
    elif comChoice == '바위':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('컴퓨터가 이겼음!')        
    else:
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('사용자가 이겼음!')
elif userChoice == '바위':
    if comChoice == '바위':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('비겼음!')
    elif comChoice == '가위':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('컴퓨터가 이겼음!')
    else:
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('사용자가 이겼음!')
else:
    if comChoice == '보':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('비겼음!')
    elif comChoice == '가위':
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('컴퓨터가 이겼음!')
    else:
        print('사용자 : ', userChoice, '컴퓨터 : ', comChoice)
        print('사용자가 이겼음!')