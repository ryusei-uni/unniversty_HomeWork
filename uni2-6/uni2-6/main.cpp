#include <stdio.h>

int main(void) {
	int a = 10;
	a += 5;
	printf("a = %d \n", a);

	a -= 3;
	printf("a = %d \n", a);

	a *= 2;
	printf("a = %d \n", a);

	a /= 2;
	printf("a = %d \n", a);

	a %= 2;
	printf("a = %d \n", a);
}