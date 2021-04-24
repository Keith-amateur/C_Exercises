#include<stdio.h>
#define RANK1 8.75
#define RANK2 10.00
#define RANK3 9.33
#define RANK4 11.20
#define TAX_RATE1 0.15
#define TAX_RATE2 0.2
#define TAX_RATE3 0.25
void calc_salary(float pay_rate, float hours);
int main() {
    char num;
    float pay_rate;
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $%.2f/hr  2) $%.2f/hr 3)$%.2f/hr 4)%.2f/hr 5)quit\n", RANK1, RANK2, RANK3, RANK4);
    while ((num = getchar()) != '5') {
        switch (num) {
            case '1':
                pay_rate = RANK1;
                break;
            case '2':
                pay_rate = RANK2;
                break;
            case '3':
                pay_rate = RANK3;
                break;
            case '4':
                pay_rate = RANK4;
                break;
            case '\n':
                continue;
                break;
            default:
                printf("Please enter the correct option\n");
                continue;
                break;
        }
        float hours;
        printf("Enter the number of hours:\n");
        scanf("%f", &hours);
        calc_salary(pay_rate, hours);
        printf("\n\nEnter the number corresponding to the desired pay rate or action:\n");
        printf("1) $%.2f/hr  2) $%.2f/hr 3)$%.2f/hr 4)%.2f/hr 5)quit\n", RANK1, RANK2, RANK3, RANK4);
    }
    return 0;
}

void calc_salary(float pay_rate, float hours) {
    float salary, tax, r_salary;
    if (hours > 40) {
        hours *= 1.5;
        salary = pay_rate * hours;
    } else {
        salary = pay_rate * hours;
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
}