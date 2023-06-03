//
// Created by Szabó Bence on 2022. 09. 22..
//
#include "stdio.h"
#include "math.h"

/*
typedef struct pont{
    double x, y;
} pont;
*/

/*
int main(void){
    pont p1 = {2.2, 1.6};
    printf("Első pont: %lf, %lf\n", p1.x, p1.y);
    pont p2 = {};
    scanf("%lf%lf", &p2.x, &p2.y);
    printf("Második pont: %lf, %lf", p2.x, p2.y);
    pont p3 = {((p1.x+p2.x)/2), ((p1.y+p2.y)/2)};
    printf("\nSzakasz felezőpontja: x=%lf, y=%lf", p3.x, p3.y);
    p1 = (pont) { 2, 5};
    printf("%lf %lf", p1.x, p1.y);
}
 */

/*
double origo_tavolsag(pont p) {
    return sqrt(p.x*p.x + p.y*p.y);
}

int main(void){
    pont p = {4, 6};
    printf("%lf", origo_tavolsag(p));
}
 */


/*
int main(void){
    Tort uj = {12, 2};
    Tort t[4];

    for (int i = 0; i < 4; ++i) {
        t[i].szaml = 1;
        t[i].nev = 2;
    }
    for (int i = 0; i < 4; ++i) {
        printf("%d/%d\n", t[i].szaml, t[i].nev);
    }
    printf("%d/%d", uj.szaml, uj.nev);
}
 */

#include <stdio.h>
#include <math.h>

typedef struct Vektor{
    double x, y;
} Vektor;

double hossz(Vektor v){
    return sqrt((v.x*v.x)+(v.y*v.y));
}

Vektor osszeg(Vektor v1, Vektor v2){
    Vektor o;

    o.x = v1.x+v2.x;
    o.y = v1.y+v2.y;

    return o;
}

int main(void){
    Vektor a = {1, 2};
    Vektor b = {-0.5, 3};
    Vektor c = {};

    c = osszeg(a, b);
    printf("vx: %lf, vy: %lf\n", c.x, c.y);
    printf("Hossza: %lf", hossz(c));
}