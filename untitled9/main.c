#include <stdio.h>
#include "FilsLLC.h"
#include "ReadDoc.h"

void GenerateSentence() {
    Tree *arbreDico = creerArbrDico();
    FILE *f = fopen("Notre Dico Projet.txt", "rt");
    char *motF, *mot, c;
    int nature, genre, nombre,pers,temps, nbAction,ligne=0;
    Node *nodeMot;
    while (c != EOF) {
        nbAction = 0;
        motF = getWord(f,&c);
        mot = getWord(f,&c);
        nature = getNature(f,&c);
        c= fgetc(f);
        nodeMot = addWordToDic0(&arbreDico, mot, nature, &nbAction);
        if (nature == NOM || nature == ADJ) {
            genre = getgenre(f,&c);
            nombre = getNombre(f,&c);
            if (nature == NOM) {
                FlechirNom(motF, nodeMot, genre, nombre);

            } else {
                FlechirAdj(motF, nodeMot, genre, nombre);
            }
        }
        else {
            if (nature==VERBE){
                if (nbAction>0){
                    nodeMot->nature->verbe.infinitf=mot;
                }
                while (c==':'){
                    temps= getTemps(f,&c);
                    if (temps!=-1){
                        nombre= getNombre(f,&c);
                        pers= getPers(f,&c);
                        FlechirVerbe(motF,nodeMot,temps,pers,nombre);
                    }
                }
            }

        }
        ligne++;
        if (ligne==30){
            int x=1;
        }

    }
    displaysentence(arbreDico);
}


int main() {
    GenerateSentence();



    return 0;
}



































