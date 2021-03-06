#include<stdio.h>
#define YEARS 5
#define MONTHS 12
float calc_year_average(const float rain[][MONTHS], int years);
float *calc_month_average(const float rain[][MONTHS], int years);
float arr[MONTHS];  // 全局变量   作为返回值
int main() {
    const float rain[YEARS][MONTHS] =
        {
            {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
            {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
            {9.1, 8.5, 6.7, 4.3, 2.1, 0.5, 0.2, 0.2, 1.1, 2.3, 6.1, 6.4},
            {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
            {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2},
        };
    float year_average = calc_year_average(rain, YEARS);
    float *month_average = calc_month_average(rain, YEARS);
    printf("The yearly average is %.1f inches.\n", year_average);
    printf("Monthly averages:\n\n");

    printf("  Jan  FEb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  ");
    printf("Nov  Dec\n");
    int i;
    for (i = 0; i < MONTHS; i++) {
        printf("%5.1f", *(month_average + i));
    }
    return 0;
}

float calc_year_average(const float rain[][MONTHS], int years) {
    int year, month;
    float subtot, total;
    for (year = 0, total = 0; year < YEARS; year++) {
        for (month = 0, subtot = 0; month < MONTHS; month++) {
            subtot += rain[year][month];
        }
        printf("%5d  %15.1f\n", 2010 + year, subtot);
        total += subtot;
    }
    return total / YEARS;
}

float *calc_month_average(const float rain[][MONTHS], int years) {
    int year, month;
    float subtotal;
    extern float arr[MONTHS];
    for (month = 0; month < MONTHS; month++) {
        for (year = 0, subtotal = 0; year < YEARS; year++) {
            subtotal += rain[year][month];
        }
        arr[month] = subtotal / YEARS;
    }
    return arr;
}