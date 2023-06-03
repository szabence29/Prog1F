#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void kiir(BiFa *gyoker){
    if (gyoker == NULL){
        return;
    }
    kiir(gyoker->bal);
    printf("%d ", gyoker->ertek);
    kiir(gyoker->jobb);
}

void felszabadit(BiFa *gyoker){
    if (gyoker == NULL){
        return;
    }
    felszabadit(gyoker->bal);
    felszabadit(gyoker->jobb);
    free(gyoker);
}

int elem(BiFa *gyoker){
    if (gyoker == NULL){
        return 0;
    }
    return elem(gyoker->bal) + elem(gyoker->jobb) + 1;
}

int osszeg(BiFa *gyoker){
    if (gyoker == NULL){
        return 0;
    }
    return osszeg(gyoker->bal) + osszeg(gyoker->jobb) + gyoker->ertek;
}

BiFa *keres(BiFa *gyoker, int ertek){
    if (gyoker == NULL){
        return NULL;
    }
    if (gyoker->ertek == ertek){
        return gyoker;
    }
    if (gyoker->ertek < ertek ){
        return keres(gyoker->jobb, ertek);
    } else {
        return keres(gyoker->bal, ertek);
    }
}

void negalas(BiFa *gyoker){
    if (gyoker == NULL){
        return;
    }
    negalas(gyoker->bal);
    gyoker->ertek = gyoker->ertek*-1;
    negalas(gyoker->jobb);
}

BiFa *negaltkeres(BiFa *gyoker, int ertek){
    if (gyoker == NULL){
        return NULL;
    }
    if (gyoker->ertek == ertek){
        return gyoker;
    }
    if (gyoker->ertek > ertek ){
        return negaltkeres(gyoker->jobb, ertek);
    } else {
        return negaltkeres(gyoker->bal, ertek);
    }
}

void tukroz(BiFa *gyoker){
    if (gyoker == NULL){
        return;
    }
    BiFa *temp = gyoker->jobb;
    gyoker->jobb = gyoker->bal;
    gyoker->bal = temp;
    tukroz(gyoker->jobb);
    tukroz(gyoker->bal);
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);
    kiir(gyoker);
    printf("\n%d", elem(gyoker));
    printf("\n%d", osszeg(gyoker));
    BiFa *find = keres(gyoker, 21);
    if (find == NULL){
        printf("\nNincs benne ilyen elem.");
    } else {
        printf("\n%d", find->ertek);
    }
    negalas(gyoker);
    printf("\n");
    kiir(gyoker);
    BiFa *find_negate = negaltkeres(gyoker, -21);
    if (find_negate == NULL){
        printf("\nNincs benne ilyen elem.");
    } else {
        printf("\n%d", find_negate->ertek);
    }
    printf("\n");
    negalas(gyoker);
    tukroz(gyoker);
    kiir(gyoker);
    felszabadit(gyoker); //Felszabadítja a fa elemeit.
    return 0;
}