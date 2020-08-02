//
// Created by Cindy Lieu on 1/1/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "relationship.h"
#include "tree.h"

tree *getRoot(tree *node) {
    tree *root = node;

    while (root->parent != NULL) {
        root = root->parent;
    }

    return root;
}

int getBranch(tree *root, tree *node) {
    tree *n = node;
    int branch = -1;

    while (n != root) {
        n = n->parent;
        branch++;
    }

    return branch;
}

tree *setSameBranch(tree *tree1, tree *tree2) {

    int branch1 = getBranch(getRoot(tree1), tree1);
    int branch2 = getBranch(getRoot(tree2), tree2);
    int count = 0;

    if (branch1 > branch2) {
        while (count < (branch1 - branch2)) {
            tree1 = tree1->parent;
            count++;
        }
        return tree1;
    } else {
        while (count < (branch2 - branch1)) {
            tree2 = tree2->parent;
            count++;
        }
        return tree2;
    }

}

tree *getCommonAncestor(tree *tree1, tree *tree2) {

    int branch1 = getBranch(getRoot(tree1), tree1);
    int branch2 = getBranch(getRoot(tree2), tree2);

    if (branch1 > branch2) {
        tree1 = setSameBranch(tree1, tree2);
    } else if (branch2 > branch1){
        tree2 = setSameBranch(tree1, tree2);
    }

    while (tree1 != tree2) {
        tree1 = tree1->parent;
        tree2 = tree2->parent;
    }

    return tree1;

}

void relationship(tree *firstNode, tree *secondNode) {

    int timesRemoved, n1, n2, cousins;
    tree *commonAncestor;

    n1 = getBranch(getRoot(firstNode), firstNode);
    n2 = getBranch(getRoot(secondNode), secondNode);

    timesRemoved = abs(n1 - n2);
    commonAncestor = getCommonAncestor(firstNode, secondNode);

    if (n1 == n2) {

        cousins = getBranch(commonAncestor, firstNode);
        if (cousins == 0) {
            printf("'%s' and '%s' are siblings.", firstNode->name, secondNode->name);
        } else if (cousins == 1) {
            printf("'%s' and '%s' are 1st cousins.", firstNode->name, secondNode->name);
        } else if (cousins == 2) {
            printf("'%s' and '%s' are 2nd cousins.", firstNode->name, secondNode->name);
        } else if (cousins == 3) {
            printf("'%s' and '%s' are 3rd cousins.", firstNode->name, secondNode->name);
        } else if (cousins == 4) {
            printf("'%s' and '%s' are 4th cousins.", firstNode->name, secondNode->name);
        } else if (cousins == 5) {
            printf("'%s' and '%s' are 5th cousins.", firstNode->name, secondNode->name);
        }

    } else if (n1 > n2) {

        cousins = getBranch(commonAncestor, secondNode);
        if (cousins == -1 && timesRemoved == 1) {
            printf("'%s' and '%s' are child and parent.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 2) {
            printf("'%s' and '%s' are grand child and grand parent.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 3) {
            printf("'%s' and '%s' are great grand child and great grand parent.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 4) {
            printf("'%s' and '%s' are great great grand child and great great grand parent.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 5) {
            printf("'%s' and '%s' are great great great grand child and great great great grand parent.", firstNode->name, secondNode->name);
        }
        else if (cousins == 0 && timesRemoved == 1) {
            printf("'%s' and '%s' are niece/nephew and aunt/uncle.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 2) {
            printf("'%s' and '%s' are grand niece/nephew and grand aunt/uncle.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 3) {
            printf("'%s' and '%s' are great grand niece/nephew and great grand aunt/uncle.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 4) {
            printf("'%s' and '%s' are great great grand niece/nephew and great great grand aunt/uncle.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 5) {
            printf("'%s' and '%s' are great great great grand niece/nephew and great great great grand aunt/uncle.", firstNode->name, secondNode->name);
        }
        else if (cousins == 1 && timesRemoved == 1) {
            printf("'%s' and '%s' are 1st cousins once removed.", firstNode->name, secondNode->name);
        } else if (cousins == 1 && timesRemoved == 2) {
            printf("'%s' and '%s' are 1st cousins twice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 1 && timesRemoved == 3) {
            printf("'%s' and '%s' are 1st cousins thrice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 1 && timesRemoved == 4) {
            printf("'%s' and '%s' are 1st cousins 4 times removed.", firstNode->name, secondNode->name);
        } else if (cousins == 1 && timesRemoved == 5) {
            printf("'%s' and '%s' are 1st cousins 5 times removed.", firstNode->name, secondNode->name);
        }
        else if (cousins == 2 && timesRemoved == 1) {
            printf("'%s' and '%s' are 2nd cousins once removed.", firstNode->name, secondNode->name);
        } else if (cousins == 2 && timesRemoved == 2) {
            printf("'%s' and '%s' are 2nd cousins twice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 2 && timesRemoved == 3) {
            printf("'%s' and '%s' are 2nd cousins thrice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 2 && timesRemoved == 4) {
            printf("'%s' and '%s' are 2nd cousins 4 times removed.", firstNode->name, secondNode->name);
        } else if (cousins == 2 && timesRemoved == 5) {
            printf("'%s' and '%s' are 2nd cousins 5 times removed.", firstNode->name, secondNode->name);
        }
        else if (cousins == 3 && timesRemoved == 1) {
            printf("'%s' and '%s' are 3rd cousins once removed.", firstNode->name, secondNode->name);
        } else if (cousins == 3 && timesRemoved == 2) {
            printf("'%s' and '%s' are 3rd cousins twice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 3 && timesRemoved == 3) {
            printf("'%s' and '%s' are 3rd cousins thrice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 3 && timesRemoved == 4) {
            printf("'%s' and '%s' are 3rd cousins 4 times removed.", firstNode->name, secondNode->name);
        } else if (cousins == 3 && timesRemoved == 5) {
            printf("'%s' and '%s' are 3rd cousins 5 times removed.", firstNode->name, secondNode->name);
        }
        else if (cousins == 4 && timesRemoved == 1) {
            printf("'%s' and '%s' are 4th cousins once removed.", firstNode->name, secondNode->name);
        } else if (cousins == 4 && timesRemoved == 2) {
            printf("'%s' and '%s' are 4th cousins twice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 4 && timesRemoved == 3) {
            printf("'%s' and '%s' are 4th cousins thrice removed.", firstNode->name, secondNode->name);
        } else if (cousins == 4 && timesRemoved == 4) {
            printf("'%s' and '%s' are 4th cousins 4 times removed.", firstNode->name, secondNode->name);
        } else if (cousins == 4 && timesRemoved == 5) {
            printf("'%s' and '%s' are 4th cousins 5 times removed.", firstNode->name, secondNode->name);
        }

    } else {

        cousins = getBranch(commonAncestor, firstNode);
        if (cousins == -1 && timesRemoved == 1) {
            printf("'%s' and '%s' are parent and child.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 2) {
            printf("'%s' and '%s' are grand parent and grand child.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 3) {
            printf("'%s' and '%s' are great grand parent and great grand child.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 4) {
            printf("'%s' and '%s' are great great grand parent and great great grand child.", firstNode->name, secondNode->name);
        } else if (cousins == -1 && timesRemoved == 5) {
            printf("'%s' and '%s' are great great great grand parent and great great great grand child.", firstNode->name, secondNode->name);
        }
        else if (cousins == 0 && timesRemoved == 1) {
            printf("'%s' and '%s' are aunt/uncle and niece/nephew.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 2) {
            printf("'%s' and '%s' are grand aunt/uncle and grand niece/nephew.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 3) {
            printf("'%s' and '%s' are great grand aunt/uncle and great grand niece/nephew.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 4) {
            printf("'%s' and '%s' are great great grand aunt/uncle and great great grand niece/nephew.", firstNode->name, secondNode->name);
        } else if (cousins == 0 && timesRemoved == 5) {
            printf("'%s' and '%s' are great great great grand aunt/uncle and great great great grand niece/nephew.", firstNode->name, secondNode->name);
        }

    }

}

