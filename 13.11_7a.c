#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAXLEN 1025

int main(int argc, char **argv) {
    FILE *f1, *f2;
    if ((f1 = fopen(argv[1], "r")) == NULL 
    || (f2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Error in opening files\n");
    }
    char buff[MAXLEN];
    while (!feof(f1) || !feof(f2)) {
        memset(buff, 0, MAXLEN);
        fgets(buff, MAXLEN, f1);
        fputs(buff, stdout);
        fgets(buff, MAXLEN, f2);
        fputs(buff, stdout);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}