sentence = input('번역할 문장을 입력하시오: ')
short = {'B4':'Before', 'TX':'Thanks', 'BBL':'Be Back Later', 'BNCU':'Be Seeing You', 'HAND':'Have A Nice Day'}
result = ""
senList = sentence.split()
for i in senList:
    if i in short:
        result += short[i] + ""
    else:
        result += senList[i]
