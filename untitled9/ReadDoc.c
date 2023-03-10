//
// Created by tmKla on 04/11/2022.
//

#include "ReadDoc.h"

int sameWord(char *c1, char *c2, int size) {
    int i = 0;
    while (i < size - 1 && c1[i] == c2[i]) {
        i++;
    }
    return c1[i] == c2[i];
}

char *getWord(FILE *f, char *c) {
    *c = fgetc(f);
    char *mot = malloc(20 * sizeof(char));
    int i = 0;
    while (*c != '\t' && *c != EOF) {
        mot[i] = *c;
        i++;
        *c = fgetc(f);

    }
    mot[i] = '\0';
    return mot;
}

int getNature(FILE *f, char *c) {
    char nature[3];
    for (int i = 0; i < 3; i++) {
        *c = fgetc(f);
        nature[i] = *c;
    }
    if (sameWord(nature, "Nom", 3) == 1) {
        return NOM;
    }
    if (sameWord(nature, "Adj", 3) == 1) {
        return ADJ;
    }
    if (sameWord(nature, "Verbe", 3) == 1) {
        return VERBE;
    }
    return ADV;
}

void gotoThenextline(FILE *f, char *c) {
    while (*c != '\n' && *c != EOF) {
        *c = fgetc(f);
    }
}

int getgenre(FILE *f, char *c) {
    char genre[6];
    *c = fgetc(f);
    int i = 0;
    while (*c != '+') {
        genre[i] = *c;
        *c = fgetc(f);
        i++;
    }
    if (sameWord(genre, "Mas", 3)) {
        return 0;
    }
    if (sameWord(genre, "Fem", 3)) {
        return 1;
    }
    return 2;
}

int getNombre(FILE *f, char *c) {
    char nombre[2];
    int i = 0;
    *c = fgetc(f);
    while (*c != '+' && *c != '\n' && *c != EOF) {
        nombre[i] = *c;
        *c = fgetc(f);
        i++;
    }

    return sameWord(nombre, "PL", 2);
}

int getTemps(FILE* f, char* c){
    char temps[4];
    int i=0;
    *c= fgetc(f);
    while (*c!='+' && *c!='\n' && *c!=EOF){
        temps[i]=*c;
        *c= fgetc(f);
        i++;
    }
    if (sameWord(temps,"Inf",3)){
        return -1;
    }
    if (sameWord(temps,"IPre",4)){
        return 0;
    }
    if (sameWord(temps,"IImp",4)){
        return 1;
    }
    return 2;
}

int getPers(FILE *f, char *c) {
    char pers[2];
    int i = 0;
    *c = fgetc(f);
    while (*c != ':' && *c != '\n' && *c != EOF) {
        pers[i] = *c;
        *c = fgetc(f);
        i++;
    }
    if (sameWord(pers, "P1", 2) == 1) {
        return 0;
    }
    if (sameWord(pers, "P2", 2) == 1) {
        return 1;
    }
    return 2;
}