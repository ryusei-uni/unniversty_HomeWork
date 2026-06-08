#include < stdio.h>
int calcTotal(int[], int);
int main(void) {

    int scores[5][3] = {
    {80, 72, 88},
    {65, 90, 74},
    {92, 85, 91},
    {50, 63, 58},
    {77, 68, 82}
    };

    for (int i = 0; i < 5; i++) {
        printf("¶“k%d: ‘Œê = %d ”Šw = %d ‰pŒê: %d ‡Œv = %d •½‹Ï = %.1f\n",
            i,
            scores[i][0],
            scores[i][1],
            scores[i][2],
            calcTotal(scores[i],3),
            (double) calcTotal(scores[i], 3)/3
        );
    }

	return 0;
}
int calcTotal(int row[], int n) {
    int Total = 0;
    for (int i = 0; i < n; i++) {
        Total += row[i];
    }
    return Total;
}