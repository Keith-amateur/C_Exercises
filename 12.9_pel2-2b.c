#include<stdio.h>
#include "12.9_pel2-2a.h"

int main() {
    int mode;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        int previous_mode;
        previous_mode = set_mode(mode);
        get_info();
        show_info();
        printf("Enter 0 for metric mode, 1 for US mode: ");
        printf("(-1 to quit):");
        scanf("%d", &mode);
        if (mode != 1 && mode != 0 && mode != -1) {
            printf("Invalid mode specified. Mode %d(%s) used\n", 
            previous_mode, previous_mode == 1 ? "US" : "metric");
            mode = previous_mode;
        }
    }
    printf("Done.\n");
    return 0;
}
