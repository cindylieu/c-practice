//
// Created by Cindy Lieu on 1/1/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// create new tree node
tree *newTreeNode(char *name) {

    tree *node = (tree *) malloc(sizeof(tree));
    strcpy(node->name, name);
    node->parent = NULL;
    node->sibling = NULL;
    node->leftChild = NULL;
    return node;

}

void insertChild(tree *parentNode, tree*childNode) {

    if (parentNode->leftChild == NULL) {
        parentNode->leftChild = childNode;
    } else {
        insertSibling(parentNode->leftChild, childNode);
    }

}

void insertSibling(tree *leftChildNode, tree *childNode) {

    while (leftChildNode->sibling != NULL) {
        leftChildNode = leftChildNode->sibling;
    }
    leftChildNode->sibling = childNode;

}

