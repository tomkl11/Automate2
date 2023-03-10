//
// Created by tmKla on 10/03/2023.
//

#include "initialisation.h"
liaisons *creerLiasions() {
    liaisons *NewList = malloc(sizeof(liaisons));
    NewList->data = NULL;
    NewList->next = NULL;
    return NewList;
}
listEtat *creerListEtat(){
    return creerLiasions();
}

Etat *creerEtat(char *nom, int nblettre) {
    Etat *NewEtat = malloc(sizeof(Etat));
    NewEtat->nom = nom;
    NewEtat->listLiaisons = malloc(sizeof (liaisons));
    NewEtat->listnbliaisons= malloc(nblettre * sizeof (int));
    for (int i=0;i<nblettre;i++){
        NewEtat->listLiaisons[i]=creerLiasions();
        NewEtat->listnbliaisons[i]=0;
    }
    return NewEtat;
}