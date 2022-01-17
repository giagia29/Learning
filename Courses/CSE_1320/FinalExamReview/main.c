#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct Student
{
    char name[20], id[20];
    int age;
    float cgpa, height, weight;
};

struct Student Insert(char fn[20], char zc[20], int a, float cg, float h, float w)
{
    struct Student x;
    strcpy(x.name,fn);
    strcpy(x.id,zc);
    x.age = a;
    x.cgpa = cg;
    x.height = h;
    x.weight = w;
    return x;
}

void Printf(struct Student x)
{
    printf("Name: %s\n", x.name);
    printf("Student ID: %s\n", x.id);
    printf("Age: %d\n", x.age);
    printf("Student cgpa: %0.2f\n", x.cgpa);
    printf("Height: %0.2f\n", x.height);
    printf("Weight: %0.2f\n", x.weight);
    printf("\n");
}

int main()
{
    int n,i,a;
    char fn[20], zc[20];
    float cg, h, w;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student s[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", fn);
        printf("Enter student id: ");
        scanf("%s", zc);
        printf("Enter age: ");
        scanf("%d", &a);
        printf("Enter cgpa: ");
        scanf("%f", &cg);
        printf("Enter height: ");
        scanf("%f", &h);
        printf("Enter weight: ");
        scanf("%f", &w);
        s[i] = Insert(fn,zc,a,cg,h,w);
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        Printf(s[i]);
        printf("\n");
    }
}
