def toNumber(l):

    if l in ['a', 'b', 'c']:
        return 2
    elif l in ['d','e','f']:
        return 3
    elif l in ['g','h','i']:
        return 4
    elif l in ['j','k','l']:
        return 5
    elif l in ['m','n','o']:
        return 6
    elif l in ['p','q','r','s']:
        return 7
    elif l in ['t','u','v']:
        return 8
    else:
        return 9
    
sen = input('문자열을 입력하시오: ')
sen = sen.lower()
result = ""
for i in range(len(sen)):
    result += str(toNumber(sen[i]))
print(result)