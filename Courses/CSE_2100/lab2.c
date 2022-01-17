#include <stdlib.h>
#include <stdio.h>
int main()
{
	int A, B;
	printf("Enter A: ");
	scanf("%d", &A);
	printf("Enter B: ");
	scanf("%d", &B);
	printf("A && B: %d, A || B: %d, !(A || B): %d\n", A && B, A || B, !(A || B));
	return 0;

}
