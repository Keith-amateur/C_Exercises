#include<stdio.h>
#include<string.h>
int main() {
    char first_name[20];
    char family_name[20];
    printf("Please enter your name:\n");
    scanf("%s %s", first_name, family_name);
    printf("%s %s\n", first_name, family_name);
    printf("%*d %*d\n", (int)strlen(first_name), (int)strlen(first_name), 
                        (int)strlen(family_name), (int)strlen(family_name));
    printf("%s %s\n", first_name, family_name);
    printf("%-*d %-*d\n", (int)strlen(first_name), (int)strlen(first_name), 
                        (int)strlen(family_name), (int)strlen(family_name));
    return 0;
}