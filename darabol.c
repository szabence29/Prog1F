#include "stdio.h"
#include "string.h"

void darabol(char **tomb, char *sztring){
    char *t = strtok(sztring, ";");
    while (t != NULL){
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < 1; ++j) {
                tomb[i][j] = t[j];
            }
        }
        t = strtok(NULL, ";");
    }
}

int main(void){
    char tomb[3][3];
    darabol((char **) tomb, "Szabó Bence;LV08C9;A12");
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 1; ++j) {
            printf("%c", tomb[i][j]);
        }
    }
}