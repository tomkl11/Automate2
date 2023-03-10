//
// Created by tmKla on 28/10/2022.
//

#include "FilsLLC.h"
Nom creerNom(){
    Nom nom;
    nom.ecriture[0]=nom.ecriture[1]=NULL;
    return nom;
}
Adj creerAdj(){
    Adj adj;
    for (int i=0; i<2;i++){
        for (int j=0;j<2;j++){
            adj.ecriture[i][j]=NULL;
        }
    }
    return adj;
}
Verbe creerVerbe(){
    Verbe verbe;
    verbe.infinitf=NULL;
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for (int k=0;k<2;k++){
                verbe.conjugaison[i][j][k]=NULL;
            }
        }
    }
    return verbe;
}
Nature* creerNature(){
    Nature* nature= malloc(sizeof (Nature));
    nature->nom=creerNom();
    nature->adj=creerAdj();
    nature->verbe=creerVerbe();
    return nature;
}
Node *creerNode() {
    Node *newNode = malloc(sizeof(Node));
    newNode->lettre = '.';
    newNode->ListFils = creerList();
    newNode->nbFils = 0;
    newNode->nature=creerNature();
    return newNode;
}

List *creerList() {
    List *newList = malloc(sizeof(List));
    newList->data = NULL;
    newList->next = NULL;
    return newList;
}

Tree *creerArbrDico() {
    Tree *arbreDico = malloc(sizeof(Tree));
    arbreDico->root = malloc(sizeof(Node));
    List *temp = arbreDico->root->ListFils = creerList();
    temp->data = creerNode();
    temp->data->lettre = '0';
    for (int i = 0; i < 3; i++) {
        temp = temp->next = creerList();
        temp->data = creerNode();
        temp->data->lettre = (char) (i + 49);
    }
    return arbreDico;
}

void displayAllSons(List *listFils) {
    List *temp = listFils;
    while (temp != NULL) {
        printf("%c", temp->data->lettre);
        temp = temp->next;
    }
}

int isLetterExist(List *ListFils, char c) {
    List *temp = ListFils;
    if (temp->data == NULL) {
        return 0;
    }
    while (temp->next != NULL && temp->data->lettre != c) {
        temp = temp->next;
    }
    return temp->data->lettre == c;
}

List *addtoEndList(List *ListFils, char c) {
    List *newList = creerList();
    newList->data = creerNode();
    newList->data->lettre = c;
    if (ListFils->data == NULL) {
        ListFils = newList;
        return ListFils;
    }
    List *temp = ListFils;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newList;
    return ListFils;

}

Node *addLetterToDic0(Node *node, char *mot, int i, int *nbAction) {
    if (i == strlen(mot)) {
        if (*nbAction > 0) {
            node->ListFils = addtoEndList(node->ListFils, '.');
            node->nbFils++;
        }
        return node->ListFils->data;
    }
    if (isLetterExist(node->ListFils, mot[i]) == 0) {
        node->ListFils = addtoEndList(node->ListFils, mot[i]);
        node->nbFils++;
        (*nbAction)++;
    }
    List *temp = node->ListFils;
    while (temp->data->lettre != mot[i]) {
        temp = temp->next;
    }
    return addLetterToDic0(temp->data, mot, i + 1, nbAction);

}

Node *addWordToDic0(Tree **Arbre, char *mot, int nature, int *nbAction) {
    Node *Root = (*Arbre)->root;
    List *root = Root->ListFils;
    for (int i = 0; i < nature; i++) {
        root = root->next;
    }
    int lenWord = strlen(mot);
    return addLetterToDic0(root->data, mot, 0, nbAction);


}

Node *goToTheRandomNode(List *ListFils, int numFils) {
    List *temp = ListFils;
    int cpt = 0;
    while (cpt < numFils) {
        temp = temp->next;
        cpt++;
    }
    return temp->data;
}

Node *displayRandomLetter(Node *node) {
    if (node->lettre == '.') {
        printf(" ");
        return node;
    }
    int numFils = rand() % (node->nbFils);
    node = goToTheRandomNode(node->ListFils, numFils);
    if (node->lettre != '.') {
        printf("%c", node->lettre);
    }
    return displayRandomLetter(node);
}

Node *displayRandomWord(Tree *Arbre, int nature) {
    Node *root = goToTheRandomNode(Arbre->root->ListFils, nature);
    return displayRandomLetter(root);
}


void FlechirNom(char *motF, Node *nodemot, int genre, int nombre) {
    nodemot->nature->nom.genre = genre;
    if (genre == 0) {
        nodemot->nature->nom.determinant[0] = "le";
    } else {
        nodemot->nature->nom.determinant[0] = "la";
    }
    nodemot->nature->nom.determinant[1] = "les";
    nodemot->nature->nom.ecriture[nombre] = motF;
}

void FlechirAdj(char *motF, Node *nodemot, int genre, int nombre) {
    if (genre==2){
        nodemot->nature->adj.ecriture[0][nombre] = motF;
        nodemot->nature->adj.ecriture[1][nombre] = motF;
    }
    else{
        nodemot->nature->adj.ecriture[genre][nombre] = motF;
    }
}

void FlechirVerbe(char *motF, Node *nodemot, int temps, int pers, int nombre) {
    nodemot->nature->verbe.conjugaison[temps][pers][nombre] = motF;
}
void displayFormFlechieNom(Nom nom){
    printf("\n%s %s\n",nom.ecriture[0],nom.ecriture[1]);
}
void displayFormFlechieAdj(Adj adj){
    printf("\n");
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            printf("%s ",adj.ecriture[i][j]);
        }
    }
    printf("\n");
}
void displaysentence(Tree *Arbre) {
    srand(time(NULL));
    Node *nom = displayRandomWord(Arbre, NOM);
    Node *adj = displayRandomWord(Arbre, ADJ);
    Node *verbe= displayRandomWord(Arbre,VERBE);
    displayRandomWord(Arbre,ADV);
    printf("\n");
    int genre = nom->nature->nom.genre, nombre = rand() % 2,temps=rand()%7;
    char *determinant = nom->nature->nom.determinant[nombre], *nomF = nom->nature->nom.ecriture[nombre];
    char *adjF = adj->nature->adj.ecriture[genre][nombre];
    char *verbeF=verbe->nature->verbe.conjugaison[temps][2][nombre];
    printf("%s %s %s %s ", determinant, nomF,adjF,verbeF);
    displayRandomWord(Arbre,ADV);

}