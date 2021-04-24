#include <stdio.h>
#include <string.h>
#include <memory.h>

#define LEN 21
#define NUM 12
#define FLIGHT 4
struct seat {
    int no;
    int isbooked;
    char fname[LEN];
    char lname[LEN];
};

void eatline(void);
void showflight(void);
void showmenu(void);
void emptynum(struct seat *containers, int n);
void emptylist(struct seat *containers, int n);
void alphabetical(struct seat *containers, int n);
void book(struct seat *containers, int n);
void delete(struct seat *containers, int n);
void distribution(struct seat *containers, int n);
char *s_gets(char *st, int n);

int main() {
    static struct seat seats[FLIGHT][NUM];
    memset(seats, 0, sizeof(seats));
    int flight;
    showflight();
    int code = -1;
    while (scanf("%d", &flight) == 1) {
        eatline();
        switch (flight) {
            case 102:
                code = 0;
                break;
            case 311:
                code = 1;
                break;
            case 444:
                code = 2;
                break;
            case 519:
                code = 3;
                break;
            default:
                puts("ERROR INPUT");
                break;
        }
        if (code == -1) {
            break;
        }
        int index;
        for (index = 0; index < NUM; index++) {
            seats[code][index].no = index + 1;
        }
        showmenu();
        char opt;
        while ((opt = getchar()) != 'g') {
            switch (opt) {
                case 'a':
                    emptynum(seats[code], NUM);
                    break;
                case 'b':
                    emptylist(seats[code], NUM);
                    break;
                case 'c':
                    alphabetical(seats[code], NUM);
                    break;
                case 'd':
                    book(seats[code], NUM);
                    break;
                case 'e':
                    delete(seats[code], NUM);
                    break;
                case 'f':
                    distribution(seats[code], NUM);
                    break;
                default:
                    printf("ERROR INPUT");
                    break;
            }
            eatline();          // 调用book函数时, 会出现额外一个空格的原因
            showmenu();
        }
        showflight();
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
    puts("e) Delete a seat assignment\nf) Confirm the seats distribution\ng) Quit");
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

void distribution(struct seat *containers, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (containers[i].isbooked) {
            printf("%d %s %s\n", containers[i].no, containers[i].fname, containers[i].lname);
        }
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

void showflight(void) {
    puts("Flight: 102, 311, 444, 519\n Enter any non-digital to quit");
}