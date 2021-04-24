#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define LEN 21
#define MAX 19
struct info {
    int no;
    char fname[LEN];
    char lname[LEN];
    int times;
    int hit;
    int base;
    int point;
    float rate;
};
void create_Data();


int main() {
    int count = 0;
    struct info player[MAX];
    memset(player, 0, sizeof(player));
    create_Data();
    FILE *fp;
    if ((fp = fopen("data.dat", "rb")) == NULL) {
        fprintf(stderr, "Can't open the file");
        exit(1);
    }
    struct info temp;
    rewind(fp);
    while (count < MAX && fread(&temp, sizeof(struct info), 1, fp) == 1) {
        player[temp.no] = temp;
        player[temp.no].rate = (float)temp.hit / temp.times;
        printf("%d %s %s %d %d %d %d %.2f\n", player[temp.no].no, player[temp.no].fname, player[temp.no].lname, 
                                          player[temp.no].times ,player[temp.no].hit, player[temp.no].base, player[temp.no].point,
                                          player[temp.no].rate);
    }
    return 0;
}

void create_Data(void) {
    FILE *fp;
    if ((fp = fopen("data.dat", "wb+")) == NULL) {
        fputs("Can't open the file", stderr);
        exit(1);
    }
    struct info data[4] =
        {
            {4, "Jessie", "Joybat", 5, 2, 1, 1, 0.0},
            {0, "Al", "Smith", 4, 3, 1, 2, 0.0},
            {2, "Will", "Green", 2, 1, 2, 2, 0.0},
            {4, "Jessie", "Joybat", 6, 2, 2, 2, 0.0},
        };
    fwrite(data, sizeof(data), 1, fp);
    fclose(fp);
}

