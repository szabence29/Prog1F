//
// Created by Szabó Bence on 2022. 11. 03..
//

#include <stdio.h>
#include <string.h>
#include "debugmalloc.h"

char* masolat(char *forras){
    char *str = (char *) malloc(strlen(forras)+1*sizeof(char));
    strcpy(str, forras);
    str[strlen(forras)] = '\0';
    return str;
}
#
char* hozzafuz(char *mihez, char *mit){
    int lenmihez = strlen(mihez);
    int lenmit = strlen(mit);
    char *stringhozzafuz = (char *) malloc((lenmihez + lenmit + 1)*sizeof(char));
    for (int i = 0; i < lenmihez; ++i) {
        stringhozzafuz[i] = mihez[i];
    }
    for (int i = 0; i < lenmit; ++i) {
        stringhozzafuz[lenmihez+i] = mit[i];
    }
    stringhozzafuz[lenmihez+lenmit] = '\0';
    return stringhozzafuz;


char* reszsztring(char *forras, int idx1, int idx2){
    int hossz = strlen(forras);
    if (idx1 < 0)
        idx1 = 0;
    if (idx2 > hossz)
        idx2 = hossz;
    char *reszszoveg = (char*) malloc(((idx2-idx1)+1)*sizeof(char));
    int j = 0;
    for (int i = 0; i < hossz; ++i) {
        if (i >= idx1 && i < idx2){
            reszszoveg[j++] = forras[i];
        }
    }
    reszszoveg[j] = '\0';
    return reszszoveg;
}

char* reszsztring2(char *forras, int idx1, int idx2){
    int hossz = strlen(forras);
    if (idx1 < 0)
        idx1 = 0;
    if (idx2 > hossz)
        idx2 = hossz;
    char *reszszoveg = (char*) malloc(((hossz-(idx2-idx1))+1)*sizeof(char));
    int j = idx1;
    for (int i = 0; i < idx1; ++i) {
        reszszoveg[i] = forras[i];
    }
    for (int i = idx2; i < hossz; ++i) {
        reszszoveg[j++] = forras[i];
    }
    reszszoveg[j] = '\0';
    return reszszoveg;
}


int main(void){
    char *szovegmasol = masolat("alma");
    printf("Masol: %s\n", szovegmasol);
    char *szoveghozzafuz = hozzafuz("alma", "fa");
    printf("Hozzafuz: %s\n", szoveghozzafuz);
    char *szovegreszsztring = reszsztring("hello, vilag", 3, 9);
    printf("Resz (belul): %s\n", szovegreszsztring);
    char *szovegreszsztring2 = reszsztring2("hello, vilag", 4, 8);
    printf("Resz (kivul): %s\n", szovegreszsztring2);
    free(szovegmasol);
    free(szoveghozzafuz);
    free(szovegreszsztring);
    free(szovegreszsztring2);
}