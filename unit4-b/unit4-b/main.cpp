#include <stdio.h>

int main(void) {
    int x = 10;
    if (x == 5) {   
        printf("5 ‚Å‚·\n");
    }
    else {
        printf("5 ‚Å‚Í‚ ‚è‚Ü‚¹‚ñ\n");
    }

    int score = 85;
    if (score >= 80) {
        printf("‡Ši\n");
    }
    else if (score >= 60) {   
        printf("ÄŽŽŒ±\n");
    }
    else {
        printf("•s‡Ši\n");
    }

    int a = 10, b = 5;
    if (a >= 5 && b <= 3) {   
        printf("ðŒ‚ð–ž‚½‚·\n");
    }
    else {
        printf("ðŒ‚ð–ž‚½‚³‚È‚¢\n");
    }
}