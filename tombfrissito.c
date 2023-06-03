//
// Created by Szabó Bence on 2022. 09. 22..
//
#include "stdio.h"

int main(void) {

    // 1. feladat:

    int tomb[10] = {-20, 10, -2, 0, 9, -1, 54, -71, 99, -12};
    int negativ=0;
    int size = sizeof tomb/ sizeof tomb[0];
    printf("Összesen %d szám van\n", size);
    for (int i = 0; i < size; ++i) {
        if (tomb[i] < 0){
            negativ+=1;
        }
    }
    printf("Ebből %d szám negatív\n", negativ);
    printf("Indexeik: ");
    for (int i = 0; i < 10; ++i) {
        if (tomb[i] < 0){
            printf("%d ", i);
        }
    }
    printf("\n\n");

    // 2. feladat:

    double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
    int negativindex[10] = {};
    negativ=0;
    int meret = sizeof szamok/ sizeof szamok[0];
    printf("Összesen %d szám van.\n", meret);
    for (int i = 0; i < meret; ++i) {
        printf("[%d]=%g ", i, szamok[i]);
        if (szamok[i] < 0){
            negativindex[negativ] = i;
            negativ+=1;
        }
    }
    printf("\n\n");
    for (int i = 0; i < negativ; ++i) {
        printf("[%d]=%g ", negativindex[i], szamok[negativindex[i]]);
    }
}