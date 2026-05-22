#include <stdio.h>

int main(void) {

	for (int i = 1; i <= 20; ++i) {
		if (!(i % 2 == 0)) {
			printf("%d\n", i);
		}
	}

	printf("\n");


	for (int i = 10; i >= 1; --i) {
		printf("%d\n",i);
	}
	int n;
	int i = 0;
	scanf_s("%d", &n);
	while (i < n) {
		printf("™ ");
		++i;
	}

	return 0;
}