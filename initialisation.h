//
// Created by tmKla on 10/03/2023.
//
#include "structure.h"

#ifndef AUTOMATE2_INITIALISATION_H
#define AUTOMATE2_INITIALISATION_H
listEtat *creerListEtat();
Transition *crrerTransition();
Etat *creerEtat(char *nom, int nblettre);
void ajouterTransition(Etat* EtatX, Etat * EtatLie, int num);

#endif //AUTOMATE2_INITIALISATION_H
