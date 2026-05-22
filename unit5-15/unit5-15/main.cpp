#include <stdio.h>

int main(void) {
	
	//”’l‚Ì‰Šú‰»;
	int input_num, result;
	printf("³‚Ì®”‚ğ“ü—ÍF@");
	scanf_s("%d", &input_num);

	while (true) {
		if (input_num % 2 == 0) {
			result = input_num / 2;
		}
		else {
			result = input_num * 3 + 1;
		}
		printf("%d", result);
		if (result == 1) break;
	}
	
	return 0;
}