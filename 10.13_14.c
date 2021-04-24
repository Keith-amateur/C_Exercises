#include<stdio.h>
#define ROWS 3
#define COLS 5
void input_arr(int rows, int cols, double arr[rows][cols]);
double container[ROWS];
double *calc_row_mean(int rows, int cols, double arr[rows][cols]);
double calc_all_mean(int rows, int cols, double arr[rows][cols]);
double find_max(int rows, int cols, double arr[rows][cols]);
int main() {
    double arr[ROWS][COLS];
    input_arr(ROWS, COLS, arr);
    double *mean_of_row = calc_row_mean(ROWS, COLS, arr);
    double mean_of_all = calc_all_mean(ROWS, COLS, arr);
    double max = find_max(ROWS, COLS, arr);
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

void input_arr(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
}

double *calc_row_mean(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    double subtotal;
    extern double container[ROWS];
    for (i = 0; i < rows; i++) {
        for (j = 0, subtotal = 0.0; j < cols; j++) {
            subtotal += arr[i][j];
        }
        container[i] = subtotal / cols;
    }
    return container;
}

double calc_all_mean(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    double total;
    for (i = 0, total = 0.0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            total += arr[i][j];
        }
    }
    return total / (rows * cols);
}

double find_max(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    double max;
    for (i = 0, max = arr[0][0]; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    return max;
}