//
// Created by tmKla on 05/10/2022.
//
#include "stdlib.h"
#ifndef UNTITLED7_ARBRE_BINAIR_H

#define UNTITLED7_ARBRE_BINAIR_H
#include "bst.h"

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;
typedef struct Node* p_node;

typedef struct Tree {
    Node *root;

}Tree;

p_node createNode(int value);
Tree* createTree();
Tree* createTreeFromNode(Node* pNode);
void displayTree(Tree* tree);
int maxInTree(Tree* tree);
int SumFromTree(Tree* tree);
int getSumAndNbNodesFromTree(Tree* tree, int* nbNodes);
int highTree(Tree* tree);
float avgTree(Tree *tree);
int countNbOccurrenceInTree( Tree* tree, int value);
void displayTreePrefix(Tree* tree);
void displayTreeInfix(Tree* tree);
void displayTreePostfix(Tree* tree);
int BalanceTree(Tree* tree);
#endif //UNTITLED7_ARBRE_BINAIR_H