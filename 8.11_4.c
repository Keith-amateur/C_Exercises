#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main() {
    char ch;
    int cnt_alpha = 0;
    int cnt_words = 0;
    bool inword = false;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            inword = true;
        } else if (inword) {
            inword = false;
            cnt_words++;
        }
        if (inword) {
            cnt_alpha++;
        }

    }
    printf("%d个单词 %d个字母\n", cnt_words, cnt_alpha);
    printf("平均每个单词的字母数:%.4f", (double)cnt_alpha / cnt_words);
    return 0;
}