#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 21

int charCount(FILE *fp, char ch);

int main(int argc, char **argv) {
    char filename[LEN];
    if (argc == 1) {
        fprintf(stderr, "Argument is not enough\n");
        exit(EXIT_FAILURE);
    } else if (argc == 2) {
        fgets(filename, LEN, stdin);
        char *find;
        if ((find = strchr(filename, '\n'))) {
            *find = '\0';
        }
        FILE *fp;
        if ((fp = fopen(filename, "r")) == NULL) {
            fprintf(stderr, "Can't open the file %s", filename);
            exit(EXIT_FAILURE);
        }
        printf("There are %d %c in %s", charCount(fp, *argv[1]), *argv[1], filename);
        fclose(fp);
    } else if (argc > 2) {
        int i;
        FILE *fp;
        for (i = 2; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                fprintf(stderr, "Can't open the file %s", argv[i]);
                continue;
            }
            printf("There are %d %c in %s\n", charCount(fp, *argv[1]), *argv[1], argv[i]);
            fclose(fp);
        }
    }
    return 0;
}

int charCount(FILE *fp, char ch) {
    char charinfile;
    int count = 0;
    while ((charinfile = getc(fp)) != EOF) {
        if (charinfile == ch) {
            count++;
        }
    }
    return count;
}