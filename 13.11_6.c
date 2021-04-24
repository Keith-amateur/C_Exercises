#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main() {
    FILE *in, *out;
    int ch;
    puts("Please enter the file name");
    char name[LEN];
    scanf("%s", name);
    int count = 0;
    if ((in = fopen(name, "r")) == NULL) {
        fprintf(stderr, "Can't open %s file\n", name);
        exit(EXIT_FAILURE);
    }
    strncat(&name[strlen(name)], ".red", 5);
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't open %s file\n", name);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(in)) != EOF) {
        if (count++ % 3 == 0) {
            putc(ch, out);
        }
    }

    if (fclose(in) != 0 || fclose(out) != 0) {
        fprintf(stderr, "Error in closing files\n");
    }
    return 0;
}