#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//this function will find the minimum score of students in the record.
void FindMinScore(char first[100][100], char last[100][100], float grade[100], int t)
{
    float min = grade[0];
    int i = 0;
    for (i = 1; i < t; i++)
    {
        if (min > grade[i])
        {
            min = grade[i]; //determine the minimum score using for loop
        }
    }
    int p;
    for (p = 0; p < t; p++)
    {
        if (grade[p] == min)
        /* once find out the minimum score, if any student who has the same
        score with the minimum then also print out their results */
        {
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.1f", grade[p]);
            printf("\n");
        }
    }
}
//this function will find the maximum score of students in the record.
void FindMaxScore(char first[100][100], char last[100][100], float grade[100], int t)
{
    float max = grade[0];
    int i = 0;
    for (i = 1; i < t; i++)
    {
        if (max < grade[i])
        {
            max = grade[i]; //determine the maximum score using for loop
        }
    }
    int p;
    for (p = 0; p < t; p++)
    {
        if (grade[p] == max)
        /* once find out the minimum score, if any student who has the same
        score with the minimum then also print out their results */
        {
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.1f", grade[p]);
            printf("\n");
        }
    }
}
//this function is used to sort the record of students by their last name.
void SortByLastName(char first[100][100], char last[100][100], float grade[100], int t)
{
    int i, j;
    float temp = 0;
    char x[100] = " ";
    //using bubble sort.
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t - i - 1; j++)
        {
            if (strcmp(last[j],last[j+1]) > 0)
            {
                strcpy(x,last[j]);
                strcpy(last[j],last[j+1]);
                strcpy(last[j+1],x);
                strcpy(x,first[j]);
                strcpy(first[j],first[j+1]);
                strcpy(first[j+1],x);
                temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
            }
        }
    }
    int p;
    //print out the result once done sorting.
    for (p = 0; p < t; p++)
    {
        printf("First name: %-10s", first[p]);
        printf("Last name: %-10s", last[p]);
        printf("Score: %.1f", grade[p]);
        printf("\n");
    }
}
//this function is used to sort the records of students by their scores.
void SortByScore(char first[100][100], char last[100][100], float grade[100], int t)
{
    int i, j;
    float temp = 0;
    char x[100] = " ";
    //using bubble sort.
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < t - i - 1; j++)
        {
            if (grade[j] < grade[j + 1])
            {
                temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
                strcpy(x,last[j]);
                strcpy(last[j],last[j+1]);
                strcpy(last[j+1],x);
                strcpy(x,first[j]);
                strcpy(first[j],first[j+1]);
                strcpy(first[j+1],x);
            }
        }
    }
    int p;
    //print out the result once done sorting.
    for (p = 0; p < t; p++)
    {
        printf("First name: %-10s", first[p]);
        printf("Last name: %-10s", last[p]);
        printf("Score: %.1f", grade[p]);
        printf("\n");
    }
}
//this function is used to search for the last name in the record if it is matched with the last name entered by user.
void SearchByLastName(char name[100], char first[100][100], char last[100][100], float grade[100], int t)
{
    int p, count = 0;
    for (p = 0; p < t; p++)
    {
        if (strcmp(name,last[p]) == 0)
        {
            count = count + 1; //count total first name that match.
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.1f", grade[p]);
            printf("\n");
        }
    }
    if (count == 0) printf("No last name matched.");
}
//this function is used to search for the first name in the record if it is matched with the first name entered by user.
void SearchByFirstName(char name[100], char first[100][100], char last[100][100], float grade[100], int t)
{
    int p, count = 0;
    for (p = 0; p < t; p++)
    {
        if (strcmp(name,first[p]) == 0)
        {
            count = count + 1; //count total last name that match.
            printf("First name: %-10s", first[p]);
            printf("Last name: %-10s", last[p]);
            printf("Score: %.1f", grade[p]);
            printf("\n");
        }
    }
    if (count == 0) printf("No first name matched.");
}
//this function is used to print out the record after finish entering all statistics.
void PrintRecords(char first[100][100], char last[100][100], float grade[100], int t)
{
    int p;
    for (p = 0; p < t; p++)
    {
        printf("First name: %-10s", first[p]);
        printf("Last name: %-10s", last[p]);
        printf("Score: %.1f", grade[p]);
        printf("\n");
    }
}
//this function will be called to show out all functions that the program can perform
void Option()
{
    printf("Print records (press 1)");
    printf("\n");
    printf("Search by first name (press 2)");
    printf("\n");
    printf("Search by last name (press 3)");
    printf("\n");
    printf("Sort by score (press 4)");
    printf("\n");
    printf("Sort by last name (press 5)");
    printf("\n");
    printf("Find Max Score (press 6)");
    printf("\n");
    printf("Find Min Score (press 7)");
    printf("\n");
    printf("Exit the program (press 0)");
}

int main()
{
    int n, i = 0, number;
    float score[100];
    char firstname[100][100], lastname[100][100], name[100];
    //creating a while loop so that the program will run forever, and only stop when press 0.
    while(true)
    {
        printf("Please indicate number of records you want to enter (min 5, max 15): ");
        scanf("%d", &n); //read the total number of students user want to enter.
        printf("\n");
        if ((n < 5) || (n > 15))
        {
            continue; //if the user enter wrong number, it will ask to enter again.
        }
        else if ((n >= 5) && (n <= 15))
        {
            //start recording first name, last name and score of each student.
            printf("Please input records of students \n");
            printf("--------------------------------\n");
            for (i = 0; i < n; i++)
            {
                printf("First name: ");
                scanf("%s", firstname[i]);
                printf("Last name: ");
                scanf("%s", lastname[i]);
                printf("Score: ");
                scanf("%f", &score[i]);
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
                PrintRecords(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 2)
            {
                printf("First name needed to search: ");
                scanf("%s", name);
                printf("\n");
                SearchByFirstName(name, firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 3)
            {
                printf("Last name needed to search: ");
                scanf("%s", name);
                printf("\n");
                SearchByLastName(name, firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 4)
            {
                printf("The records of students after sorting by score: \n\n");
                SortByScore(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 5)
            {
                printf("The records of students after sorting by last name: \n\n");
                SortByLastName(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 6)
            {
                printf("All the students with maximum scores in the records are: \n\n");
                FindMaxScore(firstname, lastname, score, n);
                printf("\n\n");
            }
            else if (number == 7)
            {
                printf("All the students with minimum score in the records are: \n\n");
                FindMinScore(firstname, lastname, score, n);
                printf("\n\n");
            }
            else
            {
                printf("The number you typed in is incorrect.\n");
                printf("Please enter number for options again.\n\n");
                continue;
            }
        }
    }
}
