#include <stdio.h>

typedef struct Koordinata{
    int x, y;
} Koordinata;

int kincsek(char t[10][10], int sorok) {
    int db=0;
    for (int i=0; i<sorok; i++)
        for (int j=0; j<10; j++)
            if (t[i][j]=='$') db++;
    return db;
}

void labirintus_kiir(char t[10][10], int sorok) {
    for (int i=0; i<sorok; i++) {
        for (int j=0; j<10; j++) printf("%c", t[i][j]);
        printf("\n");
    }
}

Koordinata jatekos(char t[][10], int sorok) {
    Koordinata k;
    for (int i=0; i<sorok; i++) {
        for (int j=0; j<10; j++) {
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

enum irany{kincs};

int main() {
    char labirintus[10][10] = {
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

    labirintus_kiir(labirintus, 10);

    return 0;
}