#include <stdio.h>
#include <string.h>
int main(void) {
	char names[5][20] = {
		{"Tanaka"},
		{"Hayashi"},
		{"Sato"},
		{"Suzuki"},
		{"Takahashi"}
	};
	char Tempname[20];
	printf("ŒŸõ‚·‚é–¼‘O‚ğ“ü—ÍF ");
	scanf_s("%s",Tempname,sizeof(Tempname));

	for (int i = 0; i < 5; i++) {
		if (strcmp(Tempname, names[i])== 0) {
			printf("%s ‚Í %d”Ô–Ú‚ÉŒ©‚Â‚©‚è‚Ü‚µ‚½B", names[i],i);
			break;
		}
	}

	int kuku[9][9];
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			kuku[i-1][j-1] = i * j;
			printf("%d\n", kuku[i + 1][j + 1]);
		}
	}
	return 0;
}