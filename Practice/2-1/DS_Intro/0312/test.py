import pandas as pd
import matplotlib as plt

df = pd.read_csv('auto.csv')
df._get_numeric_data()
numeric = df.select_dtypes(include='number')
categorical = df.select_dtypes(exclude='number')


