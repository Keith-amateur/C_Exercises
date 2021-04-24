#include <stdio.h>

#define MASK1 0xFF
#define MASK2 0xFF00
#define MASK3 0x30000
#define MASK4 0x40000
#define MASK5 0x80000
#define MASK6 0x100000
unsigned long bits;
void showmenu(void);
void show_settings(const unsigned long bits);
void eatline(void);

int main() {
    bits = 0;
    show_settings(bits);
    showmenu();
    char opt;
    while ((opt = getchar()) != 'q') {
        eatline();
        switch (opt) {
            case 's':
                printf("Enter font size(0-127):");
                int x;
                scanf("%d", &x);
                eatline();
                x <<= 8;
                bits &= ~MASK2;
                bits |= x;
                break;
            case 'f':
                printf("Enter font Id(0-255):");
                int y;
                scanf("%d", &y);
                eatline();
                bits &= ~MASK1;
                bits |= y;
                break;
            case 'a':
                printf("Select Alignment\n");
                puts("l) left   c) center   r) right");
                char ch = getchar();
                eatline();
                switch (ch) {
                    case 'l':
                        bits &= ~MASK3;
                        bits |= 0;
                        break;
                    case 'c':
                        bits &= ~MASK3;
                        bits |= (1 << 16);
                        break;
                    case 'r':
                        bits &= ~MASK3;
                        bits |= (2 << 16);
                        break;
                    default:
                        break;
                }
                break;
            case 'b':
                bits ^= (1 << 18);
                break;
            case 'i':
                bits ^= (1 << 19);
                break;
            case 'u':
                bits ^= (1 << 20);
                break;
            default:
                break;
        }
        // eatline();
        show_settings(bits);
        showmenu();
    }
    puts("Bye!");

    return 0;
}

void show_settings(const unsigned long x) {
    printf("%10s %10s %10s %10s %10s %10s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%10lu ", x & MASK1);
    printf("%10lu ", (x & MASK2) >> 8);
    switch ((x & MASK3) >> 16) {
        case 0:
            printf("%10s ", "left");
            break;
        case 1:
            printf("%10s ", "center");
            break;
        case 2:
            printf("%10s ", "right");
            break;
        default:
            puts("Error");
            break;
    }
    printf("%10s ", x & MASK4 ? "true" : "false");
    printf("%10s ", x & MASK5 ? "true" : "false");
    printf("%10s ", x & MASK6 ? "true" : "false");
}



void showmenu(void) {
    putchar('\n');
    puts("f) change font    s) change szie    a) change alignment");
    puts("b) toggle bold    i) toggle italic  u) toggle underline");
    puts("q) quit");
}

void eatline(void) {
    while (getchar() != '\n') {
        continue;
    }
}