#include<stdio.h>
void simple_sort(double *a, double *b, double *c);
void exchange(double *m, double *n);
int main() {
    double x, y, z;
    printf("Please enter three numbers: ");
    while (scanf("%lf %lf %lf", &x, &y, &z) != 3) {
        printf("Please enter the number such as 3, 1.2: ");
        scanf("%*s");
    }
    simple_sort(&x, &y, &z);
    printf("After sorting, the three numbers are %.2f, %.2f, %.2f", x, y, z);
    return 0;
}

// void simple_sort(double * a, double * b, double * c) {
//     if (*a > *b) {
//         if (*b > *c) {
//             exchange(a, c);
//         } else if (*c < *a) {
//             exchange(a, c);
//             exchange(a, b);
//         } else {
//             exchange(a, b);
//         }
//     } else {
//         if (*a > *c) {
//             exchange(b, c);
//             exchange(a, b);
//         } else if (*c < *b) {
//             exchange(b, c);
//         } else {
//             ;
//         }
//     }
// }

// 选择排序的思想
void simple_sort(double * a, double * b, double * c) {
    if (*a > *b) {
        exchange(a, b);
    }
    if (*a > *c) {
        exchange(a, c);
    }
    if (*b > *c) {
        exchange(b, c);
    }
}

void exchange(double *m, double *n) {
    double temp;
    temp = *m;
    *m = *n;
    *n = temp;
}