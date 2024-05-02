def getGrade(score):
    if score>=90:
        return 'A'
    elif score >= 80:
        return 'B'
    elif score >= 70:
        return 'C'
    elif score >= 60:
        return'D'
    else :
        return 'F'
    
userGrade = int(input('점수를 입력하세요: '))
print('성적은 %s 입니다.' %(getGrade(userGrade)))