import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("score_data.csv")
plt.rc("font", family = "gulim")
subdf1 = df[df.grade == '1학년']
subdf2 = df[df.grade == '2학년']

plt.figure(figsize=(8,6))
plt.scatter(subdf1['kor'], subdf1['mat'],color='blue',label='1학년', alpha=0.7)
plt.scatter(subdf2['kor'], subdf2['mat'],color='orange',label='2학년', alpha=0.7)

plt.title("학년별 국어 수학 점수 분포")
plt.xlabel("국어 점수")
plt.ylabel("수학 점수")
plt.legend()  # 범례 추가
plt.grid(True)  # 격자 추가

plt.show()  