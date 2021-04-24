#include<stdio.h>

int main() {
    float speed;
    float size;
    printf("Please enter the download speed(Mb/s) and the size of the file(MB):\n");
    scanf("%f %f", &speed, &size);
    float time;
    time = size * 8 / speed;
    printf("At %.2f megabits per seconde, a file of %.2f megabytes\n downloads in %.2f seconds",
           speed, size, time);

    return 0;
}