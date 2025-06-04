for a in range(1, 101, 1):
    for b in range(a, 101, 1):
        for c in range(b, 101, 1):
            if a**2 + b**2 == c**2:
                print(a,b,c)