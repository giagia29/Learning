# pip install tkinter
from tkinter import *

import sqlite3

# create tkinter window

root = Tk()

root.title('Address Book')
root.geometry("400x400")

# the database must be in the same directory with the .py file, also the name must match
address_book_connect = sqlite3.connect('address_book.db')

address_book_cur = address_book_connect.cursor()

address_book_cur.execute('''CREATE TABLE addresses(
                            first_name text,
                            last_name text,
                            street text,
                            zipcode INTEGER)''')


# submit values into the address DB
def submit():
    submit_con = sqlite3.connect('address_book.db')
    submit_cur = submit_con.cursor()
    submit_cur.execute("INSERT INTO addresses VALUES (:f_name, :l_name, :street, :zipcode)",
                       {
                           # create the variable name first
                           'f_name': f_name.get(),
                           'l_name': l_name.get(),
                           'street': street.get(),
                           'zipcode': zipcode.get(),
                       })
    # commit changes
    submit_con.commit()
    submit_con.close()


# building the gui components
# pack place grid
# create text boxes
f_name = Entry(root, width=30)
f_name.grid(row=0, column=1)

l_name = Entry(root, width=30)
l_name.grid(row=1, column=1)

street = Entry(root, width=30)
street.grid(row=2, column=1)

zipcode = Entry(root, width=30)
zipcode.grid(row=3, column=1)

# create label
f_name_label = Label(root, text='First name: ')
f_name_label.grid(row=0, column=0)

# ... continue for l_name, street, and zipcode


# execute tkinter components

root.mainloop()
