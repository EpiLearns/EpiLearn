#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

BinaryTree* init_binary_tree(int data)
{
    BinaryTree* res = calloc(1,sizeof(BinaryTree));

    if (!res)
    {
        return NULL;
    }

    res->key = data;

    return res;
}

void search_key(BinaryTree* binaryTree, int data, BinaryTree* res)
{
    if (binaryTree->key == data)
    {
        res = binaryTree;
    }

    if (binaryTree->left)
    {
        search_key(binaryTree->left,data,res);
    }

    if (binaryTree->right)
    {
        search_key(binaryTree->right,data,res);
    }
}