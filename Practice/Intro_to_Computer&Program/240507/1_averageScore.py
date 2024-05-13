grade = []
goodGrade = 0
for i in range(5):
    grade.append(int(input('성적을 입력하시오: ')))
    if grade[i] >= 80:
        goodGrade += 1
print('성적의 평균은 %f입니다.' %(sum(grade)/5))
print('80점 이상인 성적을 받은 학생은 %d명입니다.' %(goodGrade))