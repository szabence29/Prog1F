//
// Created by Szabó Bence on 2022. 10. 06..
//

#include "stdio.h"
#include "math.h"

void kocka(double o, double *felszin, double *terfogat){
    *felszin = pow(o, 2)*6;
    *terfogat = pow(o, 3);


}

int main(void){
    double oldal = 2;
    double felszin, terfogat;
    kocka(oldal, &felszin, &terfogat);
    printf("Felszíne: %f, Térfogata: %f", felszin, terfogat);

    return 0;
}