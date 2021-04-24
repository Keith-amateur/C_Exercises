#include<stdio.h>
#include<ctype.h>       // isspace('\n') = true.
int main() {
    char ch;
    int spacec_ct, enter_ct, other_ct;
    spacec_ct = enter_ct = other_ct = 0;
    while ((ch = getchar()) != '#') {
        if (ch == ' ') {
            spacec_ct++;
        } else if (ch == '\n') {
            enter_ct++;
        } else {
            other_ct++;
        }
    }
    printf("# space, # \\n, # other characters\n");
    printf("  %3d  %4d  %7d", spacec_ct, enter_ct, other_ct);
    return 0;
}   