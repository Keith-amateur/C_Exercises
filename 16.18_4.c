#include <stdio.h>
#include <time.h>

void loop_in_time(double time);

int main() {
    loop_in_time(0.1);
    return 0;
}

void loop_in_time(double time) {
    time_t now = clock();
    int count = 0;
    while (1) {
        puts("Hello");
        count++;
        if ((clock() - now) / (double) CLOCKS_PER_SEC >= time) {
            break;
        }
    }
    printf("The loop has run %d times", count);
}