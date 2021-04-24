#include<stdio.h>
#define M_PER_H 60
int main() {
    printf("Please enter time in minutes (<=0 to quit)\n");
    int time, hour, min;
    scanf("%d", &time);
    while (time > 0) {
        hour = time / 60;
        min = time % 60;
        printf("It's %d hours %d minutes\n", hour, min);
        scanf("%d", &time);
    }
    return 0;
}