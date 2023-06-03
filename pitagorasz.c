//
// Created by Szabó Bence on 2022. 09. 12..
//

#include "stdio.h"

int main(void) {
    char tomb[10] = {'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z'};
    char elso;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf(" %c", tomb[j]);
        }
        elso = tomb[0];
        for (int k = 1; k < 10; ++k) {
            tomb[k-1] = tomb[k];
        }
        tomb[9] = elso;
        printf("\n");
    }
}
