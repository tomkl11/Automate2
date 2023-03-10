//
// Created by tmKla on 09/02/2023.
//
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
typedef struct Etat{
    char* nom;
    struct Transition** listTransitions;
    int* listnbTransitions;
    bool entree;
    bool sortie;
}Etat;
typedef struct Transition{
    Etat* data;
    struct Transition* next;
}Transition;
typedef struct Transition listEtat;
Etat* creerEtat( char*, int);
void ajouterLiasons(Etat* EtatX, Etat *newvoisin, int);
listEtat* creerAutomate(char* listletttres, int nbEtat);
void displayAutomate(listEtat* Automate, char*);