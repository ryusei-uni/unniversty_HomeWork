#include <stdio.h>
#include <math.h>

int main(void) {
	double deg = 30.0;
	double red = deg * 3.14159265358979 / 180;
	double result = sin(red);
	printf("sin(30) = %.4f\n", result);
	return 0;
}