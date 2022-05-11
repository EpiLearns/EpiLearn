#ifndef PAINT2D_H
#define PAINT2D_H

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include <string.h>

GtkBuilder* builder;

cairo_surface_t* surface;

GtkWidget* Paint2DWindow;

GtkWidget* paint_draw_area;

void open_paint2D_fct();

#endif