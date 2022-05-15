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

void bt_insert_left(BinaryTree* bt,int data)
{
    bt->left = init_binary_tree(data);
    bt->left->order = bt->order * 2;
}

void bt_insert_right(BinaryTree* bt,int data)
{
    bt->right = init_binary_tree(data);
    bt->right->order = bt->order * 2 + 1;
}

void bt_free(BinaryTree* bt)
{
    if (bt)
    {   
        if(bt->left)
        {
            bt_free(bt->left);
        }

        if (bt->right)
        {
            bt_free(bt->right);
        }

        free((bt));
    }
}
