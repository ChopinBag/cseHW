sen = input('문자열을 입력하시오: ')

alpha=0
digit=0
space=0

if len(sen)>0:
    for i in sen:
        if i.isalpha():
            digit +=1
        if i.isspace():
            space+=1
        if i.isalpha():
            alpha+=1

print('알파벳 문자의 개수 = %d'%(alpha))
print('숫자 문자의 개수 = %d'%(digit))
print('공백문자의 개수 = %d'%(space))