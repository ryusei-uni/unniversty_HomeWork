#include <stdio.h>
double calcAverage(int a,int b,int c) {
	return (a + b + c) / 3;
}
int isEven(int n) {
	if (n % 2 == 0) return 1;
	else return 0;
}
int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
int main(void) {
	
	double reslut = calcAverage(11, 16, 90);
	printf("calcAverage {11,16,90}= %0.5f\n",reslut);
	int n=5;
	printf("isEven,%d\n", isEven(n));
	printf("%d!‚Í%d", n, factorial(n));

	return 0;
}