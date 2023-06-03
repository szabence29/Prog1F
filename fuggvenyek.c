//
// Created by Szabó Bence on 2022. 09. 22..
//

#include "stdio.h"

double kob(double x){
    return x*x*x;
}

double abszolut(double x){
    return x*(-1);
}

double szinusz(double x){
    return x*(3.142/180);
}

int main(void){
    for (double i = -1; i < 1; i=i+0.1) {
        printf("%f ,%f ,%f ,%f", i, kob(i), abszolut(i), szinusz(i));
        printf("\n");
    }
}