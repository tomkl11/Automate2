//
// Created by tmKla on 05/10/2022.
//
#include "stdio.h"
#include "arbre_binair.h"
#include "math.h"

Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

Tree *createTree() {
    Tree *newTree = malloc(sizeof(Tree));
    if (newTree != NULL) {
        newTree->root = NULL;
    }
    return newTree;
}

Tree *createTreeFromNode(Node *pNode) {
    Tree *newTree = createTree();
    if (newTree != NULL) {
        newTree->root = pNode;
    }
    return newTree;
}

void displayNode(Node *node) {
    if (node != NULL) {
        printf("%d(", node->value);
        displayNode(node->left);
        printf(" , ");
        displayNode(node->right);
        printf(")");
    } else {
        printf("-");
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

void displayTree(Tree *tree) {
    displayNode(tree->root);
}

int maxInNode(Node *node) {
    int maximum = node->value;
    if (node->left != NULL) {
        maximum = max(maximum, maxInNode(node->left));
    }
    if (node->right != NULL) {
        maximum = max(maximum, maxInNode(node->right));
    }
    return maximum;
}

int maxInTree(Tree *tree) {
    if (tree->root != NULL) {
        return maxInNode(tree->root);
    } else {
        return -9999999999;
    }
}

int getSumAndNbNodesFromNodes(Node *node, int *nbNodes) {
    int sum = node->value;
    (*nbNodes)++;
    if (node->left != NULL) {
        sum += getSumAndNbNodesFromNodes(node->left, nbNodes);
    }
    if (node->right != NULL) {
        sum += getSumAndNbNodesFromNodes(node->right, nbNodes);
    }
    return sum;
}

int getSumAndNbNodesFromTree(Tree *tree, int *nbNodes) {
    if (tree->root != NULL) {
        return getSumAndNbNodesFromNodes(tree->root, nbNodes);
    }
}

float avgTree(Tree *tree) {
    int nbNodes = 0;
    if (tree->root != NULL) {
        float res = (float) getSumAndNbNodesFromNodes(tree->root, &nbNodes) / (float) nbNodes;
        return res;
    }
    return 0;
}

int highNodes(Node *node) {
    int highLeft = 1, hightRight = 1;
    if (node->left != NULL) {
        highLeft += highNodes(node->left);
    }
    if (node->right != NULL) {
        hightRight += highNodes(node->right);
    }
    return max(highLeft, hightRight);
}

int highTree(Tree *tree) {
    if (tree->root != NULL) {
        return highNodes(tree->root);
    }
    return 0;
}
int countNbOccurrenceInNode( Node* node, int value){
    if (node!=NULL){
        int res=node->value==value;
        res+= countNbOccurrenceInNode(node->left,value);
        res+= countNbOccurrenceInNode(node->right,value);
        return res;
    }
    return 0;
}
int countNbOccurrenceInTree( Tree* tree, int value){
    return countNbOccurrenceInNode(tree->root,value);
}

void displayNodePrefix(Node* node){
    if (node != NULL) {
        printf("%d ", node->value);
        displayNodePrefix(node->left);
        displayNodePrefix(node->right);
    }
    return;


}
void displayTreePrefix(Tree* tree){
    displayNodePrefix(tree->root);
}

void displayNodeInfix(Node* node){
    if (node != NULL) {
        displayNodeInfix(node->left);
        printf("%d ", node->value);
        displayNodeInfix(node->right);
    }
    return;
}
void displayTreeInfix(Tree* tree){
    displayNodeInfix(tree->root);
}
void displayNodePostfix(Node* node){
    if (node != NULL) {
        displayNodePostfix(node->left);
        displayNodePostfix(node->right);
        printf("%d ", node->value);
    }
    return;
}
void displayTreePostfix(Tree* tree){
    displayNodePostfix(tree->root);
}
int BalanceNode(p_node pn){
    if (pn!=NULL){
        int heighLeft= highNodes(pn->left);
        int heighRight= highNodes(pn->right);
        int deltaHeight=heighLeft-heighRight;
        if (-1<=deltaHeight && deltaHeight<=1){
            return BalanceNode(pn->left)&& BalanceNode(pn->right);
        }
        else{
            return 0;
        }
    }
    return 1;
}
int BalanceTree(Tree* tree){
    if (tree!=NULL){
        return BalanceNode(tree->root);
    }
    return 1;
}