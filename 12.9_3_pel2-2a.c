#include<stdio.h>
#include"12.9_3_pel2-2a.h"

int set_mode(int n) {
    int mode;
    mode = n;
    return mode;
}

void get_info(int mode, double *distance, double *fuel) {
    if (mode == 0) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", fuel);
    } else if (mode == 1) {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel);
    }
}

void show_info(int mode, double distance, double fuel) {
    if (mode == 0) {
        printf("Fuel consumption is %.2f liters per 100 km\n", 
        fuel / distance * 100);
    } else if (mode == 1) {
        printf("Fuel consumption is %.1f miles per gallon\n", 
        distance / fuel);

    }
}