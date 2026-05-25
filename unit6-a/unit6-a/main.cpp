#include <stdio.h>

int calcTotal(int, int);
void printTotal(int,int);

char getGrade(int);
int isBetween(int, int, int);

int main(void) {
	printTotal(500, 3);
	printTotal(1200, 2);
	printf("%d点です。スコア：%c\n",95 ,getGrade(95));
	printf("%d点です。スコア：%c\n",72 ,getGrade(72));
	printf("%d点です。スコア：%c\n", 43, getGrade(43));
	
	printf("%d\n", isBetween(50, 25, 90));
	printf("%d\n", isBetween(11, 25, 90));
}


int calcTotal(int price, int quantity) {
	return price * quantity;
}

void printTotal(int price, int quantity) {
	printf("%d円を%d個で合計金額: %d円です。\n", price,quantity,calcTotal(price,quantity));
	
}

char getGrade(int score) {
	if (score >= 90) {
		return 'S';
	}
	else if(score >=70) {
		return 'A';
	}
	else if (score >= 50) {
		return 'B';
	}
	else {
		return 'C';
	}
}

int isBetween(int val, int lo, int hi) {
	if (lo <= val && val <= hi) {
		return 1;
	}
	else {
		return 0;
	}
}