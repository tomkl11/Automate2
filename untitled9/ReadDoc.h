//
// Created by tmKla on 04/11/2022.
//

#ifndef UNTITLED9_READDOC_H
#define UNTITLED9_READDOC_H
#define NOM 0
#define ADJ 1
#define VERBE 2
#define ADV 3
#endif //UNTITLED9_READDOC_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char* getWord(FILE* f, char* c);
int getNature(FILE* f, char* c);
int getgenre(FILE* f, char* c);
int getTemps(FILE* f, char* c);
int getPers(FILE* f, char* c);
int getNombre(FILE* f, char* c);