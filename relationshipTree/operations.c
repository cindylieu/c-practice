//
// Created by Cindy Lieu on 1/1/20.
//

#include <stdio.h>
#include "operations.h"
#include "bst.h"
#include "tree.h"
#include "relationship.h"

void printOptions() {
    printf("Perform an operation on the orchard.\n\n");
    printf("\t(r)ead list of names \n\n"
           "\t(i)nsert nodes into a tree \n\n"
           "\t(l)ookup relationship of two names\n\n"
           "\t(p)reorder output of binary tree.\n\n"
           "\t(q)uit)\n\n");
    printf("> ");
}

void operationI(bst *root, char *parentName, char *childName) {

    // if parent does not exist
    if (search(root, parentName) == NULL) {

        insertBST(root, parentName);
        bst *parentBSTNode = search(root, parentName);
        tree *parentTreeNode = newTreeNode(parentName);
        parentBSTNode->treeNode = parentTreeNode;

    }

    // get parentBSTNode & parentTreeNode
    bst *parentBSTNode = search(root, parentName);
    tree *parentTreeNode = parentBSTNode->treeNode;

    // create child, insert to tree, insert to bst
    tree *childTreeNode = newTreeNode((childName));
    insertChild(parentTreeNode, childTreeNode);
    insertBST(root, childName);
    bst *childBSTNode = search(root, childName);
    childBSTNode->treeNode = childTreeNode;

    // set child's parent
    childTreeNode->parent = parentTreeNode;

}

void operationL(bst *root, char *firstPerson, char *secondPerson){

    tree *firstNode = search(root, firstPerson)->treeNode;
    tree *secondNode = search(root, secondPerson)->treeNode;

    if (getRoot(firstNode) != getRoot(secondNode)) {
        printf("'%s' and '%s' are not in the same family.\n", firstPerson, secondPerson);
    } else {
        relationship(firstNode, secondNode);
    }

}

void operationR(){

}