//
// Created by tmKla on 21/10/2022.
//
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#ifndef UNTITLED9_PARTIE1_H
#define UNTITLED9_PARTIE1_H
#define NOM 0
#define ADJ 1


typedef struct Nom{
    int tab[2];
    int genre;
}Nom;
typedef struct Adj{
    Nom nom;
    int tab[2][2];
}Adj;
typedef struct Nature{
    Nom nom;
    Adj adj;
}Nature;
typedef struct Cell{
    Nature nature;
    char lettre;
    struct Cell**  Listfils;
    int nbFils;
}Cell;
typedef struct Root{
    Cell* Listfils;
}Root;
typedef struct ArbrDico{
    Root root;
}ArbrDico;
Cell* creerCell();
ArbrDico* creerArbbrDico();
int isLetterexist(Cell* , char);
void addWordToDico(char* mot,int nature, ArbrDico**);
// fonction mot aléatoire
//fonction display mot de base
//générer les mots
// générer phrase avec mots de base aléatoires


#endif //UNTITLED9_PARTIE1_H
