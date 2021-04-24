#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 8

void PrintSelectedElement(int *arr, int n, int num);
int inArr(int *arr, int n, int val);

int main() {
    int arr[SIZE];
    int i;
    for (i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    PrintSelectedElement(arr, SIZE, 8);

    return 0;
}

void PrintSelectedElement(int *arr, int n, int num) {
    srand((unsigned int)time(0));
    int selected_num[num];
    int i;
    for (i = 0; i < num; i++) {
        selected_num[i] = 9;
    }
    for (i = 0; i < num; i++) {
        int val = rand() % 8;
        while (inArr(selected_num, num, val)) {
            val = rand() % 8;
        }
        selected_num[i] = val;
    }
    for (i = 0; i < num; i++) {
        printf("%d\n", arr[selected_num[i]]);
    }
}

int inArr(int *arr, int n, int val) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            return 1;
        }
    }
    return 0;
}