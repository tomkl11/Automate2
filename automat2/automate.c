#include "automate.h"

Transition *creerTransition() {
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

listEtat* ajouterEtat(listEtat* Automate,int nbEtat, int nblettre) {
    char* list[4]={"0","1","2","3"};
    listEtat* temp=Automate;
    for (int i=0; i<nbEtat;i++){
        temp->data= creerEtat(list[i],nblettre);
        if (i<nbEtat-1){
            temp->next= creerListEtat();
        }
        temp=temp->next;
    }
    return Automate;
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


void displayAutomate(listEtat* Automate, char* listLettres) {
    int nblettres= strlen(listLettres);
    listEtat * temp=Automate; Transition *liaisons1;
    printf("Etats\t|");
    for (int i=0; i<nblettres;i++){
        printf("\t%c\t|", listLettres[i]);
    }
    printf("\n");
    printf("----------------------\n");
    while (temp!=NULL){
        printf("%s\t|\t",temp->data->nom);
        for (int i=0;i<nblettres;i++){
            liaisons1=temp->data->listTransitions[i];
            while (liaisons1!=NULL){
                printf("%s,", liaisons1->data->nom);
                liaisons1=liaisons1->next;
            }
            printf("\t|\t");
        }
        printf("\n");
        printf("-------\t-------\t-------\t\n");
        temp=temp->next;
    }

}

