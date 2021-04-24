#include<stdio.h>
#define ROWS 3
#define COLS 5
void copy_arr(double new_arr[][COLS], double arr[][COLS], int row);
void show_arr(int row, int col, double arr[row][col]);
int main() {
    double arr[ROWS][COLS] = {
        {1.0, 1.0, 1.0, 1.0, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0},
    };
    double new_arr[ROWS][COLS];
    show_arr(ROWS, COLS, arr);
    printf("---------------------------------\n");
    copy_arr(new_arr, arr, ROWS);
    show_arr(ROWS, COLS, new_arr);

    return 0;
}
void copy_arr(double new_arr[][COLS], double arr[][COLS], int row) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < COLS; j++) {
            new_arr[i][j] = arr[i][j];
        }
    }
}

void show_arr(int rows, int cols, double arr[rows][cols]) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%.2f  ", arr[i][j]);
        }
        putchar('\n');
    }
}