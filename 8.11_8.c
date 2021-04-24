#include<stdio.h>
char get_choice(void);
void intro(void);
void get_float(float* n);
int main() {
    char choice;
    float x, y;
    intro();
    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a':
                printf("Enter the first number: ");
                get_float(&x);
                printf("Enter the second number: ");
                get_float(&y);
                printf("%.2f + %.2f = %.2f\n", x, y, x + y);
                break;
            case 's':
                printf("Enter the first number: ");
                get_float(&x);
                printf("Enter the second number: ");
                get_float(&y);
                printf("%2.f - %2.f = %.2f\n", x, y, x - y);
                break;
            case 'm':
                printf("Enter the first number: ");
                get_float(&x);
                printf("Enter the second number: ");
                get_float(&y);
                printf("%.2f * %.2f = %.2f\n", x, y, x * y);
                break;
            case 'd':
                printf("Enter the first number: ");
                get_float(&x);
                printf("Enter the second number: ");
                get_float(&y);
                while (y == 0) {
                    printf("Enter a number other than 0: ");
                    scanf("%f", &y);
                }
                printf("%.2f / %.2f = %.2f\n", x, y, x / y);
                break;
            default:
                printf("Please respond with a, s, m, d, q\n");
                break;
        }
        intro();
    }
    printf("Bye!");
    return 0;
}
void intro(void) {
    printf("Enter the operation of your choice:\n");
    printf("a.add           s.subtract\n");
    printf("m.multiply      d.divide\n");
    printf("q.quit\n");
}
char get_choice(void) {
    int ch;
    while (1) {
        if ((ch = getchar()) > ' ') {
            break;
        }
    }
    while (getchar() != '\n') {
        continue;
    }
    return ch;
}

void get_float(float* n) {
    char ch;
    while (scanf("%f", n) != 1) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        printf(" is not a number.\n");
        printf("Please enter a number , such as 2.5, -1.78E8, or 3: ");
    }
}