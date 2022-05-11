#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BinaryTree
{
    struct BinaryTree *left,*right;
    int key;

} BinaryTree;

BinaryTree* init_binary_tree(int data);

void search_key(BinaryTree* binaryTree, int data, BinaryTree* res);

#endif