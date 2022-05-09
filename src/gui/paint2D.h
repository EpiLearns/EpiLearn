#ifndef PAINT2D_H
#define PAINT2D_H

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <string.h>

GtkApplication* app;
GtkBuilder* builder;
GtkWidget* Paint2DWindow;

cairo_surface_t* surface;
GtkWidget* paint_draw_area;

//GtkButton* paint_write;
//GtkButton* paint_erase;

gboolean on_draw_paint(GtkWidget* widget,cairo_t* contexte, gpointer user);
gboolean on_motion_paint(GtkWidget* widget,GdkEvent* event, gpointer user);

//void get_paint_object();
//void paint_signal();

void open_paint2D_fct(GtkApplication* app,gpointer user);

#endif