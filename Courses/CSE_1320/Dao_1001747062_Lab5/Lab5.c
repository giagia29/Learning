#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//structure Student contains student's information
struct Student
{
    char firstname[20];
    char lastname[20];
    float score;
    char zipcode[20];
    struct Student *link;
};

struct Student *head;
int n;
//Insert student's information in each nodes.
void Insert(char fn[20], char ln[20], float s, char zc[20])
{
    struct Student *temp = (struct Student*)malloc(sizeof(struct Student));
    strcpy(temp->firstname, fn);
    strcpy(temp->lastname, ln);
    temp->score = s;
    strcpy(temp->zipcode, zc);
    temp->link = head;
    head = temp;
}

void Options()
{
    printf("Print records of all students (press 1)\n");
    printf("Add a new record (press 2)\n");
    printf("Delete record(s) (press 3)\n");
    printf("Search by Zip code (press 4)\n");
    printf("Search by score range (press 5)\n");
    printf("Find the median score (press 6)\n");
    printf("Exit the program (press 0)\n\n");
}
//Print all student's records
void PrintRecords()
{
    struct Student *temp = head;
    while(temp != NULL)
    {
        printf("First name: %-10s ", temp->firstname);
        printf("Last name: %-10s ", temp->lastname);
        printf("Score: %-10.1f", temp->score);
        printf("Zip code: %-10s", temp->zipcode);
        printf("\n");
        temp = temp->link;
    }
}
//Add the record of new student
void AddRecord(char fn[20], char ln[20], float s, char zc[20], int x)
{
    int i;
    struct Student *temp1 = (struct Student*)malloc(sizeof(struct Student));
    strcpy(temp1->firstname, fn);
    strcpy(temp1->lastname, ln);
    temp1->score = s;
    strcpy(temp1->zipcode, zc);
    temp1->link = NULL;
    struct Student *temp = head;
    for (i = 0; i < x - 1; i++)
    {
        temp = temp->link;
    }
    temp->link = temp1;
}
//Delete student's records with matched last name
void DeleteRecords(char target[20])
{
    int count = 0;
    struct Student *temp1, *temp2;
    //if the student at the first node has matched last name
    while((head != NULL) && (strcmp(head->lastname,target) == 0))
    {
        temp1 = head;
        head = head->link;
        free(temp1);
    }
    temp1 = NULL;
    temp2 = head;
    while(temp2 != NULL)
    {
        if (strcmp(temp2->lastname,target) == 0)
        {
            if (temp1 != NULL)
            {
                temp1->link = temp2->link;
            }
            free(temp2);
            temp2 = temp1->link;
            count = count + 1;
        }
        else
        {
            temp1 = temp2;
            temp2 = temp2->link;
        }
    }
    if (count == 0) printf("There are no students with matched last name.");
    else printf("Delete successful.\n\n");
}
//Search for the student with matched zip code
void SearchZipCode(char target[20])
{
    int count = 0;
    struct Student *temp = head;
    while(temp != NULL)
    {
        if (strcmp(temp->zipcode,target) == 0)
        {
            count = count + 1;
            printf("First name: %-10s", temp->firstname);
            printf("Last name: %-10s", temp->lastname);
            printf("Score: %-10.1f", temp->score);
            printf("Zip Code: %-10s", temp->zipcode);
            printf("\n");
        }
        temp = temp->link;
    }
    if (count == 0) printf("There is no student with matched Zip Code.");
}
//find all the students with scores lie between min and max
void ScoreRange(float min, float max)
{
    int count = 0;
    struct Student *temp = head;
    while(temp != NULL)
    {
        //checking if student's score at each node is between min and max
        if((temp->score <= max) && (temp->score >= min))
        {
            count = count + 1;
            printf("First name: %-10s", temp->firstname);
            printf("Last name: %-10s", temp->lastname);
            printf("Score: %-10.1f", temp->score);
            printf("Zip Code: %-10s", temp->zipcode);
            printf("\n");
        }
        temp = temp->link;
    }
    if (count == 0) printf("There are no students have the score among the specified range.");
}

void Swap(char x[20], char y[20])
{
    char temp[20] = " ";
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
//print all students who have score above median
void PrintMedian(float x)
{
    int count = 0;
    struct Student *temp = head;
    while(temp != NULL)
    {
        //compare the student's score at each node to the median
        if((temp->score) > x)
        {
            count = count + 1;
            printf("First name: %-10s", temp->firstname);
            printf("Last name: %-10s", temp->lastname);
            printf("Score: %-10.1f", temp->score);
            printf("Zip Code: %-10s", temp->zipcode);
            printf("\n");
        }
        temp = temp->link;
    }
    if (count == 0) printf("There are no students who have higher score than the median.");
}
//find the median score of all student's records
void MedianScore(int x)
{
    struct Student *i = NULL;
    struct Student *j = NULL;
    int t;
    float temp, result;
    char trans[20] = " ";
    //using bubble sort to sort the data of student in each node
    for (i = head; i != NULL; i = i->link)
    {
        for (j = i->link; j != NULL; j = j->link)
        {
            if (i->score > j->score)
            {
               temp = i->score;
               i->score = j->score;
               j->score = temp;
               Swap(i->firstname,j->firstname);
               Swap(i->lastname,j->lastname);
               Swap(i->zipcode,j->zipcode);
            }
        }
    }
    struct Student *temp1 = head;
    struct Student *temp2 = (struct Student*)malloc(sizeof(struct Student));
    if (x % 2 == 1) //if the total number of nodes is an odd number
    {
        for (t = 0; t < ((x + 1) / 2 - 1); t++)
        {
            temp1 = temp1->link;
        }
        printf("%0.2f", temp1->score);
        printf("\n\n");
        PrintMedian(temp1->score);
    }
    else
    {
        //if the total number of nodes is an even number
        for (t = 0; t < (x / 2 - 1); t++)
        {
            temp1 = temp1->link;
        }
        temp2 = temp1->link;
        result = (float) (((temp1->score) + (temp2->score)) / 2);
        printf("%0.2f", result);
        printf("\n\n");
        PrintMedian(result);
    }
}

int main()
{
    int i, num;
    float s, max, min;
    char fn[20],ln[20],zc[20], target[20];
    head = NULL;
    printf("Please indicate number of records you want to enter (min 5): ");
    scanf("%d", &n);
    printf("\n");
    printf("Please input records of students (enter a new line after each record) with the following format");
    printf("\n\n");
    while(true)
    {
        if (n < 5)
        {
            printf("The enter number is not valid.\n\n");
            continue;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                printf("Enter the student's first name: ");
                scanf("%s", fn);
                printf("Enter the student's last name: ");
                scanf("%s", ln);
                printf("Enter the student's score: ");
                scanf("%f", &s);
                printf("Enter the student's zip code: ");
                scanf("%s", zc);
                printf("\n");
                Insert(fn,ln,s,zc);
            }
            while(true)
            {
                printf("Options can perform: \n\n");
                Options();
                printf("Enter a number for the program to run: ");
                scanf("%d", &num);
                printf("\n");
                if (num == 0)
                {
                    printf("Exit program.\n");
                    exit(0);
                }
                else if (num == 1)
                {
                    printf("The records of all students: \n\n");
                    PrintRecords();
                    printf("\n\n");
                }
                else if (num == 2)
                {
                    printf("Please add the information of student.\n\n");
                    printf("Enter the student's first name: ");
                    scanf("%s", fn);
                    printf("Enter the student's last name: ");
                    scanf("%s", ln);
                    printf("Enter the student's score: ");
                    scanf("%f", &s);
                    printf("Enter the student's zip code: ");
                    scanf("%s", zc);
                    printf("\n");
                    AddRecord(fn,ln,s,zc,n);
                    printf("Add successfully.\n\n");
                    n = n + 1;
                }
                else if (num == 3)
                {
                     printf("Enter the student's last name that you want to delete: ");
                     scanf("%s", target);
                     printf("\n");
                     DeleteRecords(target);
                }
                else if (num == 4)
                {
                    printf("Enter the zip code: ");
                    scanf("%s", target);
                    printf("\n");
                    printf("The students with the same zip code: \n\n");
                    SearchZipCode(target);
                    printf("\n\n");
                }
                else if (num == 5)
                {
                    printf("Enter the min: ");
                    scanf("%f", &min);
                    printf("\n");
                    printf("Enter the max: ");
                    scanf("%f", &max);
                    printf("\n");
                    printf("The students with their scores between max and min: \n\n");
                    ScoreRange(min,max);
                    printf("\n\n");
                }
                else if (num == 6)
                {
                    printf("The median score of student records: \t");
                    MedianScore(n);
                    printf("\n\n");
                }
                else
                {
                    printf("The number you choose cannot be performed.\n\n");
                }
            }
        }
    }
}
