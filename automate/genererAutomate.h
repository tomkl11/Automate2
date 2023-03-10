//
// Created by tmKla on 10/03/2023.
//

#ifndef AUTOMATE2_GENERERAUTOMATE_H
#define AUTOMATE2_GENERERAUTOMATE_H

#endif //AUTOMATE2_GENERERAUTOMATE_H
#include "structure.h"
#include "initialisation.h"
Etat* findEtatinList(char *nom,   listEtat* listEtatpres);
Etat *creerchemin(Etat *EtatX, listEtat* listEtatspres, char *listLetrres);
listEtat* creerAutomate(char *listLettres, int nbEtat);