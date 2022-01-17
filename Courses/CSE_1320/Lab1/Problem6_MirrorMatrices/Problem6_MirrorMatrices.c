#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100][100], b[100][100], row, col, c[100][100];
    int check = 0, i, j, p, q, temp;
    printf("Enter dimensions value: ");
    scanf("%d %d", &row, &col); // asking for matrix dimension.
    printf("Enter matrix A: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++) scanf("%d", &a[i][j]); //read the first matrix from the user.
    }
    printf("Enter matrix B: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++) scanf("%d", &b[i][j]); //read the second matrix from the user.
    }
    int t = 0;
    while(t < row) //starting with the first row.
    {
        /*for each row, swapping all the elements backward*/
        p = 0; // start with the first position in row 0.
        q = col - 1; // end position
        while(p <= q)
        {
            /* this is the process of swapping, after
                swap, increment the index of lefty elements and
                decrease the index of right elements until they are all swapped */
            temp = a[t][p];
            a[t][p] = a[t][q];
            a[t][q] = temp;
            p = p + 1;
            q = q - 1;
        }
        t = t + 1; //after finish swapping, moving to the next row.
    }
    /* after swapping all the matrix rows by rows. If the result
    comes out two matrices are the same, then they are mirror. Otherwise, they are not. */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (b[i][j] != a[i][j])
            {
                printf("Both are not mirror matrices of each other.");
                exit(0);
            }
        }
    }
    printf("Both are mirror matrices of each other.");
}
