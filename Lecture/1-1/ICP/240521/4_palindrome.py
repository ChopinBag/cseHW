sen = input('문자열을 입력하시오: ')
sen = list(sen.replace(" ",""))
senRev = sen[::-1]

def isPal():
    for i in range(len(sen)):
        if sen[i] != senRev[i]:
            return False
        else:
            return True