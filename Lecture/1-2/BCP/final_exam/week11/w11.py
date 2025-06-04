import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("gdp_data.csv")
plt.plot(df.year, df.gdp,"--ro")

plt.title("GDP")
plt.xlabel("year")
plt.ylabel("gdp")
plt.ylim([0,7000])
plt.legend(['gdp'])
plt.show()

#%%
import matplotlib.pyplot as plt
import pandas as pd

plt.bar(range(len(df.year)) , df.gdp)
plt.xticks(range(len(df.year)) , df.year)
plt.show()

#%%
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

df = pd.read_csv("gdp_data.csv")
sns.barplot(x=df.year, y=df.gdp)

# %%
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("iris.csv")
plt.scatter(df.PetalLength, df.PetalWidth, c=df.Species)
# %%
import matplotlib.pyplot as plt
import pandas as pd
df = pd.read_csv("countries.csv")
plt.pie(df.area, labels=df.country, autopct="%.2f%%")
# %%
df = pd.read_csv("iris.csv")
plt.hist(df.PetalWidth)
# %%
df = pd.read_csv("iris.csv")
plt.hist(df.PetalWidth, 10, histtype='bar')
plt.hist(df.SepalWidth, 10, histtype='bar', alpha=0.3)

plt.legend(['PetalWidth','SepalWidth'])
# %%
