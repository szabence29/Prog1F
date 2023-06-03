//
// Created by Szabó Bence on 2022. 10. 20..
//

#include "stdio.h"
#include "math.h"

int main (void){
    double szam = 5;
    for (int i = 0; i < 32; ++i) {
        szam = 1 << i;
        printf("%g - %g\n", szam, log2(szam)+1);
    }
}
