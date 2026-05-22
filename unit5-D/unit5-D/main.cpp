#include <stdio.h>
#include <math.h>
//上向き三角の星を表示する
int starn() {
	int n;
	printf("整数を入力：");
	scanf_s("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			printf("★ ");
		}
		printf("\n");
	}
	return 0;
}

//下向き三角の星を表示する
int starns(){
	int n;
	printf("整数を入力：");
	scanf_s("%d", &n);
	for (int i = 0; i <= n; i++) {
		for (int j = n; j > i; j--) {
			printf("★ ");
		}
			printf("\n");
	}
	return 0;
	}

//奇数と偶数をカウントする
int odd_even() {
	int n,even=0,odd=0;
	for (int i = 1; i <= 5; i++) {
		printf("%d番目：",i);
		scanf_s("%d", &n);
		if (n % 2 == 0) even++;
		else odd++;
	}
	printf("偶数：%d 奇数：%d", even, odd);
	return 0;
}
//素数判定
int pnumg(int n) {
	int a = 0;
	if (n < 2) printf("素数じゃない");
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			a = 1;
			break;
		}
	}
	if (a == 1) {
		printf("%d,素数ではありません", n);
	}
	else if (a == 0) {
		printf("%d,これは素数です", n);

	}
	return 0;
}
//任意のが数,素数判定
int pnum() {

	int n;
	printf("整数を入力：");
	scanf_s("%d", &n);
	pnumg(n);
		
	return 0;
}
//1〜100 の素数をすべて表
int pnum_h() {
	int k = 0;
	printf("2 ");
	for (int i = 3; i <= 100; i+=2) {
		k = 0;
		for (int j = 3; j <=sqrt(i); j += 2) {
			if (i % j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
int main(void) {
	
	printf("星三角上\n");
	starn();
	printf("\n");
	printf("星三角下\n");
	starns();
	printf("\n");
	printf("偶数奇数カウンタ\n");
	odd_even();
	printf("\n");
	printf("素数判定\n");
	pnum();
	printf("\n");
	printf("1から100 の素数をすべて表示");
	pnum_h();
	printf("\n");

	return 0;
}