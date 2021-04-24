#include<stdio.h>
#include<string.h>
#define MAXSIZE 80


char *mystrncpy(char *s1, char *s2, int n);

int main() {
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    puts("Please enter something");
    fgets(s1, MAXSIZE, stdin);
    fgets(s2, MAXSIZE, stdin);
    char *find = strchr(s1, '\n');
    if (find) {
        *find = '\0';
    }
    find = strchr(s2, '\n');
    if (find) {
        *find = '\0';
    }
    char *st;
    st = mystrncpy(s1, s2, 6);
    // st = strncpy(s1, s2, 20);
    puts(st);
    puts(s1);

    return 0;
}

char *mystrncpy(char *s1, char *s2, int n) {
    int len_s1 = 0;
    int len_s2 = 0;
    int z = 0;
    while (s1[z]) {
        len_s1++;
        z++;
    }
    z = 0;
    while (s2[z]) {
        len_s2++;
        z++;
    }
    int i, j;
    if (n > len_s2) {
        for (i = len_s1, j = 0; j < len_s2; i++, j++) {
            s1[i] = s2[j];
        }
    } else {
        for (i = len_s1, j = 0; j < n; i++, j++) {
            s1[i] = s2[j];
        }
        s1[i + 1] = '\0';
    }
    return s1;
}