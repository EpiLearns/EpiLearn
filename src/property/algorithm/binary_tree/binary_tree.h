#ifndef BINARY_TREE_P_H
#define BINARY_TREE__P_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
    struct BinaryTree* left;
    struct BinaryTree* right;
    int key;

    int order;

} BinaryTree;

BinaryTree* init_binary_tree(int data);
void bt_insert_left(BinaryTree* bt,int data);
void bt_insert_right(BinaryTree* bt,int data);

void bt_free(BinaryTree* bt);

#endif