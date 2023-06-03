//
// Created by Szabó Bence on 2022. 10. 20..
//


#include "stdio.h"
#include "stdbool.h"
/*
bool maganhangzo(char betu){
    return betu == 'a' || betu == 'e' || betu == 'i' || betu == 'o' || betu == 'u';
}

void virag(char *forras, char *cel){
    int i = 0;
    int j = 0;
    while (forras[j] != '\0'){
        cel[i++] = forras[j];
        if (maganhangzo(forras[j])){
            cel[i++] = 'v';
            cel[i++] = forras[j];
        }
        j++;
    }
    cel[i] = '\0';
}

int main(void){
    char cel[50];
    virag("viragnyelv", cel);
    printf("%s", cel);
}
 */

bool magan(char betu){
    return betu == 'a' || betu == 'u' ||betu == 'o' ||betu == 'i' ||betu == 'e';
}

void virag(char *forras, char *cel){
    int i=0;
    int j=0;
    while (forras[j] != '\0'){
        cel[i++] = forras[j];
        if (magan(forras[j])){
            cel[i++] = 'v';
            cel[i++] = forras[j];
        }
        j++;
    }
    cel[i] = '\0';
}

int main(void){
    char cel[50];
    virag("viragnyelv", cel);
    printf("%s", cel);
}























