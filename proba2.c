#include <stdio.h>

typedef struct{
    int x, y;
} Koord;

int kincsek_szama(char t[][10], int sorok) {
    int db=0;
    for (int i=0; i<sorok; i++)
        for (int j=0; j<10; j++)
            if (t[i][j]=='$') db++;
    return db;
}

void lab_kiir(char t[][10], int sorok) {
    for (int i=0; i<sorok; i++) {
        for (int j=0; j<10; j++) printf("%c", t[i][j]);
        printf("\n");
    }
}

Koord jatekos_helye(char t[][10], int sorok) {
    int i, j;
    Koord k;
    for (i=0; i<sorok; i++) {
        for (j=0; j<10; j++) {
            if (t[i][j]=='@') {
                k.x=j;
                k.y=i;
                return k;
            }
        }
    }
    k.x=k.y=-1;
    return k;
}

enum irany{fel, jobb, le, bal};

int mehet_e(char t[][10], int sorok, enum irany ir) {
    Koord k=jatekos_helye(t, 10);
    if (ir==fel  && k.y>0       && t[k.y-1][k.x]!='#') return 1;
    if (ir==le   && k.y<sorok-1 && t[k.y+1][k.x]!='#') return 1;
    if (ir==bal  && k.x>0       && t[k.y][k.x-1]!='#') return 1;
    if (ir==jobb && k.x<10-1    && t[k.y][k.x+1]!='#') return 1;
    return 0;
}

enum lepes{rossz, kijarat, kincs, ures};

enum lepes leptet(char t[][10], int sorok, enum irany ir) {
    Koord jh = jatekos_helye(t, sorok);
    Koord ujhely=jh;
    char felulirt;
    if (!mehet_e(t, sorok, ir)) return rossz;
    switch(ir) {
        case fel: ujhely.y--; break;
        case le:  ujhely.y++; break;
        case bal: ujhely.x--; break;
        default:  ujhely.x++; break;
    }
    t[jh.y][jh.x]=' ';
    felulirt = t[ujhely.y][ujhely.x];
    t[ujhely.y][ujhely.x] = '@';
    if (felulirt=='$') return kincs;
    else if (ujhely.x==0 || ujhely.x==9 || ujhely.y==0 || ujhely.y==9) return kijarat;

    return ures;
}

int main() {
    char lab[10][10] = {
            {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#'},
            {'#', '$', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
            {'#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#'},
            {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '$', '#'},
            {'#', ' ', '#', '#', '$', '#', ' ', '#', ' ', '#'},
            {'#', '@', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
            {'#', ' ', ' ', ' ', '$', '#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int osszkincs, megtalalt;
    char c;
    enum irany ir;
    enum lepes eredmeny;

    osszkincs=kincsek_szama(lab, 10);
    megtalalt=0;

    do{
        printf("Kincsek: %d/%d\n", megtalalt, osszkincs);
        lab_kiir(lab, 10);
        do{
            c=getchar();
        } while (c!='w' && c!='a' && c!='s' && c!='d');
        switch(c) {
            case 'w': ir=fel; break;
            case 'a': ir=bal; break;
            case 's': ir=le;  break;
            default: ir=jobb; break;
        }
        eredmeny=leptet(lab, 10, ir);
        if (eredmeny==kincs) megtalalt++;

    } while (eredmeny!=kijarat);

    printf("Jatek vege!\n");
    lab_kiir(lab, 10);

    return 0;
}