#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[80];
    printf("Please enter a string: ");
    gets(s);
    /*
    for this problem, we'll be using strtok, to separate the word using pointer once it finds
    the string contains special characters.
    */
    char* word = strtok(s, "1234567890!@#$%^&*()+=_-{'}[]:;,.`~?/<>|"); //find the appearance of the special character.
    // mark the memory address using variable word.
    printf("The new string is: ");
    while(word != NULL)
    {
        //once it's marked, continue with the remaining string.
        printf("%s", word);
        //replace the special character found with NULL variable.
        word = strtok(NULL, "1234567890!@#$%^&*()+=_-{'}[]:;,.`~?/<>|");
    }
}
