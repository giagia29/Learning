#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int i, j, a[1000], count = 0, n, b = 0, t;
    bool prime[1000] = {true};
    printf("Please enter a positive integer: ");
    scanf("%d", &n);
    for (t = 0; t < 1000; t++) prime[t] = true;
    for (i = 2; i < 1000; i++)
    {
        for (j = i * i; j < 1000; j = j + i)
        {
            prime[j] = false;
        }
    }
    for (i = 2; i < 1000; i++)
    {
        if (prime[i] == true)
        {
            a[count] = i;
            count = count + 1;
        }
    }
    for (i = 0; i < count; i++)
    {
        if (a[i] > n) break;
        for (j = i; j < count; j++)
        {
            if (n - a[i] == a[j])
            {
                printf("%d = %d + %d", n, a[i], a[j]);
                printf("\n");
                b = b + 1;
                break;
            }
        }
    }
    if (b == 0) printf("There is no such expression for the entered number.");
}
