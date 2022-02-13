#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include "gui.h"

void open_page(GtkBuilder* builder, char *name)
{
    GtkWidget* page = GTK_WIDGET(gtk_builder_get_object(builder,name));
    gtk_widget_show(page);
}

void close_page(GtkBuilder* builder, char *name)
{
    GtkWidget* page = GTK_WIDGET(gtk_builder_get_object(builder,name));
    gtk_widget_hide(page);
}

void menu_signals(GtkBuilder* builder)
{
    
}

void update_page(GtkBuilder* builder, char* previous_page, char* new_page)
{
    close_page(builder,previous_page);
    open_page(builder,new_page);
}

GtkBuilder *init_gui()
{
    // Initializes GTK.
    gtk_init(NULL, NULL);

    // Constructs a GtkBuilder instance.
    GtkBuilder* builder = gtk_builder_new ();

    GError* error = NULL;
    if (gtk_builder_add_from_file(builder, "res/EpiLearn.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return NULL;
    }
    
    // Gets the widgets.
    GtkWindow* mainWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.main"));

    // Connects event handlers.
    g_signal_connect(mainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Buttons event handlers.
    menu_signals(builder);

    gtk_widget_show(GTK_WIDGET(mainWindow));

    // Run the main window.
    gtk_main();
    
    return builder;
}
