#include <stdio.h>

void static_countUp(void) {
	static int count = 0;
	count++;
	printf("conut = %d\n", count);
}

void countUp(void) {
	 int count = 0;
	count++;
	printf("conut = %d\n", count);
}

int main(void) {
	printf("Static‚ ‚è\n");
	static_countUp();
	static_countUp();
	static_countUp();
	printf("Static‚È‚µ\n");
	countUp();
	countUp();
	countUp();
	return 0;
}