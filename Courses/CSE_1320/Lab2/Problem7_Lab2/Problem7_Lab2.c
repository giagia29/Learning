#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i, j;
    char s[80][80], t[80];
    printf("Please enter the character array: \n\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%s", s[i]); // for every line, read a string with length 4.
    }
    //using bubble sort to compare the string.
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5 - i - 1; j++)
        {
            if (strcmp(s[j],s[j + 1]) > 0)
            {
                strcpy(t,s[j]); //swap the string value using temporary string.
                strcpy(s[j],s[j + 1]);
                strcpy(s[j + 1],t);
            }
        }
    }
    printf("\n");
    printf("Sorted strings: \n\n");
    for (i = 0; i < 5; i++) printf("%s\n", s[i]);
}
