#%%
import numpy as np
mid_scores = np.array([10,20,30])
fin_scores = np.array([40,50,60])   
total = mid_scores+fin_scores
print(total)
#%%

x = np.arange(-10,10,1)
y = x**2
import matplotlib.pyplot as plt
plt.plot(x,y)
plt.show()
#%%

x = np.linspace(0, 2*np.pi)
y1 = np.sin(x)
y2 = np.cos(x)
import matplotlib.pyplot as plt
plt.plot(x,y1, label='sin')
plt.plot(x,y2, label='cos')
plt.legend()

plt.show()
#%%
import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(-3, 5)
y1 = 0.5 * x **3 +- 4*x + 1
y2 = x**2 - 2
plt.plot(x, y1)
plt.plot(x,y2)
# %%
