//
// Created by Cindy Lieu on 1/1/20.
//

#ifndef RELATIONSHIPTREE_TREE_H
#define RELATIONSHIPTREE_TREE_H

typedef struct node {

    char name[50];
    struct node *parent, *sibling, *leftChild;

} tree;

tree *newTreeNode(char *name);

void insertChild(tree *parentNode, tree *childNode);

void insertSibling(tree *leftChildNode, tree *childNode);

#endif //RELATIONSHIPTREE_TREE_H
