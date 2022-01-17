#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100], i, j;
    printf("Enter the numbers: ");
    for (i = 0; i < 10; i++) scanf("%d", &a[i]);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (a[j] > a[j+1]) //making comparison. If the current element is larger than it's follower, then swap.
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Sorted List: ");
    for (int t = 0; t < 10; t++) printf("%d ", a[t]);
}
