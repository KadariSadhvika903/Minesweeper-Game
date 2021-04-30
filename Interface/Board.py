from tkinter import *

class Board(Frame):
    def __init__(self, parent):
        super().__init__()

        for i in range(10):
            for j in range(10):
                Button(self, padx = 15, pady = 5).grid(row = i, column = j)

