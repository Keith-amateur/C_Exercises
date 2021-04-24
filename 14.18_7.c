#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
char *s_gets(char *st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    double value;
};

int main() {
    struct book library[MAXBKS];
    int count = 0;
    int index, filecount;
    FILE *pbooks;
    int size = sizeof(struct book);
    { // 将文件中已有的结构信息读取
    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0) {
            puts("Current contents of book.dat:");
        }
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if (count == MAXBKS) {
        fputs("The book.dat is full.", stderr);
        exit(2);
    }
    }

    int i = 0;
    puts("Please enter the number of data you want to change");
    while (scanf("%d", &i) == 1 && i >= 1 && i <= count) {
        while (getchar() != '\n')
            continue;
        rewind(pbooks);
        puts("Enter new book title");
        s_gets(library[i - 1].title, MAXTITL);
        puts("Enter new book author");
        s_gets(library[i - 1].author, MAXAUTL);
        puts("Enter new book value");
        scanf("%f", &library[i - 1].value);
        fseek(pbooks, (long)((i-1) * size), SEEK_SET);
        fwrite(&library[i - 1], size, 1, pbooks);
        puts("Enter the next number:");
    }
    while (getchar() != '\n')
        continue;
    fseek(pbooks, 0, SEEK_END);
    { // 将新的结构信息写入数组
    puts("Please add new book titles.");
    puts("Please [ENTER] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL 
                          && library[count].title[0] != '\0') {
        puts("Now enter the author.");
        s_gets(library[count].author, MAXTITL);
        puts("Now enter the value.");
        scanf("%lf", &library[count++].value);
        while (getchar() != '\n') {
            continue;
        }
        if (count < MAXBKS) {
            puts("Enter the next title.");
        }
    }
    }

    {// 显示数组中的结构信息，并将新添加的结构信息写入文件
    if (count > 0) {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++) {
            printf("%s by %s: %.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    } else {
        puts("No books? Too bad.\n");
    }
    puts("Bye!");
    fclose(pbooks);
    }

    return 0;
}

char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}