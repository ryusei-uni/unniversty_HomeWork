#include <stdio.h>

int main(void) {
	double pi = 3.14159;
	printf(" pi = %0.1f\n pi = %0.3f\n pi = %0.5f\n" ,pi,pi,pi);
	int a = 10;
	int b = 3;
	int resulta = a / b;
	int resultb = a % b;
	printf("%d ÅÄ %d = %d ó]ÇË %d \n",a,b,resulta,resultb);


	char item_apple[] = "ÇËÇÒÇ≤";
	int apple_velue = 150;
	float apple_weight = 0.3;
	char item_orange[] = "Ç›Ç©ÇÒ";
	int orange_velue = 1200;
	float orange_weight = 0.5;
	printf("è§ïiñº:  %s / âøäi: %4dâ~ / èdó : %0.1fkg\n",item_apple, apple_velue, apple_weight);
	printf("è§ïiñº:  %s / âøäi: %dâ~ / èdó : %0.1fkg\n",item_orange, orange_velue, orange_weight);


}