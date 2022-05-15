#ifndef NUMBER_H
#define NUMBER_H

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
GtkWidget	*response_confirm;

//windows end
GtkWidget	*end;
GtkWidget	*end_fixed;
GtkWidget	*end_print;
GtkWidget	*restart;

// game
GtkWidget	*background;
GtkWidget	*level_print;

int n;
char str[128];
char l_string[128];
char n_string[128];
guint event;

//fonctions 

gboolean on_number();
void	on_start_button_clicked ();
void	on_response_confirm_clicked ();
void on_response_entry_changed (GtkEntry *e);
void on_restart_clicked ();

#endif
