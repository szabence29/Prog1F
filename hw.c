#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void ertekadas(char **hova, char *mit) {
    free(*hova);
    *hova = (char*) malloc((strlen(mit) + 1) * sizeof(char));
    strcpy(*hova, mit);
}
void hozzafuz(char **str, char mit) {
    char *uj = (char*) malloc((strlen(*str) + 2) * sizeof(char));
    printf("%s%c\n", *str, mit);
    sprintf(uj, "%s%c", *str, mit);
    free(*str);
    *str = uj;
}

int main() {
    char *akt = NULL, *legh = NULL;
    ertekadas(&akt, "");
    ertekadas(&legh, "");
    int c;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            hozzafuz(&akt, c);
            printf("%s\n", akt);
        } else {
            if (strlen(akt) > strlen(legh))
                ertekadas(&legh, akt);
            ertekadas(&akt, "");
        }
    }
    printf("leghosszabb: %s\n", legh);
    free(akt);
    free(legh);

    return 0;
}