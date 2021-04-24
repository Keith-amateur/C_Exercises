#include<stdio.h>
#define LIMITS1 17850
#define LIMITS2 23900
#define LIMITS3 29750
#define LIMITS4 14875
#define RATE1 0.15
#define RATE2 0.28

int main() {
    int limit;
    printf("请输入缴纳税金的种类:\n");
    printf("1.单身      2.户主      3.已婚, 共有        4.已婚, 离异        5.退出\n");
    char class;
    while ((class = getchar()) != '5') {
        switch (class) {
            case '1':
                limit = LIMITS1;
                break;
            case '2':
                limit = LIMITS2;
                break;
            case '3':
                limit = LIMITS3;
                break;
            case '4':
                limit = LIMITS4;
                break;
            case '\n':
                continue;
                break;
            default:
                printf("请输入正确的选项:\n");
                continue;
                break;
        }
        float salary, tax;
        printf("请输入应纳税收入:\n");
        scanf("%f", &salary);
        if (salary > limit) {
            tax = limit * RATE1 + (salary - limit) * RATE2;
        } else {
            tax = salary * RATE1;
        }
        printf("应缴纳%.2f元", tax);
        printf("\n请输入缴纳税金的种类:\n");
        printf("1.单身      2.户主      3.已婚, 共有        4.已婚, 离异        5.退出\n");
    }
    return 0;
}