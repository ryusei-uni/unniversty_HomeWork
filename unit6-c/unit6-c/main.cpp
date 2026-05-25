#include <stdio.h>
double calcAverage(int, int, int);
char getGrade(double);
void printReport(int, int, int);

int main(void) {
	printReport(80, 65, 90);
	printf("\n");
	printReport(70, 20, 63);
	return 0;
}

double calcAverage(int a, int b, int c) {
	return (double)(a + b + c) / 3;
}

char getGrade(double avg) {
	if (avg >= 90)return 'S';
	else if (avg >= 70) return 'A';
	else if (avg >= 50) return 'B';
	else  return 'C';
}

void printReport(int math, int eng, int sic) {
	double avg = calcAverage(math, eng, sic);
	printf("算数： %d 英語： %d 理科： %d\n", math, eng, sic);
	printf("平均点： %1.1f\n", avg);
	printf("グレード：%c\n", getGrade(avg));
}