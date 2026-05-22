#include <stdio.h>

int main(void) {

	int i = 5;

	int a, b,c,d;

	a = i++;
	printf(" \n a = %d ,i = %d \n",a,i );
	b = ++i;
	printf(" \n b = %d ,i = %d \n", b, i);
	c = i--;
	printf(" \n c = %d ,i = %d \n", c, i);
	d = --i;
	printf(" \n d = %d ,i = %d \n", d, i);

	/*	
		a = i++;
		a = i;
		i++;
	*/
	/*	
	a = ++i;
		i++;
		a = i;
	*/


	return 0;
}

