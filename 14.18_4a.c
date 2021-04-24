#include <stdio.h>
#include <string.h>
#define LEN 21
struct name {
    char fname[LEN];
    char lname[LEN];
    char mname[LEN];
};
struct info {
    int num;
    struct name person;
};

void showinfo(struct info *containers, int n);

int main() {
    struct info containers[5] =
        {
            {302039823, {"Dirbble", "Flossie", "Muller"}},
            {302039822, {"Will", "Smith", "Karl"}},
            {302039821, {"Keith", "Flick"}},
            {302039820, {"Lucy", "Fisher", "Weil"}},
            {302039819, {"Annie", "Green"}},
        };
    showinfo(containers, 5);
    return 0;
}

void showinfo(struct info *containers, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (strlen(containers[i].person.mname) != 0)
            printf("%s, %s %c. -- %d\n", 
                    containers[i].person.fname, containers[i].person.lname,
                    containers[i].person.mname[0], containers[i].num);
        else
            printf("%s, %s -- %d\n",
                   containers[i].person.fname, containers[i].person.lname,
                   containers[i].num);
    }
}