#include <stdio.h>
#include <stdlib.h>

// this function is used to save the original value of inserted input.
int Back(int x)
{
    return x;
}
int main()
{
    int n, t = 0, d = 0;
    printf("Please enter a number: ");
    scanf("%d", &n);
    int b = Back(n);
    /*
    in order to reverse the number, we have to divide them one by one and add them reversely.
    */
    while(n > 0)
    {
        d = n % 10; // find the remainder.
        n = n / 10;
        t = t * 10 + d; //generate a new number using the remainders that are divided. (reversely) and add them together.
    }
    printf("The sum of two number is: %d + %d = %d", b, t, b + t);
}
