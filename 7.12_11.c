#include<stdio.h>
#define PRICE1 2.05
#define PRICE2 1.15
#define PRICE3 1.09
float calc_fee(int weight1, int weight2, int weight3, double* all_price, double* transport_fee);
int main() {
    int weight1, weight2, weight3;
    weight1 = weight2 = weight3 = 0;
    printf("请输入a,b,c来分别输入三种蔬菜的磅数:\n");
    char alphabet;
    while ((alphabet = getchar()) != 'q') {
        switch (alphabet) {
            case 'a':
                printf("Input: ");
                scanf("%d", &weight1);
                break;
            case 'b':
                printf("Input: ");
                scanf("%d", &weight2);
                break;
            case 'c':
                printf("Input: ");
                scanf("%d", &weight3);
                break;
            case '\n':
                continue;
                break;
            default:
                printf("请输入正确的选项:\n");
                continue;
                break;
        }
        
    }
    float all_fee;
    double all_price = 0;
    double transport_fee = 0;
    all_fee = calc_fee(weight1, weight2, weight3, &all_price, &transport_fee);
    printf("物品售价: %.2f %.2f %.2f\t订购的重量: %d\t订购的蔬菜费用: %.2f\t折扣: %.2f\t 运费和包装费: %.2f\t所有的费用总额:%.2f", 
                PRICE1, PRICE2, PRICE3, (weight1 + weight2 + weight3), all_price, (all_price > 100) ? all_price * 0.05 : 0,
                transport_fee, all_fee);
    return 0;
}

float calc_fee(int weight1, int weight2, int weight3, double* all_price, double* transport_fee) {
    int all_weights;
    all_weights = weight1 + weight2 + weight3;
    *all_price = PRICE1 * weight1 + PRICE2 * weight2 + PRICE3 * weight3;
    float discount = 0;
    if (*all_price > 100) {
        discount = *all_price * 0.05;
    }
    if (all_weights <= 5) {
        *transport_fee = 6.5;
    } else if (all_weights > 5 && all_weights <= 20) {
        *transport_fee = 14.0;
    } else if (all_weights > 20) {
        *transport_fee = 14 + (all_weights - 20) * 0.5;
    }
    return (*all_price - discount) + *transport_fee;
}