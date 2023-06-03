//
// Created by Szabó Bence on 2022. 10. 27..
//

#include "stdlib.h"
#include "stdio.h"

int main(void) {
    double *t;
    double *ujt;
    int db = 0;
    double szam;
    t = (double *) malloc((db + 1) * sizeof(double));
    while (scanf("%lf", &szam) == 1 && szam != -1) {
        ujt = (double *) malloc((db + 1) * sizeof(double));
    }
    for (int i = db - 1; i > -1; --i) {
        printf("%0.f\n", t[i]);
    }
}