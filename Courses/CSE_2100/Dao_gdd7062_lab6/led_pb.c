#include "sysfs_gpio.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	gpioOutput(4);
	gpioInput(18);
	gpioWrite(4, 1);
	while ( gpioRead(18) != 1 );
	gpioWrite(4, 0);
	return 0;
}
