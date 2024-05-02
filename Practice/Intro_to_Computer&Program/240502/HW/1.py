def calc(x1,x2,y1,y2):
    incl = (y2-y1)/(x2-x1)
    y_inter = y2 - incl*x2
    return incl, y_inter
print('기울기 = %f y절편 = %f' % (calc(10, 20, 10, 20)))