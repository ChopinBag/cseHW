words = {'one':'하나', 'two':'둘', 'three':'셋'}
asked = input('단어를 입력하시오: ')
if asked in words:
    print(words.get(asked))
else:
    print('없음')