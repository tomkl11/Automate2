//
// Created by tmKla on 14/10/2022.
//

#include "bst.h"
void insertNodeInNode(Node *node, Node *nodeToInsert) {
    if (node->value == nodeToInsert->value) {
        return;
    }
    if (node->value < nodeToInsert->value) {
        if (node->right == NULL) {
            node->right = nodeToInsert;
        } else {
            insertNodeInNode(node->right, nodeToInsert);
        }
    } else {
        if (node->left == NULL) {
            node->left = nodeToInsert;
        } else {
            insertNodeInNode(node->left, nodeToInsert);
        }
    }
}


void insertValueInBST(BST *bst, int value) {
    Node *node = createNode(value);
    if (bst != NULL) {
        if (bst->root == NULL) {
            bst->root = node;
        } else {
            insertNodeInNode(bst->root, node);
        }
    }
}

Node *findParentByValue(Node *node, int value) {
    if (node->value > value) {
        if (node->left != NULL) {
            if (node->left->value == value) {
                return node;
            } else {
                return findParentByValue(node->left, value);
            }
        }
    } else {
        if (node->right != NULL) {
            if (node->right->value == value) {
                return node;
            } else {
                return findParentByValue(node->right, value);
            }
        }
    }
    return NULL;
}

void rotateLeft(BST *bst, int valueToRotate) {
    if (bst->root == NULL) {
        return;
    } else {
        Node *parent;
        Node *nodeToRotate;
        if (bst->root->value == valueToRotate) {
            parent = NULL;
            nodeToRotate = bst->root;
        } else {
            parent = findParentByValue(bst->root, valueToRotate);
            if (parent->value > valueToRotate) {
                nodeToRotate = parent->left;
            } else {
                nodeToRotate = parent->right;
            }
        }

        if (nodeToRotate->right != NULL) {
            if (parent == NULL) {
                bst->root = nodeToRotate->right;
            } else {
                if (parent->value > valueToRotate) {
                    parent->left = nodeToRotate->right;
                } else {
                    parent->right = nodeToRotate->right;
                }
            }
            Node *temp = nodeToRotate->right;
            nodeToRotate->right = temp->left;
            temp->left = nodeToRotate;
        }
    }
}
void rotateRight(BST *bst, int valueToRotate) {
    if (bst->root == NULL) {
        return;
    } else {
        Node *parent;
        Node *nodeToRotate;
        if (bst->root->value == valueToRotate) {
            parent = NULL;
            nodeToRotate = bst->root;
        } else {
            parent = findParentByValue(bst->root, valueToRotate);
            if (parent->value > valueToRotate) {
                nodeToRotate = parent->left;
            } else {
                nodeToRotate = parent->right;
            }
        }

        if (nodeToRotate->left != NULL) {
            if (parent == NULL) {
                bst->root = nodeToRotate->left;
            } else {
                if (parent->value > valueToRotate) {
                    parent->left = nodeToRotate->left;
                } else {
                    parent->right = nodeToRotate->left;
                }
            }
            Node *temp = nodeToRotate->right;
            nodeToRotate->right = temp->left;
            temp->left = nodeToRotate;
        }
    }
}
