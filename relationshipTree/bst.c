//
// Created by Cindy Lieu on 1/1/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// create new bst node
bst *newBSTNode(char *name) {

    bst *node = (bst *) malloc(sizeof(bst));
    strcpy(node->name, name);
    node->left = node->right = NULL;
    node->treeNode = NULL;
    return node;

}

// insert new name
bst *insertBST(bst *node, char *name) {

    if (node == NULL) return newBSTNode(name);

    if (strcasecmp(name, node->name) < 0) {
        node->left = insertBST(node->left, name);
    } else if (strcmp(name, node->name) > 0) {
        node->right = insertBST(node->right, name);
    }

    return node;

}

// search and return bstnode
bst *search(bst *root, char *name) {

    if (root == NULL || strcasecmp(root->name, name) == 0) {
        return root;
    }

    if (strcasecmp(root->name, name) < 0) {
        return (search(root->right, name));
    }

    return (search(root->left, name));

}

void inorder(bst *root) {

    if (root != NULL) {
        inorder(root->left);
        printf("%s \n", root->name);
        inorder(root->right);
    }

}

void preorder(bst *root) {

    if (root != NULL) {
        printf("%s %6s %6s \n", root->name, root->left->name, root->right->name);
        preorder(root->left);
        preorder(root->right);
    }

}
