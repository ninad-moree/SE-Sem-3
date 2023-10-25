from tkinter import Button, Label
import random
import settings
import conf
import ctypes
import sys

class Cell:
    allinfo = []
    cellcount_label_object = None
    cellcount = settings.cellcount

    def __init__(self, x, y, default_value=False):
        self.default_value = default_value
        self.is_opened = False
        self.is_mine_hopeful = False
        self.cell_button_object = None
        self.x = x
        self.y = y
        Cell.allinfo.append(self)

    def create_button_object(self, location):
        button = Button(
            location,
            width=(int((conf.wpcv(5)) / (settings.gridsize))),
            height=(int((conf.hpcv(4)) / (settings.gridsize))),
        )
        button.bind('<Button-1>', self.lmb_clicked_event)
        button.bind('<Button-3>', self.rmb_clicked_event)
        self.cell_button_object = button

    @staticmethod
    def random_mines():
        picked_cells = random.sample(
            Cell.allinfo, settings.minecount
        )
        for picked_cell in picked_cells:
            picked_cell.default_value = True

    @property
    def adjacent_cells(self):
        cells = [
            self.get_cells(self.x-1, self.y-1),
            self.get_cells(self.x  , self.y-1),
            self.get_cells(self.x+1, self.y-1),
            self.get_cells(self.x-1, self.y  ),
            self.get_cells(self.x+1, self.y  ),
            self.get_cells(self.x-1, self.y+1),
            self.get_cells(self.x  , self.y+1),
            self.get_cells(self.x+1, self.y+1),
        ]
        cells = [cell for cell in cells if cell is not None]
        return cells

    @property
    def minecount_adjacent_cells(self):
        count = 0
        for cells in self.adjacent_cells:
            if cells.default_value:
                count += 1
        return count

    def get_cells(self, x, y):
        for cell in Cell.allinfo:
            if cell.x == x and cell.y == y:
                return cell

    def show_mine(self):
        self.cell_button_object.configure(bg='Red',)
        ctypes.windll.user32.MessageBoxW(0, 'You were blown by a Mine.', 'Game Over', 0)
        sys.exit()

    def show_cell(self):
        if not self.is_opened:
            Cell.cellcount -= 1
            self.cell_button_object.configure(
                text=self.minecount_adjacent_cells
            )
            if Cell.cellcount_label_object:
                Cell.cellcount_label_object.configure(
                    text=f"Cells Left:{Cell.cellcount}"
                )
            self.cell_button_object.configure(
                bg='SystemButtonFace'
            )
        self.is_opened = True

    @staticmethod
    def create_cellcount_label(location):
        lbl = Label(
            location,
            bg='White',
            fg='Black',
            text=f"Cells Left:{settings.cellcount}",
            font=("", 30)
        )
        Cell.cellcount_label_object = lbl

    def lmb_clicked_event(self, event):
        if self.default_value:
            self.show_mine()
        else:
            if self.minecount_adjacent_cells == 0:
                for cell_object in self.adjacent_cells:
                    cell_object.show_cell()
            self.show_cell()
            if Cell.cellcount == settings.minecount:
                ctypes.windll.user32.MessageBoxW(0, 'Congratulations!! You won the game.', 'Victory!', 0)
                sys.exit()
        self.cell_button_object.unbind('<Button-1>')
        self.cell_button_object.unbind('<Button-3>')

    def rmb_clicked_event(self, event):
        if not self.is_mine_hopeful:
            self.cell_button_object.configure(
                bg='Orange'
            )
            self.is_mine_hopeful = True
        else:
            self.cell_button_object.configure(
                bg='SystemButtonFace'
            )
            self.is_mine_hopeful = False

    def __repr__(self):
        return f"Cell({self.x}, {self.y})"