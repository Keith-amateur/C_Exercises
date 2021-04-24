#include<stdio.h>
#define ROWS 3
#define COLS 5
void show_arr(int arr[][COLS], int rows);
void double_arr(int arr[][COLS], int rows);
int main() {
    int arr[ROWS][COLS] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
    };
    show_arr(arr, ROWS);
    printf("-------------------------\n");
    double_arr(arr, ROWS);
    show_arr(arr, ROWS);
    return 0;   
}

void show_arr(int arr[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        putchar('\n');
    }
}

void double_arr(int arr[][COLS], int rows) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < COLS; j++) {
            arr[i][j] *= 2;
        }
    }
}