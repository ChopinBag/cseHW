from tkinter import *
from tkinter.colorchooser import askcolor

class App1():
    def __init__(self):
        window1 = Tk()
        self.label = Label(window1, text="Hello World!")
        self.label.pack()
        self.b1 = Button(window1, text="이것은 버튼", command=self.callback)
        self.b2 = Button(window1, text="이것도 버튼", command = self.hello)
        self.b2["text"]="버튼인데용"
        self.b1.pack(side=LEFT, padx=10,pady=5)
        self.b2.pack(side=LEFT, padx=10, pady=5)
        window1.mainloop()

    def callback(self):
        self.b1["text"] = "클릭된 버튼!"
    def hello(self):
        print('hello!')

import tkinter.font as font
class App2() :
    def __init__(self):
        window2 = Tk()
        self.font1 = font.Font(family="Helvetica", size=12)
        self.b1 = Button(window2, text="one", font=self.font1, command=self.bigFont)
        self.b2 = Button(window2, text="two")
        self.l1 = Label(window2, text="레이레이블", bg="white", fg="blue")
        self.b1.grid(row=0,column=0)
        self.b2.grid(row=1,column=0)
        self.l1.grid(row=0,column=1)
        self.l1["fg"]="black"
        window2.mainloop()

    def bigFont(self):
        size = self.font1['size']
        self.font1.configure(size= size+2)

class App3() :
    def __init__(self):
        window3 = Tk()
        self.l1 = Label(window3, text="라이브루",bg="blue", fg="black").pack(fill=X)
        self.l2 = Label(window3, text="라이브루우",bg="red", fg="white").pack(fill=X)
        window3.mainloop()

class App4() :
    def __init__(self):
        window4 = Tk()
        self.l1 = Label(window4, text="라이브루",bg="blue", fg="black").place(x=0, y=0)
        self.l2 = Label(window4, text="라이브루우",bg="red", fg="white")
        self.l2.place(x=0, y=30)
        self.l2["bg"] = askcolor()[1]
        window4.mainloop()

class App5() :
    def __init__(self):
        window5=Tk()
        colors=['green','blue','red','orange','white','yellow','blue']
        r=0
        for c in colors:
            Label(window5, text=c, relief=RIDGE, width=15).grid(row=r, column=0)
            Label(window5, bg=c, width=10).grid(row=r, column=1)
            r+=1
        window5.mainloop()

class Timer() :
    def __init__(self):
        self.timerWindow = Tk()
        self.timer = 0
        self.running = False
        self.timeText = Label(self.timerWindow, text="0", font=("Helvetica", 80))
        self.timeText.pack()

        startButton = Button(self.timerWindow, text="시작", bg="yellow", command=self.start)
        startButton.pack(fill=BOTH)

        stopbutton = Button(self.timerWindow, text="중지", bg="yellow", command=self.stop)
        stopbutton.pack(fill=BOTH)
        self.timerWindow.mainloop()

    
    def startTimer(self):
        if self.running :
            self.timer +=1
            self.timeText.configure(text=str(self.timer))
        self.timerWindow.after(1000, self.startTimer)

    def start(self):
        if not self.running:
            self.running = True
            self.startTimer()

    def stop(self):
        self.running = False
