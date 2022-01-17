#include<stdio.h>
#include<stdlib.h>
/* because the original number to be factorized will be affected
this function will return its original value. */
int Back(int m)
{
    return m;
}
int main()
{
    int x, a[20], count = 0, i = 2, t;
    printf("Enter a number: ");
    scanf("%d", &x);
    int d = Back(x);
    //storing original value x inside variable d.
    for (i = 2; i <= x; i++) // having a for loop to list all possible factors of the number
    {
        while(x % i == 0) //if x is divided by i then continue diving.
        {
            a[count] = i; //storing factor into an array
            count = count + 1; //count acting as an index that points to the position in array a.
            x = x / i;
        }
    }
    printf("The prime factorization of %d is ", d);
    for (t = 0; t < count - 1; t++)
    {
        printf("%d*", a[t]); //using variable count, user can extract the desire value after the number has been factorized.
    }
    printf("%d", a[count - 1]);
}
