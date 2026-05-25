#include <stdio.h>

int add(int a, int b);

int main(void) {
    printf("%d\n", add(1, 2));   // © ˆø”‚ª3‚Â
    return 0;
}

// ’è‹`iˆø”‚ª2‚Âj
int add(int a, int b) {
    return a + b;
}