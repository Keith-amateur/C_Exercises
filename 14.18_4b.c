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

void showinfo(struct info one);

int main() {
    struct info containers[5] =
        {
            {302039823, {"Dirbble", "Flossie", "Muller"}},
            {302039822, {"Will", "Smith", "Karl"}},
            {302039821, {"Keith", "Flick"}},
            {302039820, {"Lucy", "Fisher", "Weil"}},
            {302039819, {"Annie", "Green"}},
        };
    int i;
    for (i = 0; i < 5; i++) {
        showinfo(containers[i]);
    }
    return 0;
}

void showinfo(struct info one) {
    if (strlen(one.person.mname) != 0)
        printf("%s, %s %c. -- %d\n", 
                one.person.fname, one.person.lname,
                one.person.mname[0], one.num);
    else
        printf("%s, %s -- %d\n",
                one.person.fname, one.person.lname,
                one.num);

}