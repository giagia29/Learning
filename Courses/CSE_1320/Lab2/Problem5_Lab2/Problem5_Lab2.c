#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[100];
    int i = 0;
    printf("Please enter a string: ");
    fgets(s,100,stdin);
    printf("The reverse string is: \n");
    /*
    We can reverse the string by printing backwards,
    starting from the final position.
    */
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        printf("%c", s[i]);
    }
}
