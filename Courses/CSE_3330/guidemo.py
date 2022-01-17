# -- PyQt5 pip install PyQt5
# -- Tkinter pip install tkinter
# -- Kivy pip install kivy
#pip install tkinter

from tkinter import *
import sqlite3

#create tkinter window

root = Tk()
root.title('Car Rental')
root.geometry("400x400")

address_book_connect = sqlite3.connect('project2') #link to db

address_book_cur = address_book_connect.cursor()

#address_book_cur.exec
#NO Need for part 3 , cuz already have creates
#address_book_cur.execute('''CREATE TABLE addresses(first_name text,last_name text)''')


#insert vals to DB  
def submit():
	submit_conn = sqlite3.connect('project2')
	submit_cur = submit_conn.cursor()
	submit_cur.execute("INSERT INTO CUSTOMER VALUES(:CustID, :Name, :Phone)",
		{
			'CustID': CustID.get(),
			'Name': Name.get(),
			'Phone': Phone.get()
		})

	#commit changes
	submit_conn.commit()

	#close connection
	submit_conn .close()

#building the gui components
	#pack place grid
	#create text boxes

CustID = Entry(root,width = 30)
CustID.grid(row=0,column=1,padx = 20)

Name = Entry(root,width = 30)
Name.grid(row=1,column=1)

Phone = Entry(root,width = 30)
Phone.grid(row=2,column=1)

#creating labels

CustID_label = Label(root, text = 'ID number: ')
CustID_label.grid(row=0,column=0)

Name_label = Label(root, text = 'Name: ')
Name_label.grid(row=1,column=0)

Phone_label = Label(root, text = 'Phone number: ')
Phone_label.grid(row=2,column=0)

submit_btn = Button(root,text = 'Add Records to DB', command=submit)
submit_btn.grid(row=3,column=0,columnspan = 2, pady = 10, padx = 10, ipadx = 100)
#executes tkinter components
root.mainloop()







