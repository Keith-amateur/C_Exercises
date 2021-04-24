#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "17.12_7_tree.h"

void printitem(Item item);
char menu(void);
void showTree(Tree *pt);
int countWords(char *w, Tree *pt);

int main() {
    Tree wordsTree;
    InitializeTree(&wordsTree);
    char filename[50] = "testfileFor17.12_7";
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Error in opening file");
        exit(1);
    }
    char word[SLEN];
    while (!feof(fp)) {
        fscanf(fp, "%s", word);
        Item temp;
        strcpy(temp.word, word);
        temp.count = 1;
        AddItem(&temp, &wordsTree);
        showTree(&wordsTree);
        puts("---------------");
    }
    fclose(fp);
    char ch;
    char w[SLEN];
    while ((ch = menu()) != 'q') {
        switch (ch) {
            case 's':
                showTree(&wordsTree);
                break;
            case 'f':
                scanf("%s", w);
                while (getchar() != '\n') {
                    continue;
                }
                printf("%s appears %d times in file\n", w ,countWords(w, &wordsTree));
                break;
            default:
                puts("something wrong...");
                break;
        }
    }
    DeleteAll(&wordsTree);

    return 0;
}


void showTree(Tree *pt) {
    Traverse(pt, printitem);
}
void printitem(Item item) {
    printf("%-10s    %d times\n", item.word, item.count);
}
int countWords(char *w, Tree *pt) {
    Item item;
    strcpy(item.word, w);
    item.count = 0;
    int n;
    if (InTree(&item, pt, &n)) {
        return n;
    } else {
        return 0;
    }
}

char menu(void) {
    puts("s) show all words");
    puts("f) enter a word");
    puts("q) quit");
    char ch;
    ch = getchar();
    while (getchar() != '\n') {
        continue;
    }
    if (strchr("sfq", ch)) {
        return ch;
    } else {
        puts("Please enter s f q");
        menu();
    }
}