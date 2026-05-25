#include <stdio.h>

// 目的: a と b の値を交換したい
void swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int x = 10, y = 20;
    swap(x, y);
    printf("x=%d, y=%d\n", x, y);   // x=10, y=20 のまま…
    return 0;
}

//値渡しをしているだけで返されていないため