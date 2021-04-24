#include<stdio.h>
void sort_double(double arr[], int n);
int main() {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 4.5, 5.0, 6.0, 7.0};
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    putchar('\n');
    sort_double(arr, n);
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    return 0;
}

void sort_double(double arr[], int n) {
    int i;
    double t;
    for (i = 0; i < n / 2; i++) {
        t = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = t;
    }
}