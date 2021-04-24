#include<stdio.h>
#define D_PER_W 7
int main() {
    int all_days;
    int weeks, days;
    printf("Please enter the number of days(<=0 to quit):\n");
    scanf("%d", &all_days);
    while (all_days > 0) {
        weeks = all_days / 7;
        days = all_days % 7;
        printf("%d days are %d weeks, %d days\n", all_days, weeks, days);
        scanf("%d", &all_days);
    }
    return 0;
}