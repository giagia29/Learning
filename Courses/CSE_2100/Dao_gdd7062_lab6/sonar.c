#include "sysfs_gpio.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	gpioOutput(4);
	gpioInput(18);
	gpioWrite(4, 0);
	gpioWrite(4, 1);
	int count = 0;
	while ( gpioRead(18) != 1 );
	while ( gpioRead(18) != 0 )
	{
		count++;
	}
	printf("%d\n", count); 
	int final = count * 122 / 40;
	printf("%d\n", final);

	return 0;
}
