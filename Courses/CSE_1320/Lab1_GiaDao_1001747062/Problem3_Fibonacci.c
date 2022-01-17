#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, fibo[100], i = 2, sum = 0, t;
    fibo[0] = 0; // we have to assign the first two value, otherwise the program will crash with undetermined value.
    fibo[1] = 1;
    printf("Enter the number of terms: \n");
    scanf("%d", &x);
    printf("\n");
    while(i <= x)
    {
        // the current number equals the sum of its two previous standing numbers.
        fibo[i] = fibo[i - 2] + fibo[i - 1];
        i = i + 1;
    }
    printf("First 6 terms of Fibonacci numbers are: \n");
    for (t = 0; t < x; t++)
    {
        sum = sum + fibo[t]; //after storing the fibonacci value into the array, adding them to get the sum.
        printf("%d\n", fibo[t]);
    }
    printf("\n");
    printf("The sum value of the above sequence is: \n");
    printf("%d", sum);
}
