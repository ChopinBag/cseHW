from tkinter import *
from tkinter import ttk

window = Tk()

colors = ['green', 'red', 'orange']
r = 0

style = ttk.Style()

for color in colors:
    # 각 버튼에 대해 고유한 스타일을 생성
    style_name = f"{color}.TButton"
    style.configure(style_name, highlightbackground=color)
    
    Label(window, text=color, relief=RIDGE, width=15).grid(row=r, column=0)
    ttk.Button(window, text=color, style=style_name, width=15).grid(row=r, column=1)
    r += 1

window.mainloop()