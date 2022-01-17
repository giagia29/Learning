#include <stdio.h>
#include <stdlib.h>

void plus(int x)
{
    x = x + 2;
}

void f1(int *x, int * y, int z)
{
    x = x + *y;
    *y = *x + 2;
    z = z + 3;
}

void f2 (int d[], int SIZE)
{
    int i;
    for (i=0;i<SIZE;i++) d[i]=d[i]*2;
}

int main()
{
    int a[4]={0};
    int b[5]= {1, 2};
    int i;
    f2(b,4);
    for (i=0;i<5;i++) printf(" %d", b[i]);
    printf("\n");

    int k = 3;
    plus(k);
    int x[5] = {1,2,3,4};
    f2(x,4);
    printf(" %d\n", k);
    for (i=0;i<5;i++) printf(" %d", x[i]);
    printf("\n");

    return 0;
}

/* void f1( int *x, int y)
{
    x = x + y;
}
void f2 (int d[][5], int ROWS)
{
    int i,j;
    for (i=0;i<4;i++)
        for (j=0;j<4;j++) d[i][j]=d[i][j+1]+3;
}
int main()
{
    int a[4][5]={ {11,21,3}, {2,3,3}, {7,12,2,2,2}, {32,23}};
    int i,j;
    f1(&a[2][1],a[3][0]);
    f2(a,4);
    for (i=0;i<4;i++)
    {
        for (j=0;j<5;j++)
        printf(" %d",a[i][j]);
        printf("\n");
    }
    return 0;
} */
