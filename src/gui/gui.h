#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

void open_page(GtkBuilder* builder, char *name);
void close_page(GtkBuilder* builder, char *name);
void update_page(GtkBuilder* builder, char* previous_page, char* new_page);
void menu_signals(GtkBuilder* builder);

GtkBuilder *init_gui();

#endif
