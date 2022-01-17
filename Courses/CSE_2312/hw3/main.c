#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define COUNT 5

void sortAscending(uint32_t x[], uint32_t count)
{
    uint32_t i, j;
    uint32_t temp;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            if (*(x + j) > *(x + j + 1))
            {
                temp = *(x + j + 1);
                *(x + j + 1) = *(x + j);
                *(x + j) = temp;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        printf("%u ", *(x + i));
    }
    printf("\n\n");
}


uint32_t sumU16_32(const uint16_t x[], uint32_t count)
{
    uint32_t sum = 0;
    while(count > 0)
    {
        sum += *(x++);
        count--;
    }
    return sum;
}

int32_t sumS32(const int32_t x[], uint32_t count)
{
    int32_t sum = 0;
    while(count > 0)
    {
        sum += *(x++);
        count--;
    }
    return sum;
}

bool isStrSame(const char str1[], const char str2[])
{
    int i;
    bool check;
    for (i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == str2[i])
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}

uint32_t countInRange(const int32_t x[], int32_t low, int32_t high, uint32_t count)
{
    int i = 0, total = 0;
    while(i < count)
    {
        if (x[i] < low || x[i] > high)
        {
            i = i + 1;
        }
        else
        {
            total = total + 1;
            i = i + 1;
        }
    }
    return total;
}

void strConcatenate(char strTo[], const char strFrom[])
{
    int c = 0, d = 0;
    while(strTo[c] != '\0')
    {
        c = c + 1;
    }
    while(strFrom[d] != '\0')
    {
        strTo[c] = strFrom[d];
        d = d + 1;
        c = c + 1;
    }
    strTo[c] = '\0';
}

void rightStringFull(char strOut[], const char strln[], uint32_t length)
{
    uint32_t i;
    if (length < strlen(strln))
    {
        for (i = 0; i < length; i++)
        {
            strOut[i] = strln[i + 1];
        }
        strOut[i] = '\0';
    }
    else strOut[0] = '\0';
}

void rightStringTrunc(char strOut[], const char strln[], uint32_t length)
{
    int i;
    if (length < strlen(strln))
    {
        for (i = 0; i < length; i++)
        {
            strOut[i] = strln[i + 1];
        }
        strOut[i] = '\0';
    }
    else
    {
        for (i = 0; i < strlen(strln); i++)
        {
            strOut[i] = strln[i];
        }
        strOut[i] = '\0';
    }
}

uint16_t decimalStringToUint16(const char* str)
{
    int i = 0;
    uint16_t sum = 0;
    while (i < strlen(str))
    {
        sum = sum + (str[i] - 48);
        if (i == strlen(str) - 1)
        {
            break;
        }
        sum = sum * 10;
        i = i + 1;
    }
    return sum;
}

int8_t decimalStringToInt8(const char* str)
{
    int8_t sum = 0;
    if (str[0] == '-')
    {
        int i = 1;
        while (i < strlen(str))
        {
            sum = sum + (str[i] - 48);
            if (i == strlen(str) - 1)
            {
                break;
            }
            sum = sum * 10;
            i = i + 1;
        }
        sum = (-1) * sum;
    }
    return sum;
}

int main(void)
{
    uint16_t x[COUNT] = {10, 20, 30, 10, 20};
    uint32_t sumU16 = sumU16_32(x,COUNT);
    printf("The sum is: %u\n\n", sumU16);

    int32_t y[COUNT] = {-10,-20,-30,-10,-20};
    int32_t sum32 = sumS32(y,COUNT);
    printf("The sum is: %d\n\n", sum32);

    char str1[10] = "abcd";
    char str2[10] = "abcd";
    bool check = isStrSame(str1,str2);
    if (check == 1)
    {
        printf("two strings are same\n\n");
    }
    else printf("they are not equal\n\n");

    int32_t z[COUNT] = {7,8,9,10,11};
    int32_t low = 6;
    int32_t high = 15;
    uint32_t total = countInRange(z, low, high, COUNT);
    printf("the total number that is >= low and <= high: %u\n\n", total);

    char strTo[50] = "abcd", strFrom[50] = "efgh";
    strConcatenate(strTo, strFrom);
    printf("String after concatenation: %s\n\n", strTo);

    char strln[50] = "abcdef", strOut[50];
    int length = 5;
    rightStringFull(strOut, strln, length);
    printf("strOut is: '%s'\n\n", strOut);

    char strLn[50] = "abcdef", strout[50];
    int l = 7;
    rightStringTrunc(strout, strLn, l);
    printf("strOut is: '%s'\n\n", strout);

    uint32_t array[COUNT] = {5,2,4,3,1};
    printf("The array after sorting: ");
    sortAscending(array,COUNT);

    char strnum[50] = "12345";
    uint16_t number = decimalStringToUint16(strnum);
    printf("The string convert to uint16 is: %u\n\n", number);

    char strnum1[50] = "-101";
    int8_t number1 = decimalStringToInt8(strnum1);
    printf("The string convert to int8 is: %d\n\n", number1);
    return 0;
}
