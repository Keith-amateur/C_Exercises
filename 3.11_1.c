#include<stdio.h>
#include<float.h>
#include<limits.h>
int main() {
    int big_int = 2147483647; // int类型的最大值2 ^ 31 - 1
    float big_float = 3.4e38; // float最大值一般为3.4e38
    float small_float = 10.0 / 3; // float的有效位数为6位
    printf("整型越界big_int + 1 = %d\n", big_int + 1);
    printf("浮点型上溢%f\n", big_float * 10);
    printf("浮点数下溢%f\n", small_float); // 精度损失
    printf("The max float data is %f\n", FLT_MAX);
    printf("The max int data is %ld\n", INT_MAX);

    return 0;
}