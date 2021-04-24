#include <stdio.h>
#define OPTIONS 4

void afunc(void);
void bfunc(void);
void cfunc(void);
void dfunc(void);

int main() {
    typedef void (*pfunc)(void);
    pfunc funcarr[OPTIONS] = {afunc, bfunc, cfunc, dfunc};
    char opt;
    puts("Enter a, b, c or d to choose the function you want to use.(q to quit)");
    while ((opt = getchar()) != 'q') {
        switch (opt) {
            case 'a':
                funcarr[0]();
                break;
            case 'b':
                funcarr[1]();
                break;
            case 'c':
                funcarr[2]();
                break;
            case 'd':
                funcarr[3]();
                break;
            default:
                printf("ERROR INPUT\n");
                break;
        }
        while (getchar() != '\n') {
            continue;
        }
    }
    printf("Bye!\n");
    return 0;
}

void afunc(void) {
    puts("You chose \'a\'.");
}
void bfunc(void) {
    puts("You chose \'b\'.");
}
void cfunc(void) {
    puts("You chose \'c\'.");
}
void dfunc(void) {
    puts("You chose \'d\'.");
}