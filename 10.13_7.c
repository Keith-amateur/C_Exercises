#include<stdio.h>
#define ROWS 3
#define COLS 4
void copy_arr(double arr[], double source[], int n);
void copy_arr2D(double (*arr)[COLS], double (*source)[COLS], int row);
int main() {
    double arr[ROWS][COLS];
    double new_arr1[ROWS][COLS];
    double new_arr2[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = 1.0;
            printf("%.2f ", arr[i][j]);
        }
        putchar('\n');
    }
    printf("------------copy1----------------\n");
    int z;
    for (z = 0; z < ROWS; z++) {
        copy_arr(new_arr1[z], arr[z], COLS);
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%.2f ", new_arr1[i][j]);
        }
        putchar('\n');
    }

        printf("------------copy2----------------\n");
    copy_arr2D(new_arr2, arr, ROWS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%.2f ", new_arr2[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
void copy_arr(double arr[], double source[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = source[i];
    }
} 

void copy_arr2D(double (*arr)[COLS], double (*source)[COLS], int row) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] = source[i][j];
        }
    }
}