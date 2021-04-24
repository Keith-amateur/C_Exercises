#include<stdio.h>
int return_max_index(double arr[], int n);
int main() {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 9.0, 7.0};
    printf("The index of the biggest number in arr: %d",
    return_max_index(arr, sizeof(arr) / sizeof(arr[0])));


    return 0;
}

int return_max_index(double arr[], int n) {
    int i;
    double max;
    int imax;
    for (i = 0, max = arr[0], imax = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            imax = i;
        }
    }
    return imax;
}