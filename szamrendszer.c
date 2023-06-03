//
// Created by Szabó Bence on 2022. 10. 13..
//
#include "stdio.h"

void szamrendszer(int szam, int szamr){
    if (szam == 0)
        return;
    szamrendszer(szam/szamr, szamr);
    printf("%d ", szam%szamr);
}

int main(void){
    int szam = 10;
    int szamr = 2;
    szamrendszer(szam, szamr);

    return 0;
}