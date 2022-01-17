#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Function DifferentChar is set up in order to check the numbers
of different characters in the array, does not include space character.
*/
void DifferentChar(char x[100], int h)
{
    int i, j, p = 0, dem = 0;
    char r[100];
    for (i = 0; i < h; i++)
    {
        int t = 0;
        if (x[i] == ' ') continue;
        else{
            /*
                Saying we are consider a character at position i,
                then we have to look through all the elements that stand
                before that characters, from 0 to i - 1, to see if there is any resemble characters.
            */
            for (j = 0; j < i; j++)
            {
                if (x[j] == x[i])
                {
                    // if one character is found to be similar, break from the loop
                    // move to the next character of position i + 1.
                    t = 1;
                    break;
                }
            }
            /*
            If it is not marked as true, then add the character into the new array
            and increment the total numbers of different characters.
            */
            if (t == 0)
            {
                r[p] = x[i];
                p = p + 1;
                dem = dem + 1;
            }
        }
    }
    printf("Number of characters repeated: %d", dem);
    printf("\n");
    printf("Characters repeated: ");
    for (i = 0; i < p - 1; i++) printf("%c,", r[i]);
    printf("%c", r[p - 1]);
}


int CountOccurrence(char x[100], char c)
{
    int count = 0, i;
    for (i = 0; i < strlen(x); i++)
    {
        // any character is similar to c then increment the count.
        if (x[i] == c) count = count + 1;
    }
    return count;
}

void Frequency(char x[100])
{
    int t, add = 0, j, p = 0;
    char c[100];
    for (t = 0; t < strlen(x); t++)
    {
       int sum = 1;
       if (x[t] == ' ') continue; // if it's space character then skip.
       else{
        // count the occurrence of each element.
        sum = CountOccurrence(x , x[t]);
        if (sum > 1)
        // if any character has the occurrence larger than 1.
        // Add to the array.
        {
            c[p] = x[t];
            p = p + 1;
        }
       }
    }
    DifferentChar(c,p); //among those characters have more than 1 appearance, call the DifferentChar function
    // with the new array c that stores the characters.
}
int main()
{
    char s[100];
    printf("Please enter a string: ");
    fgets(s, 100, stdin);
    Frequency(s);
}
