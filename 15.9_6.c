#include <stdio.h>

struct fonts {
    unsigned int ID : 8;
    unsigned int : 0;
    unsigned int size : 7;
    unsigned int : 1;
    unsigned int alignment : 2;
    unsigned int bold : 1;
    unsigned int italic : 1;
    unsigned int underline : 1;
    unsigned int : 3;
};

void show_settings(const struct fonts *pf);
void showmenu(void);
void eatline(void);
int main() {
    struct fonts settings = {0, 12, 0, 0, 0, 0};
    show_settings(&settings);
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
                settings.size = x;
                break;
            case 'f':
                printf("Enter font Id(0-255):");
                int y;
                scanf("%d", &y);
                eatline();
                settings.ID = y;
                break;
            case 'a':
                printf("Select Alignment\n");
                puts("l) left   c) center   r) right");
                char ch = getchar();
                eatline();
                switch (ch) {
                    case 'l':
                        settings.alignment = 0;
                        break;
                    case 'c':
                        settings.alignment = 1;
                        break;
                    case 'r':
                        settings.alignment = 2;
                        break;
                    default:
                        break;
                }
                break;
            case 'b':
                settings.bold ^= 01;
                break;
            case 'i':
                settings.italic ^= 01;
                break;
            case 'u':
                settings.underline ^= 01;
                break;
            default:
                break;
        }
        // eatline();
        show_settings(&settings);
        showmenu();
    }
    puts("Bye!");
    return 0;
}


void show_settings(const struct fonts *pf) {
    printf("%10s %10s %10s %10s %10s %10s\n", "ID", "SIZE", "ALIGNMENT", "B", "I", "U");
    printf("%10d ", pf->ID);
    printf("%10d ", pf->size);
    switch (pf->alignment) {
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
    printf("%10s ", pf->bold ? "on" : "off");
    printf("%10s ", pf->italic ? "on" : "off");
    printf("%10s ", pf->underline ? "on" : "off");
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