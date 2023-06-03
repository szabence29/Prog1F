//
// Created by Szabó Bence on 2022. 09. 22..
//

#include "stdio.h"
#include "stdbool.h"
#include "ctype.h"

bool maganhangzo(char betu){
    bool magan = false;
    if (betu=='a' || betu=='e' || betu=='i' || betu=='o' || betu=='u' || betu=='A' || betu=='E' || betu=='I' || betu=='O' || betu=='U'){
        magan = true;
    }
    return magan;
}

int main(void){
    char c;
    while (scanf("%c", &c) != EOF){
        int karakterkod = c;
        if (maganhangzo(c) && karakterkod < 97){
            printf("%cv%c", karakterkod, karakterkod+32);
        }

        else if(maganhangzo(c) && karakterkod >= 97){
            printf("%cv%c", karakterkod, karakterkod);
        }
        else
            printf("%c", c);
    }
}