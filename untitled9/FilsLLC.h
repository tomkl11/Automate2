//
// Created by tmKla on 28/10/2022.
//

#ifndef UNTITLED9_PARTIE1LLC_H
#define UNTITLED9_PARTIE1LLC_H
#define NOM 0
#define ADJ 1
#define VERBE 2
#define ADV 3
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
typedef struct Nom{
    int genre;
    char* ecriture[2];
    char* determinant[2];
}Nom;
typedef struct Adj{
    char* ecriture[2][2];
}Adj;
typedef struct Verbe{
    char* infinitf;
    char* conjugaison[3][3][2];

}Verbe;
typedef struct Nature{
    Nom nom;
    Adj adj;
    Verbe verbe;
}Nature;
#endif //UNTITLED9_PARTIE1LLC_H
typedef struct Node{
    char lettre;
    struct List* ListFils;
    int nbFils;
    Nature* nature;
}Node;
typedef struct List{
    Node* data;
    struct List* next;
}List;

typedef struct Tree{
    Node* root;
}Tree;
Nom creerNom();
Adj creerAdj();
Verbe creerVerbe();
Nature* creerNature();
Tree* creerArbrDico();
Node* creerNode();
List* creerList();
int isLetterExist(List* ListFils, char c);
List* addtoEndList(List* ListFils,char c);
Node *addLetterToDic0(Node *node, char *mot, int i, int *nbAction);
Node* addWordToDic0(Tree** Arbre,char* mot,int nature, int* nbAction);
Node *goToTheRandomNode(List *ListFils, int numFils);
Node *displayRandomLetter(Node *node);
Node* displayRandomWord(Tree* Arbre, int nature);
void displaysentence(Tree*);

//fléchir les mots
void FlechirNom(char* motF,Node* nodemot,int genre, int nombre);
void FlechirAdj(char* motF,Node* nodemot,int genre, int nombre);
void FlechirVerbe(char* motF,Node* nodemot,int temps,int pers, int nombre);


//fonction debug
void displayFormFlechieNom(Nom nom);
void displayFormFlechieAdj(Adj adj);
void displayAllSons(List *listFils);
