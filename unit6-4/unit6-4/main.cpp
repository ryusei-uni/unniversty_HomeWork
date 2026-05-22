#include <stdio.h>

void printMax(int a, int b) {
	if (a > b) printf("最大値：%d\n", a);
	else printf("最大値：%d\n", b);
	
}

int getMax(int a, int b) {
	if (a > b)return a;
	else return b;
}

void printCalcArea(double r) {
	double rs;
	rs = r * r * 3.141592;
	printf("半径%0.3fの円の面積は%0.6fです\n", r, rs);

}

double CalcArea(double r) {
	double s;
	s = r * r * 3.141592;
	return s;
}

int main(void) {
	
	int result = getMax(10, 5);
	printf("最大値: %d\n", result);

	double s = CalcArea(5);
	printf("円の面積：%0.5f", s);


	return 0;
}