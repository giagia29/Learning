%{
Name: Gia Dao ENGR_1250_003 Date: 05/01/2020.

Problem Statement: Write a program using if-elseif-else statement to ask the user to enter a grade in
numerical form and display the letter grade corresponding to that numerical
grade.

Variable: 

grade: real number entered by the user value from 0 to 100

%}
clear
clc
close all
grade = input('Enter a grade in numerical form: ');
if (grade >= 90)
    fprintf('Letter grade: A.\n');
elseif(80 <= grade && grade < 90)
    fprintf('Letter grade: B.\n');
elseif(70 <= grade && grade < 80)
    fprintf('Letter grade: C.\n');
elseif(60 <= grade && grade < 70)
    fprintf('Letter grade: D.\n');
else
    fprintf('Letter grade: F.\n');
end