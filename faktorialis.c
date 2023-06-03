//
// Created by Szabó Bence on 2022. 09. 12..
//
#include "stdio.h"

int main(void){
    int sorozat;
    sorozat = 1;
    for (int n = 1; n < 8; ++n) {
        sorozat = sorozat*n;
    }
    printf("%d", sorozat);
}