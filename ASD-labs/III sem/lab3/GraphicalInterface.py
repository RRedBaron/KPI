from tkinter import Tk, Frame, Button, Label, Entry, messagebox

from BTree import *


class MainWindow(Tk):
    def __init__(self):
        super().__init__()

        self.tree = BTree(25)
        self.tree.insert(3)

        self.__frame = Frame(self)
        self.__add_button = Button(self.__frame, text='Add Value', font=("Comic Sans MS", 12), width=18,
                                   command=self.add_value)
        self.__search_button = Button(self.__frame, text='Search by key', font=("Comic Sans MS", 12), width=18,
                                      command=self.search)
        self.__delete_button = Button(self.__frame, text='Delete value', font=("Comic Sans MS", 12), width=18,
                                      command=self.delete_value)
        self.__edit_button = Button(self.__frame, text='Edit value', font=("Comic Sans MS", 12), width=18,
                                    command=self.edit_value)
        self.__value_entry = Entry(self.__frame)
        self.__key_entry = Entry(self.__frame)
        self.__name_label = Label(self.__frame, text='BTree DEMO', font=("Comic Sans MS", 12))
        self.__key_label = Label(self.__frame, text='Key', font=("Comic Sans MS", 12))
        self.__value_label = Label(self.__frame, text='Value', font=("Comic Sans MS", 12))

    def create_workspace(self):
        self.title('BTree DEMO')
        self.resizable(width=False, height=False)
        self.__frame.grid(row=0, column=1, padx=10, pady=10)
        self.__name_label.grid(row=0, column=0, columnspan=2)
        self.__key_label.grid(row=1, column=0)
        self.__key_entry.grid(row=1, column=1)
        self.__value_label.grid(row=3, column=0)
        self.__value_entry.grid(row=3, column=1)
        self.__add_button.grid(row=1, column=2, padx=10)
        self.__search_button.grid(row=2, column=2)
        self.__delete_button.grid(row=3, column=2)
        self.__edit_button.grid(row=4, column=2)

    def start(self):
        self.create_workspace()
        self.mainloop()

    def add_value(self):
        key = self.__key_entry.get()
        self.tree.insert(int(key))
        messagebox.showinfo('Success!', 'Key has been added')

    def search(self):
        key = self.__key_entry.get()
        result = self.tree.search(int(key))
        if result:
            messagebox.showinfo('Success!', 'Key has been found')
        else:
            messagebox.showerror('Failure!', 'Key hasn`t been found')

    def delete_value(self):
        key = self.__key_entry.get()
        self.tree.delete(int(key))
        messagebox.showinfo('Success!', 'Key has been deleted')

    def edit_value(self):
        old_key = self.__key_entry.get()
        new_key = self.__value_entry.get()
        self.tree.edit(int(old_key), int(new_key))
        messagebox.showinfo('Success!', 'Value has been edited')
