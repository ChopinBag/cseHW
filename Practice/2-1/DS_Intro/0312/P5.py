import pandas as pd

df = pd.read_csv('assets/titanic.csv')

df['isAlone'] = ((df['SibSp'] == 0) & (df['Parch'] == 0)).map({True: 1, False: 0})
df['Alone'] = ((df['SibSp'] == 0) & (df['Parch'] == 0)).map({True: 'yes', False: 'no'})
df['class'] = (df['Pclass']).map({3 : 'third', 2 : 'second', 1 : 'first'})
df['isAdultMale'] = ((df['Sex'] == 'male') & (df['Age'] > 18)).map({True: 1, False: 0})
