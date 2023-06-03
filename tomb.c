//
// Created by Szabó Bence on 2022. 09. 12..
//
#include "stdio.h"

int main(void) {
    int tomb[10] = {20, 10, 2, 0, 9, 1, 54, 71, 99, 12};
    printf("A tömb:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", tomb[i]);
    }
    printf("\n");
    int legkisebb;
    legkisebb = 999999999;
    int legkindex;
    legkindex = 0;
    printf("A tömb: ");
    for (int i = 0; i < 10; ++i) {
        printf("[");
        printf("%d", i);
        printf("]=");
        printf("%d ", tomb[i]);
        if (tomb[i] < legkisebb){
            legkisebb=tomb[i];
            legkindex=i;
        }
    }
    printf("\n");
    printf("A legkisebb szám: %d\n", legkisebb);
    printf("A legkisebb szám indexe: %d", legkindex);

    printf("\n");
    printf("Jelölve:");
    for (int i = 0; i < 10; ++i) {
        printf(" %d",tomb[i]);
        if (tomb[i] == legkisebb) {
            printf("[MIN]");
        }
    }
}