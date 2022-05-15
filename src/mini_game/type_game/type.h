#ifndef TYPE_H
#define TYPE_H

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
//  #include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

GtkBuilder	*builder; 

//window
GtkWidget	*window;

// window start
GtkWidget	*start;
GtkWidget	*start_fixed;
GtkWidget	*start_button;

//window number
GtkWidget	*number;
GtkWidget	*number_fixed;
GtkWidget	*number_print;

//window response
GtkWidget	*response;
GtkWidget	*response_fixed;
GtkWidget	*response_entry;

//windows end
GtkWidget	*end;
GtkWidget	*end_fixed;
GtkWidget	*end_print;
GtkWidget	*restart;
GtkWidget   *type_game_title;

// game
GtkWidget	*background;
GtkWidget	*level_print;

GtkWidget	*X1;
GtkWidget	*X2;
GtkWidget	*X3;

GtkWidget	*response_print;

char l_string[128];
char entry_string[128];

int choose_number();
void	on_start_button_clicked_type ();
void on_response_entry_changed_type (GtkEntry *e);
void on_restart_clicked_type ();
void open_type_game_fct();
#endif