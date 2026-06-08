#include <stdio.h>
int g_to_L_count = 0;
int g_count = 0;    // グローバル変数（どこからでも見える）

void increment(void) {
    g_count++;      // どの関数からも書き換えられる
}

void reset(void) {
    g_count = 0;    // どの関数からも書き換えられる
}

int main(void) {
    int local = 5;  // ローカル変数（main の中だけ）
    printf("g_to_L_count = %d\n", g_to_L_count);   // 2
    int g_to_L_count = 9;
    increment();
    increment();
    printf("count = %d\n", g_count);   // 2
    printf("g_to_L_count = %d\n", g_to_L_count);   // 2
    return 0;
}