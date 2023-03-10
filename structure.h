//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_STRUCTURE_H
#define AUTOMATE2_STRUCTURE_H
typedef struct Etat{
    char* nom;
    struct liaisons** listLiaisons;
    int* listnbvoisins;
}Etat;
typedef struct liaisons{
    Etat* data;
    struct liaisons* next;
}liaisons;
typedef struct liaisons listEtat;
#endif //AUTOMATE2_STRUCTURE_H
