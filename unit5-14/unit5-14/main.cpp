#include <stdio.h>

int main(void) {
	int setnum,a= 1,b=0,c;
	printf("€”‚ğ“ü—ÍF@");
	scanf_s("%d", &setnum);
	for (int i = 0; i < setnum; i++) {
		c = a + b;
		a = b;
		b = c;
		printf("%d\n",c);
	}
	
	return 0;
}