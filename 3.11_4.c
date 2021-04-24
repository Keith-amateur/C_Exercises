#include<stdio.h>
// 先打印小数形式 再打印成指数形式 p进制形式
int main() {
    float test_f;
    printf("Enter a floating_point value:\n");
    scanf("%f", &test_f);
    printf("fixed_point notation: %f\n", test_f);
    printf("exponential notation: %e\n", test_f);
    printf("p notation:%a\n", test_f);

    return 0;
}