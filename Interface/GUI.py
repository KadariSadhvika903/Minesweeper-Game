from tkinter import *
from Interface.Board import *

class GUI:
    def __init__(self):
        self.root = Tk()
        self.boardFrame = Board(self.root)
        self.boardFrame.grid(row=0, column=0)
    
    def run(self):
        self.root.mainloop()