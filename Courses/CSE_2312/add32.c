// C99

#include <stdio.h>  // printf
#include <stdint.h> // C99 uintX_t and intX_t types

extern uint32_t add32(uint32_t a, uint32_t b);

/*
uint32_t add32(uint32_t a, uint32_t b)
{
    return a + b;
}
*/

int main(void)
{
    uint32_t x = 2;
    uint32_t y = 3;
    uint32_t z = add32(x, y);
    printf("x = %u\n", x);
    printf("y = %u\n", y);
    printf("z = %u\n", z);
        
    return 0;
}


