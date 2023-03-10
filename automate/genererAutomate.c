//
// Created by tmKla on 10/03/2023.
//

#include "genererAutomate.h"
bool isSameWord(char *mot1, char *mot2) {
    int taille = strlen(mot1);
    if (taille != strlen(mot2)) {
        return false;
    }
    int i = 0;
    while (i < taille - 1 && mot1[i] == mot2[i]) {
        i++;
    }
    return mot1[i] == mot2[i];
}

Etat* findEtatinList(char *nom,   listEtat* listEtatpres) {
    listEtat* temp=listEtatpres;
    while (temp!=NULL && !isSameWord(temp->data->nom,nom)){
        temp=temp->next;
    }
    return temp->data;
}


Etat *creerchemin(Etat *EtatX, listEtat* listEtatspres, char *listLetrres) {
    int nblettre = strlen(listLetrres),nbtransition;
    int listnbtrnasition [nblettre];
    Etat *NewEtat, *EtatLie;Transition * list;
    char** listnomtransition[nblettre],c[1];
    for (int i = 0; i < nblettre; i++) {
        listnbtrnasition[i]=nbtransition;
        listnomtransition[i]= malloc(nbtransition * sizeof (char*));
        for (int j=0; j < nbtransition; j++){
            listnomtransition[i][j]= malloc(1 * sizeof (char));
        }
    }
    for (int i=0; i<nblettre;i++){
        int taille=listnbtrnasition[i];
        for (int j=0;j<taille;j++){
            EtatLie= findEtatinList(listnomtransition[i][j], listEtatspres);
            ajouterTransition(EtatX, EtatLie, i);
        }
    }
    return EtatX;

}

listEtat* creerAutomate(char *listLettres, int nbEtat){
    listEtat* Automate= creerListEtat(),*temp;
    ajouterEtat(Automate,nbEtat, strlen(listLettres));
    temp=Automate;
    while (temp!=NULL){
        temp->data= creerchemin(temp->data,Automate,listLettres);
        temp=temp->next;
    }
    return Automate;

}