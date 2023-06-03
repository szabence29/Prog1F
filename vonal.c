//
// Created by Szabó Bence on 2022. 09. 09..
//

#include "stdio.h"

int main(void){
    int hossz;
    int seged;
    seged = 1;
    printf("Mekkora legyen a szakasz? ");
    scanf("%d", &hossz);
    printf("+");
    while (seged <= hossz){
        printf("-");
        seged=seged+1;
    }
    printf("+");
    return 0;
}