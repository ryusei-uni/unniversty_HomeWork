#include <stdio.h>

int main(void) {
	int num;
	printf("®”‚ð“ü—Í: ");
	scanf_s("%d", &num);
	if (num % 2 == 0) {
		printf("%d ‚Í‹ô”‚Å‚·\n",num);
	}
	else{
		printf("%d ‚ÍŠï”‚Å‚·\n",num);
	}

	int score;
	printf("“_”‚ð“ü—Í(0-100): ");
	scanf_s("%d", &score);

	if (score >= 90) {
		printf("S\n");
	}
	else if(score >= 70){
		printf("S\n");
	}
	else if (score >= 50) {
		printf("B\n");
	}
	else {
		printf("C\n");
	}
	int month;
	printf("ŒŽ‚ð“ü—Íi1-12j: ");
	scanf_s("%d", &month);

	if (month >= 3 && month <=6) {
		printf("t\n");
	}
	else if (month >= 6 && month >=9) {
		printf("‰Ä\n");
	}
	else if (month >= 9 && month <= 11) {
		printf("H\n");
	}
	else {
		printf("“~\n");
	}
}