#include<stdio.h>
int return_max_int(int arr[], int n);
int main() {
    int arr[] = {1, 21, 3, 4, 5, 6, 7};
    printf("The biggest int in array is %d: ", return_max_int(arr, sizeof(arr) / sizeof(arr[0])));
    return 0;
}

int return_max_int(int arr[], int n) {
    int i;
    int max;
    for (i = 0, max = arr[0]; i < n; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}