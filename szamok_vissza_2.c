//
// Created by Szabó Bence on 2022. 10. 27..
//

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main(void){
    int n;
    int db = 0;
    int szam;
    bool felszabadit = false;
    printf("Hany szamot? ");
    scanf("%d\n", &n);
    double *t;
    t = (double *) malloc(n*sizeof(double ));
    double *ujt;
    ujt = (double *) malloc(n*sizeof(double ));
    while (scanf("%d", &szam) == 1 && szam != -1){
        if (db > n){
            felszabadit = true;
            for (int i = 0; i < n-1; ++i) {
                t[i] = ujt[i];
            }
            ++n;
            ujt[db] = szam;
        } else
            t[db] = szam;
        ++db;
    }
    if (felszabadit){
        for (int i = db-1; i > -1; --i) {
            printf("%0.f\n", ujt[i]);
        }
    } else {
        for (int i = n-1; i > -1; --i) {
            printf("%0.f\n", t[i]);
        }

    }
}

