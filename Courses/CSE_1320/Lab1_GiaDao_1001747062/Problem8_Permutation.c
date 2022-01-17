#include <stdio.h>
#include <stdlib.h>

int factorial(int x) /*calculating permutation using recursion*/
{
    int gt = 1;
    if (x == 0) return gt;
    else if (x > 0) gt = x * factorial(x - 1); //current factorial(x) equals x times factorial(x-1). Exactly the same to provided formula
}

int main()
{
   int n, r;
   printf("Enter n: ");
   scanf("%d", &n);
   printf("Enter r: ");
   scanf("%d", &r);
   int result = factorial(n) / factorial(n - r); // calculating permutation and store in variable result
   printf("The result is: %d", result);
}
