#include <stdio.h>

int getMax(int[], int);
int getMin(int[], int);

int main(void) {

	int data[5] = { 34,12,78,56,23 };

	printf("最大値は：%d\n", getMax(data, 5));
	printf("最小値は：%d\n", getMin(data, 5));

	return 0;
}


int getMax(int data[],int queue) {
	int max_value = -_CRT_INT_MAX;
	for (int i = 0; i < queue; i++) {
		if (max_value < data[i]) max_value = data[i];

	}
	return max_value;
}

int getMin(int data[], int queue) {
	int min_value = _CRT_INT_MAX;
	for (int i = 0; i < queue; i++) {
		if (min_value > data[i]) min_value = data[i];

	}
	return min_value;
}