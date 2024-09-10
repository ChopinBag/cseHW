sentence = str(input('문자열을 입력하세요.'))
if len(sentence)%2 == 0 :
    print('중앙글자는', sentence[int(len(sentence)/2-1)], sentence[int(len(sentence)/2)])
else:
    print('중앙글자는', sentence[int((len(sentence)-1)/2)])