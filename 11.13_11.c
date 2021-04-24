#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LEN 10
#define SIZE 80

char **sortbyASCII(char **strs, int n);
char **sortbylength(char **strs, int n);
char **sortby1stword(char **strs, int n);
int findWord(char *str);
char *s_gets(char *str, int n);
void multiputs(char **strs, int n);

int main() {
    char strs_container[LEN][SIZE];
    char *strs[LEN];
    int i = 0;
    puts("Enter:");
    while (i < LEN && s_gets(strs_container[i], SIZE)) {
        strs[i] = strs_container[i];
        i++;
    }
    char ch;
    puts("Sorting strings:");
    puts("---------------------------");
    printf("a) sorting by ASCII\nb) sorting by length\nc) sorting by 1stword\nq) quit\n");
    puts("---------------------------");
    putchar('\n');
    char **ptr;
    while ((ch = getchar()) != 'q') {
        switch (ch) {
            case 'a':
                ptr = sortbyASCII(strs, i);
                multiputs(ptr, i);
                break;
            case 'b':
                ptr = sortbylength(strs, i);
                multiputs(ptr, i);
                break;
            case 'c':
                ptr = sortby1stword(strs, i);
                multiputs(ptr, i);
                break;
            default:
                puts("Please enter the correct option!");
                break;
        }
        while (getchar() != '\n') {
            continue;
        }
        printf("a) sorting by ASCII\nb) sorting by length\nc) sorting by 1stword\nq) quit\n");
    }
}

char **sortbyASCII(char **strs, int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(strs[i], strs[j]) > 0) {
                temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
    }
    return strs;
}

char **sortbylength(char **strs, int n) {
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strlen(strs[j]) > strlen(strs[j + 1])) {
                temp = strs[j];
                strs[j] = strs[j + 1];
                strs[j + 1] = temp;
            }
        }
    }
    return strs;
}

char **sortby1stword(char **strs, int n) {
    int i, j;
    char *temp;
    int arr[n];
    int z;
    for (z = 0; z < n; z++) {
        arr[z] = findWord(strs[z]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = strs[i];
                strs[i] = strs[j];
                strs[j] = temp;
            }
        }
    }
    return strs;
}

int findWord(char *str) {
    int i = 0;
    int inword = 0;
    int flag = 0;
    int count = 0;
    while (str[i] != '\0') {
        if (toupper(str[i]) >= 65 && toupper(str[i]) <= 90) {
            inword = 1;
            count++;
            flag = 1;
        } else {
            inword = 0;
        }
        if (flag && !inword) {
            break;
        }
        i++;
    }
    return count;
}

char *s_gets(char *str, int n) {
    char *st;
    int i = 0;
    st = fgets(str, n, stdin);
    if (st) {
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
    return st;
}

void multiputs(char **strs, int n) {
    putchar('\n');
    int i;
    for (i = 0; i < n; i++) {
        puts(strs[i]);
    }
}