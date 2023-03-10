#include "automate.h"

voisins *creervoisins() {
    voisins *NewList = malloc(sizeof(voisins));
    NewList->data = NULL;
    NewList->next = NULL;
    return NewList;
}

Etat *creerEtat(char *nom) {
    Etat *NewEtat = malloc(sizeof(Etat));
    NewEtat->nbvoisins = 0;
    NewEtat->nom= malloc(strlen(nom));
    strcpy(NewEtat->nom,nom);
    NewEtat->listvoisins = creervoisins();
    return NewEtat;
}

Etat *ajouterVoisins(Etat *listvoisins, Etat *newvoisin, char lettrepassage) {
    listvoisins->nbvoisins++;
    voisins *NewList = creervoisins(), *temp;
    NewList->lettrepassage = lettrepassage;
    NewList->data = newvoisin;
    if (listvoisins->listvoisins->data == NULL) {
        listvoisins->listvoisins = NewList;
        return listvoisins;
    }
    temp = listvoisins->listvoisins;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = NewList;
    return listvoisins;

}

Etat *dupliquerEtat(Etat *Etatdupli) {
    Etat *ClownEtat = creerEtat("listEtat");
    voisins *temp = Etatdupli->listvoisins;
    while (temp != NULL) {
        ClownEtat = ajouterVoisins(ClownEtat, temp->data, '0');
        temp = temp->next;
    }
    return ClownEtat;

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

bool isinList(char *nom, Etat *listEtats, Etat **pEtat) {
    voisins *temp = listEtats->listvoisins;
    if (temp->data == NULL) {
        return false;
    }
    bool same = isSameWord(temp->data->nom, nom);
    while (temp->next != NULL && !same) {
        temp = temp->next;
        same = isSameWord(temp->data->nom, nom);
    }
    if (same) {
        *pEtat = temp->data;
        return true;
    }
    return false;
}

Etat *ajouterEntree(int nbentree) {
    Etat *Automate = creerEtat("Entree(s)"), *NewEtat, *temp;
    char *nom = malloc(sizeof(char));
    printf("saisir les etats d'entree\n");
    for (int i = 0; i < nbentree; i++) {
        scanf("%s", nom);
        NewEtat = creerEtat(nom);
        Automate = ajouterVoisins(Automate, NewEtat, nom[0]);
    }
    return Automate;
}

Etat *creerchemin(Etat *EtatX, Etat *listEtatspres, char *listLetrres) {
    int nblettre = strlen(listLetrres),taille;
    Etat *NewEtat, **pEtat = malloc(sizeof(Etat));
    printf("Etat %s\n",EtatX->nom);
    char* c= malloc(10), *listnumvoisin[nblettre], *c2= malloc(1);
    for (int i = 0; i < nblettre; i++) {
        listnumvoisin[i]= malloc(10);
        printf("saisir le nom de tous les etats de la lettre %c :\n",listLetrres[i]);
        scanf("%s",listnumvoisin[i]);
    }
    for (int i=0; i<nblettre;i++){
        taille= strlen(listnumvoisin[i]);
        for (int j=0;j<taille;j++){
            c2[0]=listnumvoisin[i][j],c2[1]='\0';
            if(!isinList(c2,listEtatspres,pEtat)){
                NewEtat= creerEtat(c2);
                EtatX= ajouterVoisins(EtatX,NewEtat,listLetrres[i]);
                listEtatspres= ajouterVoisins(listEtatspres,NewEtat,' ');
                NewEtat= creerchemin(NewEtat,listEtatspres,listLetrres);
            }
            else{
                EtatX= ajouterVoisins(EtatX,*pEtat,listLetrres[i]);
            }
        }
    }
    return EtatX;

}

Etat *creerAutomate(char *listLettres, int nbentree){
    Etat *Automate = ajouterEntree(nbentree);
    Etat *listEtatspres = dupliquerEtat(Automate);
    voisins *temp = Automate->listvoisins;
    int numvoisin;
    while (temp != NULL) {
        temp->data = creerchemin(temp->data, listEtatspres, listLettres);
        temp = temp->next;
    }
    return Automate;

}
void displayEtat(Etat* EtatX,Etat* listEtatprint){
    Etat *ghost;
    if (!isinList(EtatX->nom, listEtatprint, &ghost)) {
        listEtatprint = ajouterVoisins(listEtatprint, EtatX, ' ');
        voisins *temp = EtatX->listvoisins;
        printf("  %s       |", EtatX->nom);
        while (temp != NULL) {
            char lettre=temp->lettrepassage;
            while (temp!=NULL && temp->lettrepassage==lettre){
                printf("%s, ", temp->data->nom);
                temp = temp->next;
            }
            printf("  |");

        }
        printf("\n");
        temp = EtatX->listvoisins;
        while (temp != NULL) {
            displayEtat(temp->data, listEtatprint);
            temp = temp->next;
        }
    }
}

void displayAutomate(Etat *Automate, char* listlettre) {
    int size= strlen(listlettre);
    printf("Etats     ");
    for (int i=0; i<size;i++){
        printf("|  %c  ",listlettre[i]);
    }
    printf("|\n");
    size=Automate->nbvoisins;
    voisins* temp= Automate->listvoisins; Etat * listEtatprint= creerEtat("");
    for (int i=0;i<size;i++){
        displayEtat(temp->data,listEtatprint);
        temp=temp->next;
    }


}


void displayWordinAutomate(Etat *Automate);