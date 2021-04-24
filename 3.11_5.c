#include<stdio.h>
#define SEC_PER_YEAR 3.156e7
int main(){
    int age_in_years;
    printf("Please enter your age:\n");
    scanf("%d", &age_in_years);
    double age_in_seconds;
    age_in_seconds = age_in_years * SEC_PER_YEAR;
    printf("%f \n %e", age_in_seconds, age_in_seconds);
    return 0;
}