// 使用二叉查找树
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>
#include "17.12_8_tree.h"

char menu(void);
void addpet(Tree *pt);
void droppet(Tree *pt);
void showpets(const Tree *pt);
void findpet(const Tree *pt);
void printitem(Item item);
int countpets(Item item);
void uppercase(char *str);
char *s_gets(char *st, int n);

int main() {
    Tree pets;
    char choice;

    InitializeTree(&pets);
    while ((choice = menu()) != 'q') {
        switch (choice) {
            case 'a':
                addpet(&pets);
                break;
            case 'l':
                showpets(&pets);
                break;
            case 'f':
                findpet(&pets);
                break;
            case 'n':
                printf("%d pets in club\n", TreeItemCount(&pets));
                break;
            case 'd':
                droppet(&pets);
                break;
            default:
                puts("Switching Error");
                break;
        }
    }
    DeleteAll(&pets);
    puts("Bye!");
}

char menu(void) {
    int ch;

    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != 'q') {
        while (getchar() != '\n') {
            continue;
        }
        ch = tolower(ch);
        if (strchr("alrfndp", ch) == NULL) {
            puts("Please enter an a, l, f, n, or q:");
        } else {
            break;
        }
    }
    if (ch == EOF) {
        ch = 'q';
    }
    return ch;
}

void addpet(Tree *pt) {
    Item temp;

    if (TreeIsFull(pt)) {
        puts("No room in the club");
    } else {
        puts("Please enter name of pet:");
        s_gets(temp.petname, SLEN);
        puts("Please enter pet kind: ");
        char kind[SLEN];
        s_gets(kind, SLEN);
        uppercase(temp.petname);
        uppercase(kind);
        strcpy(temp.petkinds[0], kind);
        temp.count = 1;
        AddItem(&temp, pt);
    }
}

void showpets(const Tree* pt) {
    if (TreeIsEmpty(pt)) {
        puts("No entries!");
    } else {
        Traverse(pt, printitem);
    }
}

void printitem(Item item) {
    printf("Pet: %-19s   %d\n", item.petname, item.count);
    printf("Petkind:\n");
    int i;
    puts("-------------");
    for (i = 0; i < item.count; i++) {
        printf("%s ", item.petkinds[i]);
    }
    puts("\n-------------");
    putchar('\n');
}

int countpets(Item item) {
    return item.count;
}

void findpet(const Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to find:");
    s_gets(temp.petname, SLEN);
    uppercase(temp.petname);
    printf("%s\n", temp.petname);
    int n;
    Item find;
    if (InTree(&temp, pt, &n, &find)) {
        printitem(find);
    } else {
        printf("is not a member.\n");
    }
}

void droppet(Tree *pt) {
    Item temp;

    if (TreeIsEmpty(pt)) {
        puts("No entries!");
        return;
    }

    puts("Please enter name of pet you wish to delete:");
    s_gets(temp.petname, SLEN);
    uppercase(temp.petname);
    printf("%s ", temp.petname);
    if (DeleteItem(&temp, pt)) {
        printf("is dropped from the club.\n");
    } else {
        printf("is not a member.\n");
    }
}

void uppercase(char *st) {
    while (*st) {
        *st = toupper(*st);
        st++;
    }
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