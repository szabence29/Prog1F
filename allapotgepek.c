#include "stdio.h"
#include "ctype.h"

typedef enum LyAllapot {
    alap, l_volt, ll_volt
} LyAllapot;

void helyesiras(){
    LyAllapot allapot;
    allapot = alap;
    int c;
    while ((c = getchar()) != EOF) {
        switch (allapot) {
            case alap:
                if (c == 'l' || c == 'L')
                    allapot = l_volt;
                else
                    putchar(c);
                break;

            case l_volt:
                switch (tolower(c)) {
                    case 'l':
                        allapot = ll_volt;
                        break;
                    case 'y':
                        putchar('j');
                        allapot = alap;
                        break;
                    case 'L':
                        allapot = ll_volt;
                        break;
                    case 'Y':
                        putchar('J');
                        allapot = alap;
                    default:
                        allapot = alap;
                        break;
                }
                break;

            case ll_volt:
                switch (tolower(c)) {
                    case 'l':
                        putchar(c);
                        break;
                    case 'y':
                        putchar('j');
                        putchar('j');
                        allapot = alap;
                        break;
                    case 'L':
                        putchar(c);
                        break;
                    case 'Y':
                        putchar('J');
                        putchar('J');
                        allapot = alap;
                    default:
                        putchar('l');
                        putchar('l');
                        putchar(c);
                        allapot = alap;
                        break;
                }
                break;
        }
    }
}

void file_helyesiras(){
    FILE* fp1 = fopen("eredeti.txt", "r");
    FILE* fp2 = fopen("megformalt.txt", "w");
    if (fp1 == NULL)
    {
        printf("Nem sikerült beolvasni a .txt filet!");
    }

    LyAllapot allapot;
    allapot = alap;
    int c;

    while ((c = fgetc(fp1)) != EOF) {
        switch (allapot) {
            case alap:
                if (tolower(c) == 'l')
                    allapot = l_volt;
                else
                    fputc(c, fp2);
                break;

            case l_volt:
                switch (tolower(c)) {
                    case 'l':
                        allapot = ll_volt;
                        break;
                    case 'y':
                        if (c == tolower(c))
                            fputc('j', fp2);
                        else if (c == toupper(c))
                            fputc('J', fp2);
                        allapot = alap;
                        break;
                    default:
                        allapot = alap;
                        break;
                }
                break;

            case ll_volt:
                switch (tolower(c)) {
                    case 'l':
                        fputc(c, fp2);
                        break;
                    case 'y':
                        if (c == tolower(c)){
                            fputc('j', fp2);
                            fputc('j', fp2);
                        }else if (c == toupper(c)){
                            fputc('J', fp2);
                            fputc('J', fp2);
                        }
                        allapot = alap;
                        break;
                    default:
                        fputc('l', fp2);
                        fputc('l', fp2);
                        fputc(c, fp2);
                        allapot = alap;
                        break;
                }
                break;
        }
    }


}


int main(void) {
    //helyesiras();
    file_helyesiras();
    return 0;
}