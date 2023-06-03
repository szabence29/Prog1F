//
// Created by Szabó Bence on 2022. 10. 13..
//
#include "stdio.h"

void feloszt(int n){
    if (n < 1000){
        printf("%d ", n);
        return;
    }
    feloszt(n/1000);
    printf("%03d ", n % 1000);
}

int main(void){
    int szam = 1000222215;
    feloszt(szam);
}