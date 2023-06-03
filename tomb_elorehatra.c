//
// Created by Szabó Bence on 2022. 10. 13..
//

#include "stdio.h"

void it_elore(int *tomb, int meret){
    for (int i = 0; i < meret; ++i) {
        printf("%d ", tomb[i]);
    }
}

void it_hatra(int *tomb, int meret){
    for (int i = meret-1; i > -1; --i) {
        printf("%d ", tomb[i]);
    }
}

void rek_elore(int *tomb, int meret){
    if (meret == 0)
        return;
    printf("%d ", tomb[0]);
    rek_elore( tomb + 1, meret - 1);
}

void rek_hatra(int *tomb, int meret){
    if (meret == 0)
        return;
    rek_hatra(tomb + 1, meret - 1);
    printf("%d ", tomb[0]);
}

int main(void){
    int tomb1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    it_elore(tomb1, 10);
    printf("\n");
    it_hatra(tomb1, 10);
    printf("\n");
    rek_elore(tomb1, 10);
    printf("\n");
    rek_hatra(tomb1, 10);
}