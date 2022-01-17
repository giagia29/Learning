#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
int globalvar;
int same_name =3;
void sub_fcn();
int main(void)
{
    int localvar;
    globalvar = 2;
    localvar = 3;
    printf("Starting in main: ");
    printf("globalvar is %d, localvar is %d.\n", globalvar, localvar);
    sub_fcn();
    printf("\nAfter first time returning to main,");
    printf("globalvar is %d, localvar is %d.\n", globalvar, localvar);
    printf("and same_name has value %d.\n", same_name);
    sub_fcn();
    same_name++;
    printf("\nAfter secondtime returning to main,");
    printf("globalvar is %d, localvar is %d.\n", globalvar, localvar);
    printf("and same_name has value %d.\n", same_name);
    return 0;
}
void sub_fcn()
{
    int localvar = 5;
    int same_name;
    globalvar =4;
    localvar++;
    same_name=127;
    printf("\nIn sub_fcn,");
    printf("globalvar is %d, localvar is %d.\n", globalvar, localvar);
    printf("and same_name has value %d.\n", same_name);
}
