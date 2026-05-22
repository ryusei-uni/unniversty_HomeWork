#include <stdio.h>

int isEven(int n) {
    return n % 2 == 0;
}
int main(void) {
    printf("%d\n", isEven(7));
    return 0;
}