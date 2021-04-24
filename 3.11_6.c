#include<stdio.h>
#define MASS_PER_MOLE 3e-23
#define MASS_PER_QUART 950
// 输入水的夸克数 计算水分子的数量
int main() {
    int num1;
    scanf("%d", &num1);
    double num2 = num1 * MASS_PER_QUART / MASS_PER_MOLE;
    printf("水分子的数量:%f", num2);

    return 0;
}