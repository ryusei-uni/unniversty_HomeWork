//#include <stdio.h>
//
//int g = 10; //グローバル変数ｇの定義(10)
//
//void show(void) {
//	int g = 99;
//	// 書き方の例（コメントで説明する）
//	printf("show の g = %d\n", g);   // → ローカル変数の g が表示される (99)
//}
//
//void countStatic(void) {
//	static int n = 0;
//	n++;
//	printf("static あり: %d\n", n);
//}
//
//void countLocal(void) {
//	int n = 0;
//	n++;
//	printf("static なし: %d\n", n);
//}
//
//int main(void) {
//
//	countLocal();
//	printf("\n");
//	countLocal();
//	printf("\n");
//	countLocal();
//	printf("\n");
//
//	countStatic();
//	printf("\n");
//	countStatic();
//	printf("\n");
//	countStatic();
//	printf("\n");
//
//	show();
//	printf("\n");
//	printf("グローバル変数 g = %d\n", g); //グローバル変数のｇが表示される(10)
//	printf("\n");
//
//	return 0;
//}
//
#include <stdio.h>

int main(void) {
    int count;
    for (int i = 0; i < 5; i++) {
        printf("ループ中: i = %d\n", i);
        count = i;
    }
    printf("終了後: i = %d\n", count);   // ← エラー
    return 0;
}