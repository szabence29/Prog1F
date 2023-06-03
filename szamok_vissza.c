//
// Created by Szabó Bence on 2022. 10. 27..
//

#include <stdio.h>
#include "debugmalloc.h"

int main(void){
    int n;
    int szam;
    printf("Hany szamot? ");
    scanf("%d\n", &n);
    double *t;
    t = (double *) malloc(n*sizeof(double ));
    for (int i = 0; i < n; ++i) {
        scanf("\n%d", &szam);
        t[i] = szam;
    }
    for (int i = n-1; i > -1; --i) {
        printf("%0.f\n", t[i]);
    }
    free(t);
}
