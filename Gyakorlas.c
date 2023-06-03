#include "stdio.h"

int main(void){
    unsigned long int szam=29;
    for(int i=31;i>=0;i--){
        printf("%lu",(szam>>i)&1);
    }
    printf("\n");
}