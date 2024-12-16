import pandas as pd 
df = pd.read_csv('countries.csv')
# print(df['country'])
# print(df[['area','population']])
# df.loc[1,'country']

df['density'] = df['population'] / df['area']
print(df)

