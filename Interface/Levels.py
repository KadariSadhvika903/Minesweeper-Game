from tkinter import *
from tkinter import ttk

def OnClick(N, M, x, y):
    N = x
    M = y

def Clicker(root, rows, cols):
    pop = Toplevel(root)
    pop.title("Dificulty Level")
    pop_label = Label(pop, text = "The difficulty level you would like to play?")
    pop_label.grid(row =1, column = 1, columnspan =3, pady = 10)
    g1 = ttk.Radiobutton(pop, text="Beginner", value = 1, command=lambda: OnClick(rows, cols, 10, 10))
    g2 = ttk.Radiobutton(pop, text="Intermediate", value = 2, command=lambda: OnClick(rows, cols, 16, 16))
    g3 = ttk.Radiobutton(pop, text="Advanced",value = 3, command=lambda: OnClick(rows, cols, 16 , 30) )
    send = ttk.Button(pop, text='Ok', default='active', command = lambda: pop.destroy())
    g1.grid(column=1, row=2, sticky=W, padx=20)
    g2.grid(column=1, row=3, sticky=W, padx=20)
    g3.grid(column=1, row=4, sticky=W, padx=20)
    send.grid(column=2, row=5)



class SelectDifficulty(Button):
    def __init__(self, master, rows, cols, **kw):
        super().__init__(master=master, text="Click Me!", command=lambda: Clicker(master, rows, cols), **kw)

