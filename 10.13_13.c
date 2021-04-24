#include<stdio.h>
#define ROWS 3
#define COLS 5
void input_arr(double arr[][COLS], int rows);
double container[ROWS];
double *calc_row_mean(double arr[][COLS], int rows);
double calc_all_mean(double arr[][COLS], int rows);
double find_max(double arr[][COLS], int rows);
int main() {
    double arr[ROWS][COLS];
    input_arr(arr, ROWS);
    double *mean_of_row = calc_row_mean(arr, ROWS);
    double mean_of_all = calc_all_mean(arr, ROWS);
    double max = find_max(arr, ROWS);
    printf("mean of row:  ");
    int i;
    for (i = 0; i < ROWS; i++) {
        printf("%.2f ", *(mean_of_row + i));
    }
    printf("\n");
    printf("mean of all:  %.2f\n", mean_of_all);
    printf("max:  %.2f\n", max);
    return 0;
}

void input_arr(double arr[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
}

double *calc_row_mean(double arr[][COLS], int rows) {
    int i, j;
    double subtotal;
    extern double container[ROWS];
    for (i = 0; i < rows; i++) {
        for (j = 0, subtotal = 0.0; j < COLS; j++) {
            subtotal += arr[i][j];
        }
        container[i] = subtotal / COLS;
    }
    return container;
}

double calc_all_mean(double arr[][COLS], int rows) {
    int i, j;
    double total;
    for (i = 0, total = 0.0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            total += arr[i][j];
        }
    }
    return total / (rows * COLS);
}

double find_max(double arr[][COLS], int rows) {
    int i, j;
    double max;
    for (i = 0, max = arr[0][0]; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    return max;
}