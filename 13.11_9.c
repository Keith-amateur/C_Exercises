#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 40
int main(int argc, char **argv) {
    FILE *fp;
    char words[MAX];
    int count = 0;

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stderr, "Can't open \" wordy \" file\n");
        exit(EXIT_FAILURE);
    }
    fseek(fp, -3, SEEK_END);
    char ch = getc(fp);
    // if (isdigit(ch))
    //     puts("isdigit");
    count = ch - '0';
    fseek(fp, 0, SEEK_END);

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words)) == 1 && (words[0]) != '#') {
        fprintf(fp, "%s%d\n", words, ++count);
    }
    puts("File contents:");
    rewind(fp);         // 返回文件开始处
    while (fscanf(fp, "%s", words) == 1) {
        puts(words);
    }
    puts("Done!");
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error in closing file\n");
    }

    return 0;   
}