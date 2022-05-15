#ifndef GRAPH_H
#define GRAPH_H

#include <string.h>
#include "node.h"
#include "parser.h"

double graph_f (double x);

gboolean on_draw (GtkWidget *widget, cairo_t *cr);

void on_button2_clicked();

void on_button1_clicked();

void on_plusbutton_clicked();

void on_minusbutton_clicked();

void on_quitbutton_clicked(gpointer user_data);

void open_graph_fct();
#endif