from tkinter import *
from Interface.Board import *
from Interface.Levels import *

class GUI:
    def __init__(self):
        self.root = Tk()
        self.rows = 10
        self.cols = 10
        self.difficultyBtn = SelectDifficulty(self.root, self.rows, self.cols)
        self.difficultyBtn.grid(row = 0, column = 0)
        self.boardFrame = Board(self.root)
        self.boardFrame.grid(row=1, column=1, columnspan=10)
        
    
    def run(self):
        self.root.mainloop()