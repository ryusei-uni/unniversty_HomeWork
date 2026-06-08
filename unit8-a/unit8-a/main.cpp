#include <stdio.h>

void scoreTotalcalc(int[] ,int);

int main(void) {

	int scores[5] = { 85,72,90,61,78 };
	scoreTotalcalc(scores, 5);



	return 0;
}

void scoreTotalcalc(int scores[], int arr) {
	int total = 0;
	for (int i = 0; i < arr; i++) {
		total += scores[i];
	}
	printf("‡ŒvF%d\n", total);
	printf("•½‹ÏF%.1f\n", (double)total / arr);
}