#include<stdio.h>
void arr_add(int arr1[], int arr2[], int res[], int n);
int main() {
    int arr1[] = {2, 4, 5, 8};
    int arr2[] = {1, 0, 4, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int res[n];
    arr_add(arr1, arr2, res, n);
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
void arr_add(int arr1[], int arr2[], int res[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        res[i] = arr1[i] + arr2[i];
    }
}

