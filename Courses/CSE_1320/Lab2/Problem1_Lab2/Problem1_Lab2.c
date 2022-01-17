#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x, y, a[100], b[50], i, j = 0, tmp;
   printf("Please enter number of integers for array A: x = ");
   scanf("%d", &x);
   printf("\n");
   printf("Please enter number of integers for array B: y = ");
   scanf("%d", &y);
   printf("\n");
   printf("Enter array A: \n");
   for (i = 0; i < x; i++) scanf("%d", &a[i]);
   printf("\n");
   printf("Enter array B: \n");
   for (i = 0; i < y; i++) scanf("%d", &b[i]);
   i = x;
   /*
   Adding array B to array A, then have to start with the final
   position of array A and add whole array B starting from that
   position: Mark i as x (x is the final position of array A).
   */
   while((i < x + y) && (j < y))
    /*
    The total elements have to extend, equal to the number of elements
    in array A, x, plus the number of elements in array B, y, in order to
    get the total elements of new array A.
    */
   {
       /*
       After copying the first element in array B
       into the final position in array A, increment the index
       to move to the blank position to continue copying the value.
       */
       a[i] = b[j];
       i = i + 1;
       j = j + 1;
   }
   // sorting the new array A after it has done adding using bubble sort.
   for (i = 0; i < x + y - 1; i++)
   {
       for (j = i + 1; j < x + y; j++)
       {
           if (a[i] > a[j])
           {
               tmp = a[i];
               a[i] = a[j];
               a[j] = tmp;
           }
       }
   }
   printf("\n");
   printf("Finally, after merging A and B, A becomes: \n");
   for (i = 0; i < x + y; i++) printf("%d ", a[i]);
}
