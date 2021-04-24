#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static int rollem(int sides);
int roll_n_dice(int dice, int sides);

int main() {
    int dice, sides;
    int roll, sets;
    printf("Enter the number of sets; Enter q to stop: ");
    while (scanf("%d", &sets) == 1) {
        printf("How many sides and how many dice?  ");
        while (scanf("%d %d", &sides, &dice) != 2) {
            printf("Please enter the right form: ");
            while (getchar() != '\n') {
                continue;
            }
        }
        int i;
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (i = 0; i < sets; i++) {
            roll = roll_n_dice(dice, sides);
            printf("%d  ", roll);
        }
        printf("\nEnter the number of sets; Enter q to stop: ");
    }
    return 0;
}

static int rollem(int sides) {
    int roll;

    roll = rand() % sides + 1;
    return roll;
}

int roll_n_dice(int dice, int sides) {
    int d;
    int total = 0;
    if (sides < 2) {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1) {
        printf("Need at least 1 die.\n");
        return -1;
    }

    for (d = 0; d < dice; d++) {
        total += rollem(sides);
    }
    return total;
}
