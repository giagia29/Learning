#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
This is the recursive function. Calculating element at xth position in the sequence
equals to (x - 1)th ^ 2 - 1
Define the first element in the sequence is 1.
*/
int term(int x)
{

    int result;
    if (x == 1) return 1;
    else result = 1 + term(x - 1) * term(x - 1);
    return result;
}

int main()
{
    int n, i;
    printf("Please enter a number: ");
    scanf("%d", &n);
    printf("The first n terms in the series: \n");
    for (i = 1; i <= n; i++) printf("%d ", term(i));
}
