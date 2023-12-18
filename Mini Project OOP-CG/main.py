from tkinter import *
from cell import Cell
import settings
import conf

#Favourable Settings
mainvariable = Tk()
mainvariable.configure(bg='White')
mainvariable.geometry(f'{settings.width}x{settings.height}')
mainvariable.title("Minesweeper wiht Ninad and Pranay")
mainvariable.resizable(True, True)

top_bar = Frame(
    mainvariable,
    bg='Yellow',
    width=conf.wpcv(75),
    height=conf.hpcv(25),
    )
top_bar.place(x=conf.wpcv(25), y=conf.hpcv(0))

lhs_bar = Frame(
    mainvariable,
    bg='Cyan',
    width=conf.wpcv(25),
    height=conf.hpcv(100),
)
lhs_bar.place(x=conf.wpcv(0), y=conf.hpcv(0))

game_box= Frame(
    mainvariable,
    bg='White',
    width=conf.wpcv(75),
    height=conf.hpcv(75),
)
game_box.place(x=conf.wpcv(25), y=conf.hpcv(25))

game_title = Label(
    top_bar,
    bg='Black',
    fg='White',
    text='MINESWEEPER',
    font=('', 48)
)
game_title.place(
    x=conf.wpcv(0),
    y=conf.hpcv(2)
)

for x in range(settings.gridsize):
    for y in range(settings.gridsize):
        cell = Cell(x, y)
        cell.create_button_object(game_box)
        cell.cell_button_object.grid(
            column=x, row=y
            )  

Cell.random_mines()

Cell.create_cellcount_label(lhs_bar)
Cell.cellcount_label_object.place(
    x=80, y=320
)
 
#Running Program
mainvariable.mainloop()