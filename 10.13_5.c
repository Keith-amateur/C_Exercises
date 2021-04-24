#include<stdio.h>
double return_difference(double arr[], int n);
int main() {
    double arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    printf("The difference of the biggest and the smallest value in arr is: %.2f",
           return_difference(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}

double return_difference(double arr[], int n) {
    int i;
    double max, min;
    for (i = 0, max = arr[0], min = arr[0]; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }
    return max - min;
}