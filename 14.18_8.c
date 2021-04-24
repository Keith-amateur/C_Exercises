#include <stdio.h>
#include <string.h>
#include <memory.h>

#define LEN 21
#define NUM 12
struct seat {
    int no;
    int isbooked;
    char fname[LEN];
    char lname[LEN];
};

void eatline(void);
void showmenu(void);
void emptynum(struct seat *containers, int n);
void emptylist(struct seat *containers, int n);
void alphabetical(struct seat *containers, int n);
void book(struct seat *containers, int n);
void delete(struct seat *containers, int n);
char *s_gets(char *st, int n);

int main() {
    struct seat seats[NUM];
    memset(seats, 0, sizeof(seats));
    int index;
    for (index = 0; index < NUM; index++) {
        seats[index].no = index + 1;
    }
    showmenu();
    char opt;
    while ((opt = getchar()) != 'f') {
        switch (opt) {
            case 'a':
                emptynum(seats, NUM);
                break;
            case 'b':
                emptylist(seats, NUM);
                break;
            case 'c':
                alphabetical(seats, NUM);
                break;
            case 'd':
                book(seats, NUM);
                break;
            case 'e':
                delete (seats, NUM);
                break;
            default:
                printf("ERROR INPUT");
                break;
        }
        eatline();          // 调用book函数时, 会出现出现额外一个空格的原因
        showmenu();
    }
    puts("Bye!");
    return 0;
}

void eatline(void) {
    while (getchar() != '\n') {
        continue;
    }
}

void showmenu(void) {
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats\nb) Show list of empty seats");
    puts("c) Show alphabetical list of seats\nd) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment\nf) Quit");
}

void emptynum(struct seat *containers, int n) {
    int i;
    int num = 0;
    for (i = 0; i < n; i++) {
        if (!containers[i].isbooked) {
            num++;
        }
    }
    printf("Empty seats: %d\n", num);
}

void emptylist(struct seat *containers, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (!containers[i].isbooked) {
            printf("%d\n", containers[i].no);
        }
    }
}

void alphabetical(struct seat *containers, int n) {
    int i, j;
    struct seat currseats[NUM];
    for (i = 0, j = 0; i < n; i++) {
        if (containers[i].isbooked) {
            currseats[j++] = containers[i];
        }
    }

    int k, l;
    struct seat temp;
    for (k = 0; k < j; k++) {
        for (l = k + 1; l < j; l++) {
            if (currseats[k].fname[0] > currseats[l].fname[0]) {
                temp = currseats[k];
                currseats[k] = currseats[l];
                currseats[l] = temp;
            }
        }
        printf("%d %s %s\n", currseats[k].no, currseats[k].fname, currseats[k].lname);
    }
}

void book(struct seat *containers, int n) {
    puts("Enter the number of the seat you want to book:");
    int num;
    if (scanf("%d", &num) == 1 && num >= 1 && num <= NUM) {
        containers[num - 1].isbooked = 1;
        eatline();
        puts("Enter your fisrt name");
        s_gets(containers[num - 1].fname, LEN);
        puts("Enter your lasr name");
        s_gets(containers[num - 1].lname, LEN);
    }  else {
        printf("ERROR INPUT (1~%d)", NUM);
    }
}

void delete(struct seat *containers, int n) {
    puts("Enter the number of the seat that you want to cancel:");
    int num;
    if (scanf("%d", &num) == 1 && num >= 1 && num <= NUM) {
        containers[num - 1].isbooked = 0;
        memset(containers[num - 1].fname, 0, LEN);
        memset(containers[num - 1].lname, 0, LEN);
    } else {
        printf("ERROR INPUT (1~%d)", NUM);
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
            eatline();
        }
    }
    return ret_val;
}
