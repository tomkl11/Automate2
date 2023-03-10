//
// Created by tmKla on 21/10/2022.
//

#include "BourrinEasy.h"
Cell* creerCell(){
    Cell* newCell= malloc(sizeof (Cell));
    newCell->Listfils= malloc(26*sizeof (Cell));
    newCell->nbFils=0;
    newCell->lettre='0';
    newCell->Listfils[0]=NULL;
    return newCell;
}
ArbrDico* creerArbbrDico(){
    ArbrDico* dico= malloc(sizeof (ArbrDico));
    Root* root=&(dico->root);
    root->Listfils= malloc(4*sizeof (Cell));
    Cell* Nom=&(root->Listfils[0]), *Adj=&(root->Listfils[1]),*Verbe=&(root->Listfils[2]),*Adv=&(root->Listfils[3]);
    Nom->Listfils=Adj->Listfils=Verbe->Listfils=Adv->Listfils= malloc(26*sizeof (Cell));
    Nom->lettre='N',Adj->lettre='A';
    Nom->nbFils=Adj->nbFils=Adv->nbFils=0;
    return dico;


}
int isLetterexist(Cell* cell, char c){
    if (cell->Listfils[0]==NULL || cell->nbFils==0){
        return -1;
    }
    Cell* cell2= cell->Listfils[0];
    int j=0;
    while ((j<cell->nbFils-1) &&(cell2->lettre!=c) ){
        j++;
        cell2=(cell->Listfils[j]);
    }

    if (cell2->lettre==c){
        return j;
    };
    return -1;
}
void addWordToDico(char* mot,int nature, ArbrDico** dico){

    unsigned long long len= strlen(mot);
    Root* root;
    root=&((*dico)->root);
    Cell* temp,*temp2;
    temp = &(root->Listfils[nature]);//nom:0 ,adj :1, verbe: 2, adv: 2
    int indiceletter;
    for (int i=0; i<len;i++){
        indiceletter= isLetterexist(temp,mot[i]);
        if (indiceletter==-1){
            temp->Listfils[temp->nbFils]= creerCell();
            temp2=temp->Listfils[temp->nbFils];
            temp2->lettre=mot[i];
            temp2->nbFils=0;
            temp->nbFils++;
        }
        else{
            temp2=temp->Listfils[indiceletter];
        }
        temp=temp2;
    }
    temp->Listfils[temp->nbFils]=creerCell();
    temp->nbFils++;

}