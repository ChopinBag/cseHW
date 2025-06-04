triangles = []
for a in range(1, 31, 1):
    for b in range(a, 31, 1):
        for c in range(b, 31, 1):
            if a**2 + b**2 == c**2:
                triangles.append([a,b,c])

print(triangles)