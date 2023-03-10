//
// Created by tmKla on 14/10/2022.
//

#ifndef UNTITLED7_BST_H
#define UNTITLED7_BST_H
#include "arbre_binair.h"
#include <stdio.h>
typedef Tree BST;

void insertValueInBST(BST* bst,int value);
void rotateLeft(Tree *bst, int valueToRotate);
void rotateRight(BST *bst, int valueToRotate);


#endif //UNTITLED7_BST_H
