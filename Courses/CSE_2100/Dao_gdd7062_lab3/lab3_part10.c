#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main()
{
	uint8_t a = 0;
	uint8_t b = 6;
	int i = 0;
	printf("a\t a == b\t a < b\t a > b\t\n");
	for (i = 0; i < 512; i++)
	{
		if (a == b)
		{
			printf("%d\t 1\t 0\t 0\t\n", a);
		}
		else if (a < b)
		{
			printf("%d\t 0\t 1\t 0\t\n", a);
		}
		else
		{
			printf("%d\t 0\t 0\t 1\t\n", a);
		}
		a++;
	}
	return 0;
}
