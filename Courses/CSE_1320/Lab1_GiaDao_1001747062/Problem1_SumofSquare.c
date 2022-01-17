#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x, array[10], count = 0, i, t, j;
    printf("Please enter: x = ");
    scanf("%d", &x);
    printf("Please enter the array: ");
    for (t = 0; t < 10; t++) scanf("%d", &array[t]);
    for (i = 0; i < 9; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            /* checking if the square of current element is equal to the square of input number,
            subtract any other square of a different number in the array */
            if ((pow(x,2) - pow(array[i],2)) == pow(array[j], 2))
            {
                printf("(%d,%d) ", i, j); //if there are matches number, then break from the loop, starting with the new element.
                count = count + 1; //counting variable will count the pairs of numbers in the array.
                break;
            }
        }
    }
    if (count == 0) printf("There are no such pairs.");
}
