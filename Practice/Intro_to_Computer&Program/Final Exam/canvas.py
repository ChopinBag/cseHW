from tkinter import *
import time
window = Tk()
canvas = Canvas(window, width=300, height=200)
canvas.pack()
txt1 = canvas.create_text(100, 100, text="싱 스트리트")
for i in range(100):
    canvas.move(txt1, 3, 0)
    window.update()
    time.sleep(0.05)
window.mainloop()