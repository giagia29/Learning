#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubblesort(int x[20], int t)
{
    if (t == 1) return;
    int i, temp;
    for (i = 0; i < t - 1; i++)
    {
        if (x[i] > x[i + 1])
        {
            temp = x[i];
            x[i] = x[i + 1];
            x[i + 1] = temp;
        }
    }
    bubblesort(x, t - 1);
}

int main()
{
    int n, a[20], i;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Enter all elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    bubblesort(a,n);
    printf("Array after sorted: \n");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
}
