"""선형회귀 - 연비예측"""
#Q1. "car.csv" 파일 읽어서 df에 저장하기

df.info()
#Q2. 표시연비와 co2배출량 으로 산포도 그리기

#3.1 표시연비와, Co2배출량의 차원을 바꾸기
x = df['표시연비'].values.reshape(-1, 1)
print('표시연비', x[:10])

y = df['co2배출량'].values.reshape(-1, 1)
print('co2 배출량', y[:10])

#3.2 학습데이터와 테스트데이터로 분리  train_test_split
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
print('학습데이터의 샘플 수:', len(x_train))
print('평가데이터의 샘플 수:', len(x_test))

#3.3 학습모델 선택
from sklearn.linear_model import LinearRegression 
model  = LinearRegression()

#3.4 학습데이터로 학습  fit
model.fit(x_train, y_train) 

#3.5 예측하기  predict
y_pred = model.predict(x_test)

#3.6 학습데이터의 성능 평가 score
model .score(x_train, y_train)
#Q3.7 테스트 데이터의 성능 평가 score

#%%
"""
## 데이터 분류 - 붓꽃 데이터 분류하기 """
#Q1. "iris.csv" 파일 읽어서 df에 저장하기

#Q2. PetalLength 와 PetalWidth로 산포도 그리기

#
x = df.iloc[:,1:5]
y = df.Species

#3.1 train_test_split 함수를 이용하여 train set과 test set으로 나누기
from sklearn.model_selection import train_test_split

x_train, x_test, y_train, y_test = train_test_split(x,
                                                    y,
                                                    test_size=0.2,
                                                    random_state=7)

print(f'x_train 개수: {len(x_train)}, x_test 개수: {len(x_test)}')
#3.2 학습모델 선택 
from sklearn.neighbors import KNeighborsClassifier 
neigh = KNeighborsClassifier(n_neighbors=6)
#3.3 학습데이터로 학습  fit
neigh.fit(x_train, y_train) 
#3.4 테스트 세트로 예측
y_pred = neigh.predict(x_test)

#3.5 정확도 평가
from sklearn.metrics import accuracy_score
accuracy = accuracy_score(y_test, y_pred)
for i in range(10):
  print(f'실제:{y_train[i]} 예측:{y_pred[i]}')
  
#3.4 성능 평가 score
print('학습데이터:', neigh.score(x_train, y_train)) 
print('평가데이터:', neigh.score(x_test, y_test))
