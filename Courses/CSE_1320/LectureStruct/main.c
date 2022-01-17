#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* struct person
{
    char name[15];
    int age;
};
int main(void)
{
  struct person John = {"John Smith",25};
  struct person Mary = {"Mary Jones",32};
  printf("%s is %d\n", John.name, John.age);
  printf("%s is %d\n", Mary.name, Mary.age);
} */
/* struct person
{
    char name[50];
    int age;
};
struct person fx(struct person a);
int main(void)
{
    struct person UTAstudent = {"Mary Steel",25};
    struct person newa, temp;
    printf("%s is %d years old.\n", UTAstudent.name, UTAstudent.age);
    UTAstudent.age = 99;
    printf("%s is %d years old.\n", UTAstudent.name, UTAstudent.age);
    strcpy(UTAstudent.name, "Bob");
    printf("%s is %d years old.\n", UTAstudent.name, UTAstudent.age);
    newa = fx(UTAstudent);
    printf("%s is %d years old.\n", newa.name, newa.age);
    temp = UTAstudent;
    UTAstudent = newa;
    newa = temp;
    printf("was UTAstudent: %s is %d years old.\n", UTAstudent.name, UTAstudent.age);
    printf("was Tom: %s is %d years old.\n", newa.name, newa.age);
}
struct person fx(struct person a)
{
    struct person old = {"Tom",20};
    old.age += a.age;
    return old;
}; */

struct automobile
{
    char make[50];
    char model[50];
    int year;
};
void fx(struct automobile c[], int rows);
void fx2(struct automobile d);
int main()
{
    struct automobile cars[] = {{"Ford","Mustang",2010}, {"Chevy","Tahoe",2004}, {"Chevy","Impala",1966}};
    struct automobile mycar = {"Mazda","Mazda3",2009};
    int rows = sizeof(cars)/sizeof(cars[0]);
    int i;
    printf("%d %s %s\n", cars[0].year, cars[0].make, cars[0].model);
    fx(cars,rows);
    fx2(mycar);
    for(i = 0; i < rows; i++) fx2(cars[i]);
}
void fx2(struct automobile d)
{
    printf("I own a %s %s\n", d.make, d.model);
}
void fx(struct automobile c[], int rows)
{
    int i;
    for (i = 0; i < rows; i++)
    printf("%s %s\n", c[i].make, c[i].model);
}
