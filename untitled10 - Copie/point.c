//
// Created by tmKla on 28/01/2023.
//

#include "point.h"
point* creer_point(char nom){
    point* newPoint= malloc(sizeof (point));
    newPoint->nom=nom;
    newPoint->voisinsdispo= NULL;
    return newPoint;
}
voisins* creerVoisins(){
    voisins* voisins1= malloc(sizeof (voisins));
    voisins1->data=NULL;
    voisins1->next=NULL;
    return voisins1;
}
chemins* creerChemins(){
    chemins* listChemins= malloc(sizeof (chemins));
    listChemins->nbchemins=0;
    return listChemins;
}
voisins* addVoisins(point* point1, voisins* voisins1){
    voisins* newVoisins=creerVoisins();
    newVoisins->data=point1;
    if (voisins1==NULL){
        return newVoisins;
    }
    voisins* temp=voisins1;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newVoisins;
    return voisins1;
}
voisins* supprvoisins(voisins* voisins1, point* supprpoint){
    if (voisins1==NULL){
        printf("il n'y a plus de voisins\n");
        return NULL;
    }
    voisins* temp=voisins1;
    if (voisins1->data==supprpoint){
        voisins1=voisins1->next;
        free(temp);
        return voisins1;
    }
    while (temp->next->data!=supprpoint){
        temp=temp->next;
    }
    voisins* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
    return voisins1;
}
void relierPoint(point* point1, point* point2, chemins* listChemins){
    point1->voisinsdispo= supprvoisins(point1->voisinsdispo,point2);
    point1->nbvoisinsdispo--;
    point2->voisinsdispo= supprvoisins(point2->voisinsdispo,point1);
    point2->nbvoisinsdispo--;
    listChemins->chemins[listChemins->nbchemins][0]=point1->nom;
    listChemins->chemins[listChemins->nbchemins][1]=point2->nom;
}