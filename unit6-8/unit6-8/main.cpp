#include <stdio.h>
#include "mymath.h"
int n = 5;
int main(void) {
	int result = getMax(10, 5);
	printf("最大値：　%d\n", result);
	printf("最大値：　%d\n", getMax(3, 8));
	isEven(6);
	printf("３つの平均は%d\n",calcAverage(6,5,3));
	printf("%d! = %d", n, factorial(n));
	return 0;

}