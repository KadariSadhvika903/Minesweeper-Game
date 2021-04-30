from tkinter import*
from tkinter import ttk
# from tkinter import messagebox

root = Tk()
# root.geometry("300x300")

def Clicker():
    global pop
    pop = Toplevel(root)
    pop.title("Dificulty Level")
    # pop.geometry("350x150")
    # pop.config(bg = "green")
    pop_label = Label(pop, text = "The difficulty level you would like to play?")
    pop_label.grid(row =1, column = 1, columnspan =3, pady = 10)
    g1 = ttk.Radiobutton(pop, text="Beginner", value = 1, command=lambda: OnClick(10,10))
    g2 = ttk.Radiobutton(pop, text="Intermediate", value = 2, command=lambda: OnClick(16,16))
    g3 = ttk.Radiobutton(pop, text="Advanced",value = 3, command=lambda: OnClick(16,30) )
    send = ttk.Button(pop, text='Ok', default='active', command = lambda: pop.destroy())
    # global pic
    # pic = PhotoImage(file = "C:\Users\Kadari Sadhvika\Desktop\Project Minesweeper")
    g1.grid(column=1, row=2, sticky=W, padx=20)
    g2.grid(column=1, row=3, sticky=W, padx=20)
    g3.grid(column=1, row=4, sticky=W, padx=20)
    send.grid(column=2, row=5)


my_button = Button(root, text = "Click Me!", command = Clicker)
my_button.grid(row = 1, column = 2, columnspan = 3, pady = 50)

N = 0
M = 0

def OnClick(x,y):
    N = x
    M = y
    
# g1 = ttk.Radiobutton(root, text="Beginner", command=lambda: OnClick(10,10))
# g2 = ttk.Radiobutton(root, text="Intermediate", command=lambda: OnClick(16,16))
# g3 = ttk.Radiobutton(root, text="Advanced",command=lambda: OnClick(16,30) )
# send = ttk.Button(root, text='Ok', default='active')


# g1.grid(column=1, row=1, sticky=W, padx=20)
# g2.grid(column=1, row=2, sticky=W, padx=20)
# g3.grid(column=1, row=3, sticky=W, padx=20)
# send.grid(column=2, row=4)

root.mainloop()

