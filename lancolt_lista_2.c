#include <stdlib.h>
#include <stdio.h>

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}

ListaElem *lista_elejere_beszur(ListaElem *eleje, int adat) {
    ListaElem *uj;
    uj = (ListaElem *) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->kov = eleje;
    return uj;
}

ListaElem *lista_vegere_beszur(ListaElem *eleje, int adat){
    ListaElem *uj;
    uj = (ListaElem*) malloc(sizeof(ListaElem));
    uj->adat = adat;
    uj->kov = NULL;

    if (eleje == NULL) {
        eleje = uj;
    } else {
        ListaElem *mozgo = eleje;
        while (mozgo->kov != NULL)
            mozgo = mozgo->kov;
        mozgo->kov = uj;
    }
    return uj;
}

ListaElem *keres(ListaElem *eleje, int szam){
    ListaElem *mozgo;
    for (mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov) {
        if (mozgo->adat == szam){
            return mozgo;
        }
    }
    return NULL;
}

int main(void) {
    ListaElem *eleje;
    eleje = lista_letrehoz();
    ListaElem *mozgo;
    int db = 0;

    for (mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov) {
        printf("%d ", mozgo->adat);
        db+=1;
    }
    printf("\n%d\n", db);

    eleje = lista_elejere_beszur(eleje, 21);

    for (mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov) {
        printf("%d ", mozgo->adat);
    }

    eleje = lista_vegere_beszur(eleje, 69);

    for (mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov) {
        printf("%d ", mozgo->adat);
    }

    printf("\n%d", keres(eleje, ));

    return 0;
}