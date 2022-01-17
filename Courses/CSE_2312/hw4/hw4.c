#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define COUNT 3
float dotpF32(const float x[], const float y[], uint32_t count)
{
    float product = 0;
    for (int i = 0; i < count; i++)
    {
        product = product + (x[i] * y[i]);
    }
    return product;
}

void prodF64(double z[], const double x[], const double y[], uint32_t count)
{
    for (int i = 0; i < count; i++)
    {
        z[i] = x[i] * y[i];
    }
}

double minF64(const double x[], uint32_t count)
{
    double min = x[0];
    int i = 1;
    while (i < count)
    {
        if (x[i] < min)
        {
            min = x[i];
        }
        i = i + 1;
    }
    return min;
}

int main()
{
    float x[COUNT] = {1.1,2.2,3.3};
    float y[COUNT] = {4.4,5.5,6.6};
    float p = dotpF32(x,y,COUNT);
    printf("The dot product is: %.2f\n", p);

    double a[COUNT] = {1.2,2.3,3.4};
    double b[COUNT] = {4.5,5.6,6.7};
    double c[COUNT];
    prodF64(c,a,b,COUNT);
    printf("\nproduct F64: ");
    for (int i = 0; i < COUNT; i++) printf("%.2f ", c[i]);

    double t[COUNT] = {-10.1, 20, -3};
    double m = minF64(t, COUNT);
    printf("\n\nThe min is: %.2f\n", m);
    return 0;
}
