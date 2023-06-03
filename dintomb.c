#include "stdio.h"
#include "string.h"
#include "debugmalloc.h"

int main(void){
    int i;
    char s[200];
    char s2[200];
    printf("Szam: ");
    scanf("%d", &i);
    getchar();  /* ! */
    printf("Szoveg: ");
    fgets(s, 200, stdin);
    getchar();
    printf("Szoveg2: ");
    fgets(s2, 200, stdin);
    printf("%d %s %s", i, s2, s);
}