#include<stdio.h>
void copy_arr(double arr[], double source[], int n);
void copy_ptr(double *arr, double *source, int n);
void copy_ptrs(double *arr, double *source, double *arr_end);
int main() {
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    int i;
    for (i = 0; i < 5; i++) {
        printf("%f ", target1[i]);
    }
    putchar('\n');
    for (i = 0; i < 5; i++) {
        printf("%f ", target2[i]);
    }
    putchar('\n');
    for (i = 0; i < 5; i++) {
        printf("%f ", target3[i]);
    }
    putchar('\n');

    return 0;
}

void copy_arr(double arr[], double source[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = source[i];
    }
} 

void copy_ptr(double *arr, double *source, int n) {
    int i;
    for (i = 0; i < n; i++) {
        *(arr + i) = *(source + i);
    }
}

void copy_ptrs(double *arr, double *source, double *arr_end) {
    while (source < arr_end) {
        *(arr++) = *(source++);
    }
}