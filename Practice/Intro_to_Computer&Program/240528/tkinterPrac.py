from tkinter import *

class App:
    def __init__(self):
        window = Tk()
        helloButton = Button(window, text='hello', command=self.hello, fg='red')
        helloButton.pack(side=LEFT)
        quitButton = Button(window, text='quit', command=self.quit, fg='black')
        quitButton.pack(side=LEFT)
        window.mainloop()
    
    def hello(self):
        print('helloooooo')

    def quit(self):
        print('카무이!')

App()