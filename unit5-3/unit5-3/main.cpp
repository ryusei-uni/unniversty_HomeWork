#include <stdio.h>

int main(void) {
	int i = 1;

	while (i <= 10) {
		printf("%d\n",i);
		++i;
	}
	printf("\n");
	int l = 10;
	while (l >= 1) {
		printf("%d\n", l);
		--l;
	}
}