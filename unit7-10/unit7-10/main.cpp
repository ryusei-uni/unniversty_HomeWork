#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "Programming";
	char Hello[20] = "Hello";
	char world[] = "World";
	printf("•¶š—ñ‚Ì’·‚³F@%zu\n", strlen(str));

	if (strcmp(str, "Programming")==0) printf("“¯‚¶\n");
	else printf("ˆá‚¤");
	strcat_s(Hello, sizeof(Hello), world);
	printf("%s\n",Hello);

	return 0;
}