#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
//  #include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include "script.h"

// gcc -Wno-format -o window window.c script.c -Wno-deprecated-declarations -rdynamic -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0`
// export DISPLAY=0:0 

// Make them global
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
 
int level = 1;
int n;
char str[128];
char n_string[128];
guint event;
int lives = 3;



// signal

G_MODULE_EXPORT void	on_start_button_clicked (GtkButton *b);


int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("window.glade");
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	start = GTK_WIDGET(gtk_builder_get_object(builder, "start"));
    number = GTK_WIDGET(gtk_builder_get_object(builder, "number"));
    response = GTK_WIDGET(gtk_builder_get_object(builder, "response"));

	g_signal_connect(start, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(number, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(response, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_builder_connect_signals(builder, NULL);

	start_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "start_fixed"));
	start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));

    number_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "number_fixed"));
	number_print = GTK_WIDGET(gtk_builder_get_object(builder, "number_print"));

    response_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "response_fixed"));
	response_entry = GTK_WIDGET(gtk_builder_get_object(builder, "response_entry"));
    response_confirm = GTK_WIDGET(gtk_builder_get_object(builder, "response_confirm"));

    end = GTK_WIDGET(gtk_builder_get_object(builder, "end"));
    end_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "end_fixed"));
    end_print = GTK_WIDGET(gtk_builder_get_object(builder, "end_print"));

    restart = GTK_WIDGET(gtk_builder_get_object(builder, "restart"));


	gtk_widget_show(window);
    gtk_widget_hide(response_entry);
    gtk_widget_hide(response_confirm);
    gtk_widget_hide(restart);

	gtk_main();

	return EXIT_SUCCESS;
	}

// signal funtion

gboolean on_number(gpointer user_data)
{
    gtk_widget_hide(number_print);
    gtk_widget_show(response_entry);
    gtk_widget_show(response_confirm);
    return FALSE;
}

void	on_start_button_clicked (GtkButton *b) {
    lives = 3;
	gtk_widget_hide(start_button);
    n = generate_number(level);
    sprintf(str,"%d",n);
    gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) str);
    gtk_widget_show(number_print);
    event = g_timeout_add(5000, on_number, number_print);
	}

void	on_response_confirm_clicked (GtkButton *b) {
    if (strcmp(str,n_string) == 0)
    {
        level = level + 1;
    }
    else
    {
        lives = lives - 1;   
    }

    if (lives < 0)
    {
        gtk_widget_hide(response_confirm);
        gtk_widget_hide(response_entry);
        char end_level[128];
        sprintf(end_level,"YOU REACHED LEVEL : %d",level);
        gtk_label_set_text (GTK_LABEL(end_print), (const gchar*) end_level);
        gtk_widget_show(end_print);
        gtk_widget_show(restart);
    }
    else
    {
        gtk_widget_hide(response_confirm);
        gtk_widget_hide(response_entry);
        n = generate_number(level);
        sprintf(str,"%d",n);
        gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) str);
        gtk_widget_show(number_print);
        event = g_timeout_add(8000, on_number, number_print);
    }
    gtk_editable_delete_text(GTK_EDITABLE(response_entry),0,-1);
}

void on_response_entry_changed (GtkEntry *e)
{
    sprintf(n_string,"%s", gtk_entry_get_text(e));
}

void on_restart_clicked (GtkButton *b)
{
    gtk_widget_hide(end_print);
    gtk_widget_hide(restart);
    gtk_widget_show(start_button);
    level = 0;
}