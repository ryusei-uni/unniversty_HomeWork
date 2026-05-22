#include <stdio.h>

void printMax(int a, int b) {
	if (a > b) {
		printf("最大値：%d\n", a);
	}
	else {
		printf("最大値：%d\n",b);
	}
}

void printCalcArea(double r) {
	double rs;
	rs = r * r * 3.141592;
	printf("半径%0.3fの円の面積は%0.6fです\n",r,rs);
	
}


int main(void) {
	int x = 10, y = 5;
	printMax(x, y);
	printf("x = %d\n", x);
	printCalcArea(y);
	return 0;
}