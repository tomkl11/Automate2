#include <stdio.h>
#include "arbre_binair.h"
int main() {
    Node* node1,*node2,*node3;
    node1= createNode(1);
    node2= createNode(2);
    node3= createNode(3);
    Tree *myTree= createTreeFromNode(node1);
    node1->left=node2;
    node1->right=node3;
    node2->left= createNode(4);
    node2->right= createNode(5);
    node3->left= createNode(6);
    node3->right= createNode(7);
    displayTreeInfix(myTree);
    rotateLeft(myTree,5);
    return 0;
}
