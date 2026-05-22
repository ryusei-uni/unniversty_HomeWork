#include <stdio.h>

int main(void) {

	for (int i = 0; i <= 20; ++i) {
		if (i == 13) break;
		printf("%d\n",i);
	}
	printf("__________________________________\n");

	for (int i = 0; i <= 20; ++i) {
		if (i % 3 == 0) continue;
		printf("%d\n", i);
	}
	return 0;
}