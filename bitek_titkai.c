//
// Created by Szabó Bence on 2022. 10. 20..
//

#include "stdio.h"

void valtoztat(unsigned karakter){
    for (int i = 31; i >= 0; --i) {
       printf("%c", ((karakter >> i) &1) ? '#' : ' ');
    }
}

int main (void){
    unsigned long szamok[9] = { 0U, 1931988508U, 581177634U, 581374240U,581177632U,581177634U, 1919159836U, 0U };
    for (int i = 0; i < 9; ++i) {
        valtoztat(szamok[i]);
        printf("\n");
    }
}