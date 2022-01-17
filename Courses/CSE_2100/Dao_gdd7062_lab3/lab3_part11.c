#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	uint8_t a = 0;
	uint8_t b = 6;
	int i = 0;
	printf("a\t a == b\t a < b\t a > b\t\n");
	for (i = 0; i < 32; i++)
	{
		printf("%d\t %d\t %d\t %d\t\n", a, a==b, a<b, a>b);
		a = (a + 1) % 16;
	}
	return 0;
}
