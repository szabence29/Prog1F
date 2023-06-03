//
// Created by Szabó Bence on 2022. 10. 13..
//

#include "stdio.h"

int fibonacci(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    int fn1 = fibonacci(n-1);
    int fn2 = fibonacci(n-2);

    return fn1 + fn2;
}

int main(void){
    int n;
    scanf("%d", &n);
    int szam = fibonacci(n);
    printf("%d", szam);
}