#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "tree.h"
#include "operations.h"
#include "relationship.h"


int main() {

    bst *root = NULL;

    int run = 1, rootSet = 1;
    FILE *filePtr;
    char operation;
    char parent[50];
    char child[50];

    do {

        printOptions();
        scanf(" %c", &operation);

        if (operation == 'r') {

            if ((filePtr = fopen("/Users/cindylieu/develop/RelationshipTree/FamilyTrees_Homework2.txt", "r")) == NULL) {
                printf("File could not be opened\n");
            } else {
                while (!feof(filePtr)) {

                    fscanf(filePtr, "%s%s", child, parent);

                    if (rootSet == 1) {

                        root = insertBST(root, parent);
                        root->treeNode = newTreeNode(parent);
                        rootSet = 0;
                        operationI(root, parent, child);

                    } else {

                        operationI(root, parent, child);

                    }

                }
                fclose(filePtr);
            }
        } else if (operation == 'i') {

            printf("(i)nsert nodes into a tree \n\n");

            if (rootSet == 1) {

                printf("Enter child: ");
                scanf(" %s", child);
                printf("\n");
                printf("\tis the child of\n\n");
                printf("Enter parent: ");
                scanf(" %s", parent);

                root = insertBST(root, parent);
                root->treeNode = newTreeNode(parent);
                rootSet = 0;

                operationI(root, parent, child);

            } else {
                printf("Enter child: \n\n");
                scanf(" %s", child);

                if (search(root, child) != NULL) {
                    printf("Child '%s' already has a parent. Cannot add.\n", child);
                } else {

                    printf("\tis the child of\n\n");
                    printf("Enter parent: \n\n");
                    scanf(" %s", parent);

                    operationI(root, parent, child);

                }
            }

        } else if (operation == 'l') {

            char firstPerson[15];
            char secondPerson[15];

            printf("Enter the first person: \n");
            scanf(" %s", firstPerson);

            if (search(root, firstPerson) == NULL) {
                printf("First person '%s' does not exist.\n", firstPerson);

            } else {
                printf("Enter the second person: \n");
                scanf(" %s", secondPerson);

                if (search(root, secondPerson) == NULL) {
                    printf("Second person '%s' does not exist.\n", secondPerson);
                } else {

                    operationL(root, firstPerson, secondPerson);
                    printf("\n");

                }

            }


        } else if (operation == 'p') {

            printf("(p)reorder output of binary tree.\n");
            printf("Name  Left   Right\n");
            preorder(root);

        } else if (operation == 'q') {

            run = 0;
        }

    } while (run == 1);

    return 0;
}