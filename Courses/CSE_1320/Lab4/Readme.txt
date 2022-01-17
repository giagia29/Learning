Lab4 Description and Instruction
Lab4 is a menu that containts student records, include their firstnames, lastnames and scores.

First the user will enter the total number of students that they want to save their records (Line 193-200).

Note: The total number of students must larger than 5, if the user enters a number smaller than 5, then the program will ask the user to enter the total number of students again.

After enter the total number of student that the user wants to save their records, they start to enter their firstnames, lastnames, and scores.
Note: The maximum number of characters of a student's firstname and lastname is 20. The student scores must be the type float or double.
The dynamic memory is allocated exactly for the size so make sure that you enter the right amount of characters; otherwise the program will crash (do not exceed the maximum).

After the user has entered all the records, the program will show all the options that it can perform.

If the user enters 1, the program will print all the records of students that they entered. (Line 236 - 241)

If the user enters 2, the program will allow the user to add the records of one more student, include their firstname, lastname and score. (Line 242 - 267)
Note: After enter the new student's records, the program will perform on the new menu that includes the records of the new students (The new menu will be printed out if the user has done entered the records).

If the user enters 3, the program will allow the user to enter the lastname of a student. If the entered lastname matches with any lastname in the menu, the program will delete all the records of the student with the matched lastname. 

If the user enter 4, the program will ask the user to type in a lastname and it will print out all the records of all the students with matched lastnames. If no students are found, then the program will print out "No matched lastnames." (Line 291 - 299)

If the user enter 5, the program will sort the records of all students and print them out using bubble sort. (Line 300 - 304)

If the user enter 6, the program will sort the records of all students by their lastnames and print them out (also using bubble sort) (Line 306 - 311)

If the user enter 7, the program will find the median score of all students and print it out.
Note: The program will sort the records by score first (in order, from highest to lowest) and then find the median. (Line 312 - 316)

If the user enter 0, the program will exit. (Line 231 - 236)

If the user enter the number that is not listed, the program will print out "No matched with any options" and ask the user to choose again. (Line 319 - 323)
