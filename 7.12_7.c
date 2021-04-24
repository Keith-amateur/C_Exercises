#include<stdio.h>
#define TAX_RATE1 0.15
#define TAX_RATE2 0.2
#define TAX_RATE3 0.25
int main() {
    float hours;
    printf("Enter the number of hours:\n");
    scanf("%f", &hours);
    float salary, tax, r_salary;
    if (hours > 40) {
        hours *= 1.5;
        salary = 10 * hours;
    } else {
        salary = 10 * hours;
    }
    if (salary < 300) {
        tax = salary * TAX_RATE1;
    } else if (salary >= 300 && salary < 450) {
        tax = 300 * TAX_RATE1 + (salary - 300) * TAX_RATE2;
    } else if (salary >= 450) {
        tax = 300 * TAX_RATE1 + 150 * TAX_RATE2 + (salary - 450) * TAX_RATE3;
    }
    r_salary = salary - tax;
    printf("salary,    tax,    real salary:\n");
    printf("%4.1f  %8.1f  %8.1f", salary, tax, r_salary);


    return 0;
}