#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//find the median score of the student's records
void FindMedian(char **first, char **last, float *grade, int t)
{
    int i, j;
    float temp;
    char *x = (char*)calloc(20, sizeof(char));
    //sort the records first (in order, from highest to lowest)
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t - i - 1; j++)
        {
            if (*(grade + j) < *(grade + j + 1) && (last[j] != "0") && (last[j + 1] != "0") && (first[j] != "0") && (first[j + 1] != 0))
            {
                temp = *(grade + j + 1);
                *(grade + j + 1) = *(grade + j);
                *(grade + j) = temp;
                strcpy(x,first[j]);
                strcpy(first[j],first[j+1]);
                strcpy(first[j+1],x);
                strcpy(x,last[j]);
                strcpy(last[j],last[j+1]);
                strcpy(last[j+1],x);
            }
        }
    }
    float med1, med2;
    int mid1 = (t - 1)/ 2;
    int mid2 = (t + 1) / 2;
    //if the total number of records is an even number
    if (t % 2 == 0)
    {
        med1 = (float) (grade[mid1] + grade[mid2]) / 2;
        printf("%-5.2f\n\n", med1);
        for (i = 0; i < t; i++)
        {
            if ((grade[i] > med1) && (last[i] != "0") && (first[i] != "0"))
            {
                printf("First name: %-10s", first[i]);
                printf("Last name: %-10s", last[i]);
                printf("Score: %.2f", grade[i]);
                printf("\n");
            }
        }
    }
    else if (t % 2 == 1)
    {
        med2 = (float) grade[mid1];
        printf("%-5.2f\n\n", med2);
        for (i = 0; i < t; i++)
        {
            if ((grade[i] > med2) && (last[i] != "0") && (first[i] != "0"))
            {
                printf("First name: %-10s", first[i]);
                printf("Last name: %-10s", last[i]);
                printf("Score: %.2f", grade[i]);
                printf("\n");
            }
        }
    }
}
//this function is used to find the student's with the matched last name
void SearchLastName(char **first, char **last, float *grade, char *name, int t)
{
    int i, count = 0;
    for (i = 0; i < t; i++)
    {
        if ((last[i] == "0") && (first[i] == "0")) continue;
        else if (strcmp(name,last[i]) == 0) //using linear search
        {
            count = count + 1; //count the total matched last names
            printf("First name: %-10s", first[i]);
            printf("Last name: %-10s", last[i]);
            printf("Score: %.2f", grade[i]);
            printf("\n");
        }
    }
    if (count == 0) printf("No last name matched.");
}
//this function is used to sort the records of all students by last name
void SortLastName(char **first, char **last, float *grade, int t)
{
    int i, j;
    float temp;
    char *x = (char*)calloc(20, sizeof(char));
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t - i - 1; j++)
        {
            //use bubble sort
            if ((strcmp(last[j],last[j+1]) > 0) && (last[j] != "0") && (last[j + 1] != "0") && (first[j] != "0") && (first[j + 1] != 0))
            {
                strcpy(x, last[j]);
                strcpy(last[j], last[j+1]);
                strcpy(last[j+1], x);
                strcpy(x, first[j]);
                strcpy(first[j], first[j+1]);
                strcpy(first[j+1], x);
                temp = *(grade + j);
                *(grade + j) = *(grade + j + 1); //dereference grade at position j
                *(grade + j + 1) = temp;
            }
        }
    }
    //print out the result after done sorting by last name
    int p;
    for (p = 0; p < t; p++)
    {
        if ((last[p] != "0") && (first[p] != "0"))
        {
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.2f", grade[p]);
            printf("\n");
        }
    }
}
//this function is used to sort all the students records by their scores
void SortScore(char **first, char **last, float *grade, int t)
{
    int i, j;
    float temp;
    char *x = (char*)calloc(20, sizeof(char));
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t - i - 1; j++)
        {
            //use bubble sort
            if ((*(grade + j) < *(grade + j + 1)) && (last[j] != "0") && (last[j + 1] != "0") && (first[j] != "0") && (first[j + 1] != 0))
            {
                temp = *(grade + j + 1);
                *(grade + j + 1) = *(grade + j); //dereferenced grade at position j
                *(grade + j) = temp;
                strcpy(x,first[j]); //swapping first and last name due to score
                strcpy(first[j],first[j+1]);
                strcpy(first[j+1],x);
                strcpy(x,last[j]);
                strcpy(last[j],last[j+1]);
                strcpy(last[j+1],x);
            }
        }
    }
    //print out the records after done sorting
    int p = 0;
    for (p = 0; p < t; p++)
    {
        if ((last[p] != "0") && (first[p] != "0"))
        {
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.2f", grade[p]);
            printf("\n");
        }
    }
}
//this function is used to print out records of all students
void PrintRecords(char **first, char **last, float *grade, int t)
{
    int p;
    for (p = 0; p < t; p++)
    {
        if ((last[p] != "0") && (first[p] != "0"))
        {
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.2f", grade[p]);
            printf("\n");
        }
    }
}
//this function shows options that user can choose from
void Option()
{
    printf("Print records (press 1)");
    printf("\n");
    printf("Add a new record (press 2)");
    printf("\n");
    printf("Delete records (press 3)");
    printf("\n");
    printf("Search by last name (press 4)");
    printf("\n");
    printf("Sort by score (press 5)");
    printf("\n");
    printf("Sort by last name (press 6)");
    printf("\n");
    printf("Find the median score (press 7)");
    printf("\n");
    printf("Exit the program (press 0)");
}
int main()
{
   int n, i, number;
   //n is the total number of students that user want to include their records
   char *name = (char*)calloc(10, sizeof(char)); //allocate dynamic memory of char array
   char *l = (char*)calloc(10, sizeof(char));
   float *score;
   char **firstname; //allocate dynamic memory of 2D char array
   char **lastname;
   while(true)
   {
        printf("Please indicate number of records you want to enter (min 5): ");
        scanf("%d", &n);
        printf("\n");
        if (n < 5)
        {
            printf("The number that you enter is not valid.\n\n");
            continue;
        }
        else
        {
            //memory allocation for student's first name, last name, and score.
            score = (float*)calloc(n, sizeof(float));
            firstname = (char**)calloc(n, sizeof(char*));
            lastname = (char**)calloc(n, sizeof(char*));
            printf("Please input records of students \n");
            printf("--------------------------------\n");
            for (i = 0; i < n; i++)
            {
                printf("First name: ");
                firstname[i] = (char*)calloc(10, sizeof(char));
                scanf("%s", firstname[i]);
                printf("Last name: ");
                lastname[i] = (char*)calloc(10, sizeof(char));
                scanf("%s", lastname[i]);
                printf("Score: ");
                scanf("%f", &score[i]);
                printf("\n");
            }
        }
        printf("\n\n");
        while(true)
        {
            printf("Options can perform: \n");
            printf("----------------------\n");
            Option();
            printf("\n\n");
            printf("Please enter a number for your option between 0 and 7: ");
            scanf("%d", &number);
            printf("-------------------------------------------------------\n");
            if (number == 0)
            {
                printf("Exit the program.");
                exit(0);
            }
            else if (number == 1)
            {
                printf("\n");
                PrintRecords(firstname, lastname , score, n);
                printf("\n\n");
            }
            else if (number == 2)
            {
                //after adding a new record, extend the size of the heap by one.
                printf("Enter the records of student you want to add: \n\n");
                firstname = (char**)realloc(firstname, (n + 1) * sizeof(char*));
                printf("Enter first name: ");
                firstname[n] = (char*)calloc(10, sizeof(char));
                scanf("%s", firstname[n]);
                lastname = (char**)realloc(lastname, (n + 1) * sizeof(char*));
                printf("Enter last name: ");
                lastname[n] = (char*)calloc(10, sizeof(char));
                scanf("%s", lastname[n]);
                score = (float*)realloc(score, (n + 1) * sizeof(float));
                printf("Enter score: ");
                scanf("%f", &score[n]);
                printf("\n");
                printf("The new records after adding are: \n");
                for (i = 0; i < n + 1; i++)
                {
                    printf("First name: %-10s", firstname[i]);
                    printf("Last name: %-10s", lastname[i]);
                    printf("Score: %.2f", score[i]);
                    printf("\n");
                }
                printf("\n\n");
                n = n + 1;
            }
            else if (number == 3)
            {
                int count = 0, i, j;
                printf("Enter the last name of student that you want to delete: ");
                scanf("%s", l);
                printf("\n");
                for (i = 0; i < n; i++)
                {
                    if (strcmp(lastname[i], l) == 0)
                    {
                        free(lastname[i]);
                        free(firstname[i]);
                        lastname[i] = "0";
                        firstname[i] = "0";
                        continue;
                    }
                }
                int p;
                for (p = 0; p < n; p++)
                {
                     if ((lastname[p] != "0") && (firstname[p] != "0"))
                    {
                        printf("First name: %-10s", firstname[p]);
                        printf("Last name: %-10s", lastname[p]);
                        printf("Score: %.2f", score[p]);
                        printf("\n");
                    }
                }
                printf("\n\n");
            }
            else if (number == 4)
            {
                printf("Enter the last name that you want to search: ");
                scanf("%s", name);
                printf("\n");
                SearchLastName(firstname, lastname, score, name, n);
                printf("\n\n");
            }
            else if (number == 5)
            {
                printf("The records after sort by score: \n\n");
                SortScore(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 6)
            {
                printf("The records after sort by last name: \n\n");
                SortLastName(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 7)
            {
                printf("The median score of all student records is: ");
                FindMedian(firstname, lastname, score, n);
                printf("\n\n");
            }
            else
            {
                printf("The number you entered is not matched with the options.");
                printf("\n\n");
                continue;
            }
        }
   }
}
