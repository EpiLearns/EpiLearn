#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <string.h>

#include "../property/algorithm/list/list.h"

// Tools List Object

GtkBuilder* builder;

GtkWindow* listWindow;

GtkWidget* tool_list_list_text;
GtkWidget* tool_list_len_text;

GtkWidget* tool_list_append_entry;
GtkButton* tool_list_append_button;

GtkButton* tool_list_pop_button;

GtkWidget* tool_list_insert_entry1;
GtkWidget* tool_list_insert_entry2;

GtkButton* tool_list_insert_button;

void get_list_object();

void ui_list_append(GtkButton* button, gpointer user);

void ui_list_pop(GtkButton* button, gpointer user);

void ui_list_insert(GtkButton* button, gpointer user);

void list_signal();

void open_list_fct();

#endif