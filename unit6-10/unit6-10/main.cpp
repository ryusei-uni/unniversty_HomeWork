#include <stdio.h>

double calcAverage(float, int, int);



int main(void) {
	printf("%f", calcAverage(1, 2, 4));
	return 0;

}


double calcAverage(float a, int b, int c) {

	double Q = (a + b + c) / 3;
	return Q;
}
