#include<stdio.h>

int main() {
    int f_oper, s_oper;
    printf("This program computes moduli.\n");
    printf("Please enter an integer to serve as the second operand: ");
    scanf("%d", &s_oper);
    printf("Now enter the first operation: ");
    scanf("%d", &f_oper);
    printf("%d %% %d is %d\n", f_oper, s_oper, f_oper % s_oper);
    while (s_oper > 0 && f_oper > 0) {
        printf("Enter next number for first operand (<=0 to quit):");
        scanf("%d", &f_oper);
        if (f_oper <= 0)
            break;
        printf("%d %% %d is %d\n", f_oper, s_oper, f_oper % s_oper);

    }
    printf("Done!");
    return 0;
}