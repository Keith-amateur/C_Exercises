#include<stdio.h>

int main() {
    int num;
    int even_total, odd_total;
    even_total = odd_total = 0;
    int even_num, odd_num;
    even_num = odd_num = 0;
    scanf("%d", &num);
    while (num != 0) {
        if (num % 2 == 0) {
            even_num++;
            even_total += num;
        } else {
            odd_num++;
            odd_total += num;
        }
        scanf("%d", &num);
    }
    printf("#even number    #even average   #odd number    #odd average\n");
    printf("%4d %17.2f %13d %16.2f", 
            even_num, even_total / (float)even_num, odd_num, odd_total / (float)odd_total);
    return 0;
}