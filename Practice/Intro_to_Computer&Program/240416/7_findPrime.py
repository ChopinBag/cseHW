primelist = []

for n in range(2,101):
    isPrime = True
    for i in range(2, n):
        if n%i == 0 :
            isPrime = False
            break
    if isPrime :
        primelist.append(n)

print(primelist)