#include<stdio.h>
#include<string.h>

#define SIZE 80

void trim(char *str);
char *s_gets(char *st, int n);

int main() {
    char str[SIZE];
    puts("Enter:");
    while (s_gets(str, SIZE) && str[0] != '\0') {
        trim(str);
        puts(str);
        puts("Enter the next str:");
    }
    puts("Bye!");
    return 0;
}

void trim(char *str) {
    if (!strchr(str, ' ')) {
        return;
    }
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            str[i] = '\0';
            strcat(str, &str[i + 1]);
        }
        i++;
    }
    trim(str);
}

char *s_gets(char *st, int n) {
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}