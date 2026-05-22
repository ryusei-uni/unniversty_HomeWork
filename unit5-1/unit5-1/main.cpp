#include <stdio.h>

int main(void) {
	const char* A[] = {"りんご","みかん","バナナ","アイス"};
	for(int i = 0; i <= 5;i++) {
		printf("%d\n", i);
	}
	printf("\n");
	int l = 10;
	while (l >= 1) {
		--l;
		printf("%d\n",l);
	}

	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		printf("A[%d] = %s\n",i,A[i]);
	}
}