import random
print('1부터 100 사이의 숫자를 맞추시오')
aim = random.randint(1,101)
attempt = 1

while attempt < 10:
    guess = int(input('숫자를 입력하시오: '))
    attempt+=1
    if guess > aim:
        print('높음!')
    elif guess < aim:
        print('낮음!')
    else: 
        break

if attempt<10:
    print('축하합니다. 시도횟수= %d' %(attempt))
else:
    print('그만!')