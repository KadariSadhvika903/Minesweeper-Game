from tkinter import*

root = Tk()
root.title("Minesweeper Board")

# def 

for i in range(10):
    for j in range(10):
        Button(root, padx = 15, pady = 5).grid(row = i, column = j)
        
root.mainloop()