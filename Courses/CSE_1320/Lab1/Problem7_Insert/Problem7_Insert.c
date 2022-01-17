#include <stdio.h>
#include <stdlib.h>

void Insertion(int x, int n, int a[100])
{
    int b[n + 1], t, i, j, temp = 0;
    // if insert one more element to the new array, array b is larger than array a by 1 vacancy.
    for (t = 0; t < n; t++)
    {
        b[t] = a[t]; //copy all the values of array a to array b.
    }
    b[n] = x; //inserting the element typed in by the user at the last position of array b.
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n + 1; j++)
        {
            if (b[i] > b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    } // start sorting new array after having copied the value and inserted the element.
    for (i = 0; i < n + 1; i++) printf("%d \n", b[i]);
}


int main()
{
    int n, a[100], x, i;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
    printf("Input array elements: \n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("The element to be inserted can be: \n");
    scanf("%d", &x);
    printf("Expected output: \n");
    Insertion(x, n, a);
}
