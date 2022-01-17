#include <stdio.h>
#include <stdlib.h>
void Sort(int x[100])
{
    int t, i, j, tmp = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6 - i - 1; j++)
        if (x[j] > x[j + 1])
        {
            tmp = x[j];
            x[j] = x[j + 1];
            x[j + 1] = tmp;
        }
    }
}
//this function is created to count the occurrence of each element
int LargestOccurence(int x[100], int p)
{
    int count = 0, i;
    for (i = 0; i < 6; i++)
    {
        if (x[i] == p) count = count + 1;
    }
    return count;
}

int Mode(int x[100])
{
    int max = LargestOccurence(x, x[0]);
    int num = 0, i;
    for (i = 1; i < 6; i++)
    {
        int s = 0;
        s = LargestOccurence(x, x[i]);
        //compare with max in order to get the mode.
        if (max < s)
        {
            /*
            once have the element with largest occurrence
            return that element.
            */
            num = x[i];
        }
    }
    return num;
}

double Median(int x[100])
{
    // the median is equal to the average of 2 middle numbers.
    double median = (double) (x[2] + x[3]) / 2;
    return median;
}

// this function find the mean of hours studying and playing in 6 days.
double Mean(int x[100])
{
    Sort(x);
    int t, sum = 0;
    for (t = 0; t < 6; t++) sum = sum + x[t];
    double average = (double) sum / 6;
    return average;
}

int main()
{
    int a[100], b[100], i;
    printf("Please enter hours of playing video games each day within a week: \n");
    for (i = 0; i < 6; i++) scanf("%d", &a[i]);
    printf("\n");
    printf("Please enter hours of studying each day within a week: \n");
    for (i = 0; i < 6; i++) scanf("%d", &b[i]);
    int r = Mode(a), k = Mode(b);
    printf("\n");
    printf("Mean of A is: %.2f  Median of A is: %.2f  Mode of A is: %d\n", Mean(a), Median(a), r);
    printf("\n");
    printf("Mean of B is: %.2f  Median of B is: %.2f  Mode of B is: %d\n", Mean(b), Median(b), k);
    printf("\n");
    if ((Mean(a) > Mean(b)) && (Median(a) > Median(b)) && (Mode(a) > Mode(b)))
    {
        printf("You are playing more video games you have to spent more time studying.");
    }
    else if ((Mean(a) < Mean(b)) && (Median(a) < Median(b)) && (Mode(a) < Mode(b)))
    {
        printf("Good, you are spending considerable time in studying.");
    }
    else if ((Mean(a) == Mean(b)) && (Median(a) == Median(b)) && (Mode(a) == Mode(b)))
    {
        printf("You know how to balance your time.");
    }
    else printf("Sorry, cannot make up an outcome.");
}
