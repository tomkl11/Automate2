//
// Created by tmKla on 10/03/2023.
//

#include "initialisation.h"
Transition *crrerTransition() {
    Transition *NewList = malloc(sizeof(Transition));
    NewList->data = NULL;
    NewList->next = NULL;
    return NewList;
}
listEtat *creerListEtat(){
    return creerTransition();
}

Etat *creerEtat(char *nom, int nblettre) {
    Etat *NewEtat = malloc(sizeof(Etat));
    NewEtat->nom = nom;
    NewEtat->listTransitions = malloc(sizeof (Transition));
    NewEtat->listnbTransitions= malloc(nblettre * sizeof (int));
    for (int i=0;i<nblettre;i++){
        NewEtat->listTransitions[i]= creerTransition();
        NewEtat->listnbTransitions[i]=0;
    }
    return NewEtat;
}

void ajouterTransition(Etat* EtatX, Etat * EtatLie, int num) {
    Transition *NewList = creerTransition(), *temp=EtatX->listTransitions[num];
    NewList->data = EtatLie;
    EtatX->listnbTransitions[num]++;
    if (temp->data == NULL) {
        *temp = *NewList;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = NewList;

}