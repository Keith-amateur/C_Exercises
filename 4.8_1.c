#include<stdio.h>

int main() {
    char first_name[40];
    char family_name[40];
    printf("Please enter your first name and family name:\n");
    scanf("%s %s", first_name, family_name);
    printf("%s,%s", first_name, family_name);
    return 0;
}