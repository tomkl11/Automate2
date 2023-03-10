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
    NewEtat->nom = nom;
    NewEtat->listvoisins = creervoisins();
    return NewEtat;
}

Etat *ajouterVoisins(Etat *listvoisins, Etat *newvoisin, char lettrepassage) {
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
    int nblettre = strlen(listLetrres),nbvoisin,nbvoisin2;
    int listnbvoisin [nblettre];
    Etat *NewEtat, **pEtat = malloc(sizeof(Etat));
    printf("Etat %s\n",EtatX->nom);
    char** listnumvoisin[nblettre],c[1];
    for (int i = 0; i < nblettre; i++) {
        printf("saisir le nombre d'etat(s) passant par la lettre %c :\n", listLetrres[i]);
        scanf("%d",&nbvoisin);
        nbvoisin2=nbvoisin;
        listnbvoisin[i]=nbvoisin2;
        listnumvoisin[i]= malloc(nbvoisin*sizeof (char));
        printf("saisir le nom des Etats\n");
        for (int j=0; j<nbvoisin2;j++){
            listnumvoisin[i][j]= malloc(1*sizeof (char));
            scanf("%s", c);
            strcpy(listnumvoisin[i][j],c);
        }
    }
    for (int i=0; i<nblettre;i++){
        int taille=listnbvoisin[i];
        for (int j=0;j<taille;j++){
            if (!isinList(listnumvoisin[i][j],listEtatspres,pEtat)){
                NewEtat= creerEtat(listnumvoisin[i][j]);
                EtatX= ajouterVoisins(EtatX,NewEtat,listLetrres[i]);
                listEtatspres=ajouterVoisins(listEtatspres,NewEtat,listLetrres[i]);
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


void displayAutomate(Etat *EtatX, Etat *listEtatprint) {
    Etat *ghost;
    if (!isinList(EtatX->nom, listEtatprint, &ghost)) {
        listEtatprint = ajouterVoisins(listEtatprint, EtatX, ' ');
        voisins *temp = EtatX->listvoisins;
        printf("%s [", EtatX->nom);
        while (temp != NULL) {
            printf("%c  : (", temp->lettrepassage);
            char lettre=temp->lettrepassage;
            while (temp!=NULL && temp->lettrepassage==lettre){
                printf("%s ; ", temp->data->nom);
                temp = temp->next;
            }
            printf(")");

        }
        printf("]\n");
        temp = EtatX->listvoisins;
        while (temp != NULL) {
            displayAutomate(temp->data, listEtatprint);
            temp = temp->next;
        }
    }


}

void displayWordinAutomate(Etat *Automate);