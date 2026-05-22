#include <stdio.h>
int main(void) {
	//数値の初期化
	int input_num, sum=0,count=0;
	
	// ユーザーからのインプット
	printf("整数を入力（０で終了）：　");
	scanf_s("%d",&input_num);
		

	while (input_num != 0) {
	sum += input_num;
	count++;
	
	// ユーザーからのインプット
	printf("整数を入力（０で終了）：　");
	scanf_s("%d",&input_num);

	
	}
	printf("合計：　%d\n", sum);
	printf("個数： %d\n", count);

	return 0;
}