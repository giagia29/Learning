#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

extern uint64_t addU32_U64(uint32_t x, uint32_t y);

int main()
{
    uint32_t x = 1000000;
    uint32_t y = 2000000;
    uint64_t t = addU32_U64(x,y);
    printf("%u\n", t);
    return 0;
}
