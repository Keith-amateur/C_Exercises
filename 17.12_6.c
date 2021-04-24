#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int BinarySearch(int *arr, int n, int num);
int comp(const void *num1, const void *num2);
int main() {
    srand((unsigned int)time(0));
    int n = 10;
    int i;
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    qsort(arr, n, sizeof(int), comp);
    puts("The number(1 - 100) you want to find:");
    int num;
    while (scanf("%d", &num) == 1) {
        if (BinarySearch(arr, n, num)) {
            printf("%d found", num);
            break;
        }
        puts("Not found. Enter the next number");
    }
}

int BinarySearch(int *arr, int n, int num) {
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (num > arr[mid]) {
            lo = mid + 1;
        } else if (num < arr[mid]) {
            hi = mid - 1;
        } else {
            return 1;
        }
    }
    return 0;
}

int comp(const void *num1, const void *num2) {

    const int *n1 = (const int *)num1;
    const int *n2 = (const int *)num2;
    if (*n1 > *n2) {
        return 1;
    } else if (*n1 < *n2) {
        return -1;
    } else {
        return 0;
    }
}