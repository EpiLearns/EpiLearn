#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

#include "../property/algorithm/binary_tree/binary_tree.h"

typedef struct Nodes
{
    GtkWidget* bt;
    struct Nodes* next;
} Nodes;

BinaryTree* currentTree;
BinaryTree* rootTree;

Nodes* bt_nodes;

GtkBuilder* builder;
GtkWindow* binary_treeWindow;

GtkWidget* tool_b_insert_entry;
GtkButton* tool_b_insert_left_button;
GtkButton* tool_b_insert_right_button;

GtkButton* tool_b_left_del_button;
GtkButton* tool_b_right_del_button;

GtkButton* tool_b_clear_button;

GtkButton* tool_b_left_button;
GtkButton* tool_b_right_button;

GtkButton* tool_b_root_button;

GtkWidget* tool_b_key_text;

GtkWidget* bt1;
GtkWidget* bt2;
GtkWidget* bt3;
GtkWidget* bt4;
GtkWidget* bt5;
GtkWidget* bt6;
GtkWidget* bt7;
GtkWidget* bt8;
GtkWidget* bt9;
GtkWidget* bt10;
GtkWidget* bt11;
GtkWidget* bt12;
GtkWidget* bt13;
GtkWidget* bt14;
GtkWidget* bt15;
GtkWidget* bt16;
GtkWidget* bt17;
GtkWidget* bt18;
GtkWidget* bt19;
GtkWidget* bt20;
GtkWidget* bt21;
GtkWidget* bt22;
GtkWidget* bt23;
GtkWidget* bt24;
GtkWidget* bt25;
GtkWidget* bt26;
GtkWidget* bt27;
GtkWidget* bt28;
GtkWidget* bt29;
GtkWidget* bt30;
GtkWidget* bt31;

void open_binary_tree_fct();

#endif