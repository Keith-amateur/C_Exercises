#include <stdio.h>

#define LEN 21
#define CSIZE 4
struct name {
    char fname[LEN];
    char lname[LEN];
};
struct student {
    struct name stu;
    float grade[3];
    float mean;
};

void showstructinfo(struct student *info, int n);
void calcmean(struct student *info, int n);
void printmean(struct student *info, int n);

int main() {
    struct student score[CSIZE] = 
    {
        {{"A", "a"}},
        {{"B", "b"}},
        {{"C", "c"}},
        {{"D", "d"}},
    };
    int index = 0;
    puts("Enter the score of the student:");
    while (scanf("%f %f %f", &score[index].grade[0], &score[index].grade[1], &score[index].grade[2]) == 3) {
        index++;
        puts("Enter the score of the next student");
    }
    calcmean(score, index);
    showstructinfo(score, index);
    printmean(score, index);

    return 0;
}

void calcmean(struct student *score, int n) {
    int i;
    for (i = 0; i < n; i++) {
        score[i].mean = (score[i].grade[0] + score[i].grade[1] + score[i].grade[2]) / 3;
    }
}

void showstructinfo(struct student *score, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %s grade: %.2f %.2f %.2f, mean: %.2f\n",
               score[i].stu.fname, score[i].stu.lname,
               score[i].grade[0], score[i].grade[1], score[i].grade[2],
               score[i].mean);
    }
}

void printmean(struct student *score, int n) {
    int i;
    float sum = 0.0;
    for (i = 0; i < n; i++) {
        sum += score[i].mean;
    }
    printf("The total mean is %.2f", sum / n);
}