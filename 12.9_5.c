#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *generate_arr(int n, int range);
void sorted(int *arr, int n);
static int arr[10];
int main() {
    srand((unsigned int)time(0));
    int n = sizeof(arr) / sizeof(int);
    int range = 100;
    generate_arr(n, range);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    sorted(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int *generate_arr(int n, int range) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % range + 1;
    }
    return arr;
}

void sorted(int *arr, int n) {
    int i, j;
    int temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}