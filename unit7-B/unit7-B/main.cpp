#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned)time(NULL));   // シードを現在時刻で設定（毎回異なる列になる）

    for (int i = 0; i < 5; i++) {
        int dice = rand() % 6 + 1;   // 1?6 の乱数
        printf("サイコロ: %d\n", dice);
    }
    return 0;
}