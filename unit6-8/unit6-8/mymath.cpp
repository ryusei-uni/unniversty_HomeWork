#include <stdio.h>

#include "mymath.h"
void greet(void) {
	printf(" ‚±‚ñ‚É‚¿‚Í\n");
}

void printMax(int a, int b) {
	if (a > b) printf("Å‘å’lF%d\n", a);
	else printf("Å‘å’lF%d\n", b);

}

int getMax(int a, int b) {
	if (a > b)return a;
	else return b;
}

void printCalcArea(double r) {
	double rs;
	rs = r * r * 3.141592;
	printf("”¼Œa%0.3f‚Ì‰~‚Ì–ÊÏ‚Í%0.6f‚Å‚·\n", r, rs);

}

double calcArea(double r) {
	double s;
	s = r * r * 3.141592;
	return s;
}

int isEven(int num) {
	if (num % 2 == 0) return 1;
	else return 0;
}

double calcAverage(int num1, int num2, int num3) {
	double result;
	return result = (num1 + num2 + num3) / 3;
}

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}