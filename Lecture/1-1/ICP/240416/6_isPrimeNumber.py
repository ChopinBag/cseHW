n = int(input('수를 입력하세요 : '))
isPrime = True
for i in range(2, n):
    if n%i == 0 :
        isPrime = False
        break
print(n, 'is prime ?', isPrime)