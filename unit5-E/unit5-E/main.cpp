#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comput_game() {
	srand((unsigned int)time(NULL));
	int c, r;
	int  int_arr[2] = { 0,0 };
	r = rand() % 4 + 1;
	for (int i = 0; i < 2; i++) {
		int_arr[i] = rand() % 1000 + 1;
	}

	switch (r) {

	case 1:
		while (true) {
			printf("%d + %d = ", int_arr[1], int_arr[0]);
			scanf_s("%d", &c);
			printf("%d + %d = %d", int_arr[1], int_arr[0], c);
			if (c == int_arr[1] + int_arr[0]) {
				printf("\n正解");
				break;
			}
			else {
				printf("\n間違え！");
			}
		}
		break;

	case 2:
		printf("%d - %d = ", int_arr[1], int_arr[0]);
		while (true) {
			scanf_s("%d", &c);
			printf("%d - %d = %d", int_arr[1], int_arr[0], c);
			if (c == int_arr[1] - int_arr[0]) {
				printf("\n正解");
				break;
			}
			else {
				printf("\n間違え！");
			}
		}
		break;
	case 3:
		while (true) {
			printf("%d * %d = ", int_arr[1], int_arr[0]);
			scanf_s("%d", &c);
			printf("%d * %d = %d", int_arr[1], int_arr[0], c);
			if (c == int_arr[1] * int_arr[0]) {
				printf("\n正解");
				break;
			}
			else {
				printf("\n間違え！");
			}
		}
		break;
	case 4:
		while (true) {
			printf("%d / %d = ", int_arr[1], int_arr[0]);
			scanf_s("%d", &c);
			printf("%d / %d = %d", int_arr[1], int_arr[0], c);
			if (c == int_arr[1] / int_arr[0]) {
				printf("\n正解");
				break;
			}
			else {
				printf("\n間違え！");
			}
		}
		break;
	}

	return 0;
}

int main(void) {
	comput_game();
	return 0;
}