#ifndef GRID_H
#define GRID_H

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
//  #include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <glib/gprintf.h>

GtkBuilder	*builder; 

//window
GtkWidget	*window;

// window start
GtkWidget	*start_fixed;
GtkWidget	*start_button;

//windows end
GtkWidget	*end_print;
GtkWidget	*restart;

// buttons
GtkWidget	*button1;
GtkWidget	*button2;
GtkWidget	*button3;
GtkWidget	*button4;
GtkWidget	*button5;
GtkWidget	*button6;
GtkWidget	*button7;
GtkWidget	*button8;
GtkWidget	*button9;
GtkWidget	*button10;
GtkWidget	*button11;
GtkWidget	*button12;
GtkWidget	*button13;
GtkWidget	*button14;
GtkWidget	*button15;
GtkWidget	*button16;
GtkWidget	*button17;
GtkWidget	*button18;
GtkWidget	*button19;
GtkWidget	*button20;
GtkWidget	*button21;
GtkWidget	*button22;
GtkWidget	*button23;
GtkWidget	*button24;
GtkWidget	*button25;

GtkWidget	*green1;
GtkWidget	*green2;
GtkWidget	*green3;
GtkWidget	*green4;
GtkWidget	*green5;
GtkWidget	*green6;
GtkWidget	*green7;
GtkWidget	*green8;
GtkWidget	*green9;
GtkWidget	*green10;
GtkWidget	*green11;
GtkWidget	*green12;
GtkWidget	*green13;
GtkWidget	*green14;
GtkWidget	*green15;
GtkWidget	*green16;
GtkWidget	*green17;
GtkWidget	*green18;
GtkWidget	*green19;
GtkWidget	*green20;
GtkWidget	*green21;
GtkWidget	*green22;
GtkWidget	*green23;
GtkWidget	*green24;
GtkWidget	*green25;

GtkWidget	*red1;
GtkWidget	*red2;
GtkWidget	*red3;
GtkWidget	*red4;
GtkWidget	*red5;
GtkWidget	*red6;
GtkWidget	*red7;
GtkWidget	*red8;
GtkWidget	*red9;
GtkWidget	*red10;
GtkWidget	*red11;
GtkWidget	*red12;
GtkWidget	*red13;
GtkWidget	*red14;
GtkWidget	*red15;
GtkWidget	*red16;
GtkWidget	*red17;
GtkWidget	*red18;
GtkWidget	*red19;
GtkWidget	*red20;
GtkWidget	*red21;
GtkWidget	*red22;
GtkWidget	*red23;
GtkWidget	*red24;
GtkWidget	*red25;

GtkWidget	*level_print;

int nb;
int l[26];
guint event;

//fonction 

void create_grid2(int level,  int l[]);
void hide_all();
gboolean back_normal();
void change_color(int level);
void change_level();
void	on_start_button_clicked_grid ();
void on_restart_clicked_grid ();
void end_window();
void	on_button_clicked (GtkButton *b);
void open_grid_game_fct();

#endif