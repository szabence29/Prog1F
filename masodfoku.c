//
// Created by Szabó Bence on 2022. 09. 09..
//
#include <stdio.h>
#include <math.h>

int main(void) {
    int a;
    printf("Adja meg az a együtthatót! ");
    scanf("%d", &a);
    int b;
    printf("Adja meg az b együtthatót! ");
    scanf("%d", &b);
    int c;
    printf("Adja meg az c együtthatót! ");
    scanf("%d", &c);
    double x1;
    double x2;
    if (b*b > 4*a*c) {
        printf("Az egyenletnek 2 valós megoldása van.\n");
        x1=((-b)+sqrt(b*b-4*a*c))/(2*a);
        x2=((-b)-sqrt(b*b-4*a*c))/(2*a);
        printf("%f\n", x1);
        printf("%f\n", x2);
    }
    if (b*b == 4*a*c) {
        printf("Az egyenletnek 1 valós megoldása van.\n");
        printf("%d\n", (-b)/(2*a));
    }
    if (b*b < 4*a*c) {
        printf("Az egyenletnek nincsen valós megoldása.");
    }
}
