//
// Created by Szabó Bence on 2022. 10. 02..
//
#include "stdio.h"
#include "math.h"
#include "stdbool.h"

/*int main(void){
    int gondolt, tipp;
    srand(time(0));
    gondolt = rand()%1000+1;
    printf("Gondoltam egy számra 1-től 1000-ig. Találd ki!\n");
    do {
        printf("Add meg a tipped! ");
        scanf("%d", &tipp);
        if (gondolt>tipp){
            printf("A gondolt szám nagyobb mint a tipp.\n");
        }
        if (gondolt < tipp) {
            printf("A gondolt szám kisebb mint a tipp.\n");
        }
    } while (gondolt != tipp);
    printf("Gratulálok, kitaláltad! A gondolt szám %d volt", gondolt);

    return 0;
}
*/

/*
int main(void){
    int tipp;
    char valasz;
    srand(time(0));
    do {
        tipp = rand()%100+1;
        printf("A szám %d?\n", tipp);
        scanf("\n%c", &valasz);
    } while (valasz != 'i');
    printf("A gondolt szám %d volt\n", tipp);
}
*/

/*
int hatvany(int x, int y) {
    int hatvany = 1;
    while (y > 0) {
        hatvany *= x;
        --y;
    }
    return hatvany;
}

int main(void){
    int alap;
    int kitevo;
    scanf("\n%d", &alap);
    scanf("\n%d", &kitevo);
    printf("%d", hatvany(alap, kitevo));
}
*/

/*
int minimum(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int maximum (int a, int b){
    if (a > b){
        return a;
    }
    else
        return b;
}

int korlatoz (int x, int max, int min){
    if (x > min && x < max){
        return x;
    }
    if (x < min){
        return min;
    }
    if (x > max){
        return max;
    }
    return 0;
}

int main (void){
    int szam;
    int szam1;
    int szam2;
    scanf("\n%d", &szam);
    scanf("\n%d", &szam1);
    scanf("\n%d", &szam2);
    printf("%d", korlatoz(szam, maximum(szam1, szam2), minimum(szam1, szam2)));
}
 */


/*
typedef struct Rud {
    int min, max;
} Rud;

Rud rud_osszeg(Rud r1, Rud r2){
    Rud uj;
    uj.min=r1.min+r2.min;
    uj.max=r1.max+r2.max;

    return uj;
}

double atlag(Rud r){
    return ((r.min+r.max)/2);
}

int main (void){
    Rud a = {999, 1001};
    Rud b = {};
    scanf("%d %d", &b.min, &b.max);
    Rud o = {};

    o = rud_osszeg(a, b);
    printf("min: %d, max: %d, atlag: %f\n", o.min, o.max, atlag(o));

    return 0;

}
 */



typedef struct Sebesseg{
    double x, y;
}Sebesseg;

double hossz(Sebesseg v){
    return sqrt((v.x*v.x)+(v.y*v.y));
}

Sebesseg osszeg(Sebesseg v1, Sebesseg v2){
    Sebesseg uj;

    uj.x = v1.x+v2.x;
    uj.y = v1.y+v2.y;

    return uj;
}

int main (void){
    Sebesseg v1 = {1, 2};
    Sebesseg v2 = {-0.5, 3};
    Sebesseg vo = {};

    vo = osszeg(v1, v2);
    printf("vx: %f, vy: %f\n", vo.x, vo.y);
    printf("Hossz: %f\n", hossz(vo));

    return 0;
}


/*

typedef struct Datum{
    int ev, ho, nap;
}Datum;

void kiir(Datum d){
    printf("%d.%d.%d", d.ev, d.ho, d.nap);
}

bool szokoeve(int ev){
    if (ev % 400 == 0 || (ev % 100 != 0 && ev % 4 == 0)){
        return true;
    }
    return false;
}

int datum_hanyadik(Datum d){
    int honapok[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int hanyadik;
    
    hanyadik=0;
    for (int h = 1; h < d.ho; ++h) {
        hanyadik += honapok[h-1];
    }
    hanyadik += d.nap;
    if (szokoeve(d.ev) && d.ho > 2){
        hanyadik+=1;
    }
    return hanyadik;
}

int datum_kivon(Datum d1, Datum d2){
    int kulonbseg = datum_hanyadik(d1)- datum_hanyadik(d2);
    for (int ev = d1.ev; ev < d2.ev; ++ev) {
        if (szokoeve(ev)){
            kulonbseg += 366;
        } else
            kulonbseg += 365;
    }
    return kulonbseg;
}

int main(void){
    Datum ma = {2014, 10, 14}, eleje = {2014, 9, 8};

    printf("Ma: \n");
    kiir(ma);

    printf("\nA szorgalmu időszak kezdete: \n");
    kiir(eleje);

    printf("\nEnnyi nap telt el a két dátum között: %d", datum_kivon(ma, eleje));

}
*/

/*
typedef struct Kor{
    double x, y, r;
}Kor;

bool atfedik(Kor k1, Kor k2){
    return sqrt((k1.x-k2.y)*(k1.x-k2.y)+(k1.y-k2.y)*(k1.y-k2.y)) < k1.r-k2.r;
}

Kor beolvas(void){
    Kor k;
    scanf("%lf %lf %lf", &k.x, &k.y, &k.r);
    return k;
}

int main(void){
    Kor a, b;
    a = beolvas();
    b = beolvas();

    if (atfedik(a, b)){
        printf("Átfedik egymást");
    } else
        printf("Nem fedik át egymást");

    return 0;
}
 */