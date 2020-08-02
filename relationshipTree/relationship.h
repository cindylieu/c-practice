//
// Created by Cindy Lieu on 1/1/20.
//

#ifndef RELATIONSHIPTREE_RELATIONSHIP_H
#define RELATIONSHIPTREE_RELATIONSHIP_H


#include "tree.h"

tree *getRoot(tree *node);

int getBranch(tree *root, tree *node);

tree *setSameBranch(tree *tree1, tree *tree2);

tree *getCommonAncestor(tree *tree1, tree *tree2);

void relationship(tree *firstNode, tree *secondNode);

#endif //RELATIONSHIPTREE_RELATIONSHIP_H
