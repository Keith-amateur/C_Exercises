#include<stdio.h>
void copy_arr(double arr[], double source[], int n);
int main() {
    double arr[7] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0};
    double new_arr[3];
    copy_arr(new_arr, &arr[2], 3);
    int i;
    for (i = 0; i < 7; i++) {
        printf("%.2f ", arr[i]);
    }
    putchar('\n');
    for (i = 0; i < 3; i++) {
        printf("%.2f ", new_arr[i]);
    }
    return 0;
}

void copy_arr(double arr[], double source[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = source[i];
    }
} 