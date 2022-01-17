#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[50], i, j, count = 0, n;
    // the array has to be sorted.
    printf("Please enter a sorted array with 20 integers: ");
    for (i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Please enter a target value: ");
    scanf("%d", &n);
    for (i = 0; i < 20; i++)
    {
        /*
        whenever reach an element that is larger than the target,
        we don't have to search for the rest of the array as all remaining
        elements will be larger than the target.
        */
        // this will save running times for the problem.
        if (a[i] > n)
        {
            break;
        }
        for (j = i + 1; j < 20; j++)
        {
            if (n - a[i] == a[j])
                /*
                for every elements, find all the elements after it that the target
                subtract equals to that element.
                */
            {
                printf("(%d,%d) ", a[i],a[j]); //once found, print out the result.
                count = count + 1; //increment the number of matched pair.
                break; //after found then break to move to the next elements.
            }
        }
    }
    // print this line if there is no pair.
    if (count == 0) printf("No pair of integers in the given array can be summed to the target value.");
}
