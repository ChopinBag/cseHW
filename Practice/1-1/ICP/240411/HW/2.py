x1 = float(input('첫 번째 점의 x 좌표:'))
y1 = float(input('첫 번째 점의 y 좌표:'))
x2 = float(input('두 번째 점의 x 좌표:'))
y2 = float(input('두 번째 점의 y 좌표:'))


if x1 == x2:
    print('직선의 방정식은 ', x1)

else:
    slope = (y2-y1)/(x2-x1)
    print('직선의 방정식은 ', slope, 'x +', y1-slope*x1)
