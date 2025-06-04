from tkinter import *
import time
window2 = Tk()
canvas = Canvas(window2, width=300, height=200)
canvas.pack()
txt = canvas.create_text(100, 100, text="싱스트리트")
for i in range(100):
    canvas.move(txt, 3, 0)
    window2.update()
    time.sleep(0.05)

window2.mainloop()
    