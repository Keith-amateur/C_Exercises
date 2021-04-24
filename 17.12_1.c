#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);
char options(void);
void inorder(struct film *head);
void reverseorder(struct film *head);
// 正序 逆序 表示链表   利用递归 

int main() {
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    char opt;
    // 收集信息
    puts("Enter the first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL) {
            head = current;
        } else {
            prev->next = current;
        }
        current->next = NULL;
        strcpy(current->title, input);
        puts("Now enter your rating <0 - 10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title(empty line to quit):");
        prev = current;
    }
    if (head == NULL) {
        puts("No data entered");
    } else {
        puts("How do you want to present the movie list:");
        opt = options();
        if (opt == 'i') {
            inorder(head);
        } else {
            reverseorder(head);
        }
    }

    current = head;
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }
    puts("Bye!");

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
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}

char options(void) {
    // 清理缓存区
    while (getchar() != '\n') {
        continue;
    }
    char opt;
    puts("i) in order     r) in reverse order");
    opt = getchar();
    opt = tolower(opt);
    if (strchr("ir", opt)) {
        return opt;
    } else {
        puts("Please enter the i or r");
        options();
    }
}

void inorder(struct film *head) {
    struct film *current;
    current = head;
    while (current != NULL) {
        printf("Movie: %s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }
}

void reverseorder(struct film *head) {
    if (head == NULL) {
        return;
    }
    reverseorder(head->next);
    printf("Movie: %s Rating: %d\n", head->title, head->rating);
}