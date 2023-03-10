//
// Created by tmKla on 09/02/2023.
//
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
typedef struct Etat{
    char* nom;
    struct voisins* listvoisins;
    int nbvoisins;
}Etat;
typedef struct voisins{
    char lettrepassage;
    Etat* data;
    struct voisins* next;
}voisins;
Etat* creerEtat( char*);
Etat* ajouterVoisins(Etat* listvoisins, Etat* newvoisin,char );
Etat* creerAutomate(char* listletttres, int nbentree);
void displayAutomate(Etat* Automate,char*);
void displayWordinAutomate(Etat* Automate);