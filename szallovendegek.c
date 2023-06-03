//
// Created by Szabó Bence on 2022. 10. 20..
//

#include "stdio.h"

/*
typedef struct Vedneg{
    char nev[50+1];
    int szoba;
} Vedneg;

int emelet(Vedneg v){
    return v.szoba / 100;
}

Vedneg *keres(Vedneg *vendegek, int meret, char *nev){
    for (int i = 0; i < meret; ++i) {
        if (vendegek[i].nev == nev)
            return &vendegek[i];
    }
    return NULL;
}

void lakik(Vedneg *vendegek, int meret, int *szint){
    for (int i = 0; i < meret; ++i) {
        szint[emelet(vendegek[i])] += 1;
    }
}

int legtobb(Vedneg *vendegek, int meret){
    int szintek[8];
    lakik(vendegek, meret, szintek);
    int max = 0;
    for (int i = 0; i < 8; ++i) {
        if (szintek[i] > szintek[max])
            max = i;
    }
    return max;
}
*/

typedef struct Vendeg{
    char nev[50+1];
    int szoba;
}Vendeg;

int emelet(Vendeg v){
    return v.szoba/100;
}

Vendeg *keres(Vendeg *vendegek, int meret, char *nev){
    for (int i = 0; i < meret; ++i) {
        if (vendegek[i].nev == nev){
            return &vendegek[i];
        }
    }
    return NULL;
}

void lakik(Vendeg *vendegek, int meret, int *szint){
    for (int i = 0; i < 7; ++i) {
        szint[i] = 0;
    }
    for (int i = 0; i < meret; ++i) {
        szint[emelet(vendegek[i])] += 1;
    }
}

int legtobb(Vendeg *vendegek, int meret){
    int szintek[8];
    lakik(vendegek, meret, szintek);
    int max = 0;
    for (int i = 0; i < 8; ++i) {
        if (szintek[i] > szintek[max])
            max = i;
    }
    return max;
}



















