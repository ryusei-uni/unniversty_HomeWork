#include <stdio.h>

int main(void) {
	
	int max, min, sum, var,count;
	double avg;
	var = 0;
	max = var;
	min = _CRT_INT_MAX;
	sum = var;
	avg = var;
	count = 0;
	for (int i = 1; i <= 5; i++) {

		printf("%d番目の整数: ", i);
		scanf_s("%d",&var);
		sum += var;
		count = i;
		if (var > max) max = var;
		if (var < min) min = var;
	}
	avg = (double)sum / count;
	printf("合計: %d\n",sum);
	printf("最大値: %d\n",max);
	printf("最小値: %d\n",min);
	printf("平均値: %.2f\n",avg);

	return 0;
}