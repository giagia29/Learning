#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col, matrix1[100][100], matrix2[100][100], sum[100][100];
    int i, j, k, r, t, p;
    printf("Enter the number of row: ");
    scanf("%d", &row);
    printf("Enter the number of column: ");
    scanf("%d", &col);
    // asking the user to enter value for matrix 1.
    printf("Enter value for matrix 1: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    // asking user to enter the value for matrix 2.
    printf("Enter value for matrix 2: \n");
    for (t = 0; t < row; t++)
    {
        for (p = 0; p < col; p++)
        {
            scanf("%d", &matrix2[t][p]);
        }
    }
    printf("Sum of 2 matrixes is: \n");
    /* because two matrices have the same dimensions. Only need to use 2 for loops,
    and add the elements at corresponding positions together */
    for (k = 0; k < row; k++)
    {
        for (r = 0; r < col; r++)
        {
            sum[k][r] = matrix1[k][r] + matrix2[k][r];
            printf("%d ", sum[k][r]);
        }
        printf("\n");
    }
}
