Lab 5 Description and Instruction

Lab 5 ask to write a menu to maintain a student's records, include his first name, last name, score and zip code.

The program should be able to take the minimum of 5 records and provide 7 functionalities to the user for the program to perform. If the user enter a number less than 5, the program will ask the user to enter again.

Required: Create a structure named Student with above information. Then create a linked list where each list node contains a Student.

First the user will enter the total number of students that they want to save their records. After enter the total number of student that the user wants to save their records, they start to enter their first names, last names, scores, and zip code.
Note: The maximum number of characters of a student's firstname and lastname is 20. The student scores must be the type float or double.

After the user has entered all the records, the program will show all the options that it can perform. 

If the user enters 1, the program will print all the records of students that they entered.
(PrintRecords function, Line 40-52)

If the user enters 2, the program will allow the user to add the records of one student, include their first name, last name, score, and zip code. If the information of the student is added to the linked list, the program will pop up "Added successfully." (AddRecord function, Line 54-70)

If the user enters 3, the program will ask the user to type in a student's last name. If any last name in the linked list is matched, the program will delete the records of that student. The program will pop up "Delete successfully" if any matched last name is found. (DeleteRecords function, Line 71-104)

If the user enters 4, the program will ask the user to type in a zip code and print out all the students in the linked list with matched zip code. If there are is no student with matched zip code, the program will print "No student with matched zip code found". (SearchZipCode function, Line 106-124)

If the user enters 5, the program will ask the user to enter minimum score and maximum score, then print the records of all students who have the score between max and min (inclusive) (ScoreRange function, Line 126-145)

If the user enters 6, the program will find the median score in the linked list and print the records of all students who have their scores above the median score. (MedianScore function and PrintMedian function, Line 155-224)

If the user enters 0, the program will exit.

