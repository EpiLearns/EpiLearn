#ifndef FIFO_LIFO_H
#define FIFO_LIFO_H

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <string.h>

#include "../property/algorithm/fifo/fifo.h"
#include "../property/algorithm/lifo/lifo.h"

// Tools FIFO/LIFO Object

GtkBuilder* builder;

GtkWindow* fifo_lifo_Window;

GtkWidget* tool_pile_text;
GtkWidget* tool_file_text;

GtkWidget* tool_pile_isempty_text;
GtkWidget* tool_file_isempty_text;

GtkWidget* tool_pile_push_entry;
GtkButton* tool_pile_push_button;
GtkButton* tool_pile_pop_button;

GtkWidget* tool_file_enqueue_entry;
GtkButton* tool_file_enqueue_button;
GtkButton* tool_file_pop_button;

GtkButton* useless_button2;

void get_tools_object();

void ui_fifo_push(GtkButton* button, gpointer user);

void ui_fifo_pop(GtkButton* button, gpointer user);

void ui_lifo_enqueue(GtkButton* button,gpointer user);

void ui_lifo_dequeue(GtkButton* button,gpointer user);

void open_fifo_lifo_fct();

#endif