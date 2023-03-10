//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_STRUCTURE_H
#define AUTOMATE2_STRUCTURE_H
#include "string.h"
#include "stdbool.h"
typedef struct Etat{
    char* nom;
    struct Transitions** listTransitions;
    int* listnbTransitions;
    bool entree, sortie;
}Etat;
typedef struct Transitions{
    Etat* data;
    struct Transitions* next;
}Transitions;
typedef struct Transitions listEtat;
#endif //AUTOMATE2_STRUCTURE_H
