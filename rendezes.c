//
// Created by Szabó Bence on 2022. 10. 20..
//

#include "stdio.h"


/*
void csere(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minindex(int *tomb, int eleje, int vege){
    int index = eleje;
    for (int i = eleje + 1; i <= vege; ++i) {
        if (tomb[i] < tomb[index])
            index = i;
    }
    return index;
}

void sorba(int *tomb, int meret){
    for (int i = 0; i < meret-1; ++i) {
        int min = minindex(tomb, i, meret-1);
        if (min != i)
            csere(&tomb[min], &tomb[i]);
    }
}

int main(void){
    int tomb[6] = {3, 5, 8, 2, 3, 9};
    sorba(tomb, 6);
    for (int i = 0; i < 6; ++i) {
        printf("(%d.) %d\n", i, tomb[i]);
    }
}
*/

void csere(double *a, double *b){
    double temp = *a;
    *a = *b;
    *b = temp;
}

double kisebb(double *tomb, int eleje, int vege){
    int index = eleje;
    for (int i = eleje+1; i <= vege; ++i) {
        if (tomb[i] < tomb[index])
            index = i;
    }
    return index;
}

void rendez(double *tomb, int meret){
    for (int i = 0; i < meret; ++i) {
        int minindex = kisebb(tomb, i, meret);
        if (minindex != i){
            csere(&tomb[i], &tomb[minindex]);
        }
    }
}

int main (void){
    double tomb[5] = {1.4, 2, 5.1, 3.5, 0.1};
    rendez(tomb, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d. %g", i, tomb[i]);
    }
}


















