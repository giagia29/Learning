#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

extern uint64_t addU64(uint64_t x, uint64_t y);

int main()
{
  uint64_t x, y, z;
  x = 20000000000;
  y = 30000000000;
  z = addU64(x, y);
  printf("x = %llu\n", x); // format modifier is LL lower-case, not eleven
  printf("y = %llu\n", y);
  printf("z = x + y = %llu\n", z);
  return EXIT_SUCCESS;
}

