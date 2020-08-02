//
// Created by Cindy Lieu on 1/1/20.
//

#ifndef RELATIONSHIPTREE_BST_H
#define RELATIONSHIPTREE_BST_H

#include "tree.h"

typedef struct bstNode {

    char name[50];
    struct bstNode *left, *right;
    tree *treeNode;

} bst;

bst *newBSTNode(char *name);

bst *insertBST(bst *node, char *name);

bst *search(bst *root, char *name);

void inorder(bst *root);

void preorder(bst *root);

#endif //RELATIONSHIPTREE_BST_H
