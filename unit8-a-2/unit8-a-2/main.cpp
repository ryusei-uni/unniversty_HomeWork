#include <stdio.h>
int calcSum(int[], int);
int main(void) {
    int data[6] = { 4, 8, 15, 16, 23, 42 };
    int result =  calcSum(data, 6);
    printf("‡Œv: %d\n", result);
    return 0;
}

int calcSum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}