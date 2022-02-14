#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include "gui.h"

GtkBuilder* builder;

GtkWindow* mainWindow;
GtkWindow* loginWindow;
GtkWindow* mathsWindow;
GtkWindow* algoWindow;
GtkWindow* phyWindow;
GtkWindow* elecWindow;
GtkWindow* archiWindow;
GtkWindow* profileWindow;
GtkWindow* aboutUsWindow;
GtkWindow* mcqWindow;

GtkButton* login;

GtkButton* Mathematics;
GtkButton* Algorithm;
GtkButton* Physic;
GtkButton* Electronic;
GtkButton* Computer_architecture;
GtkButton* mcq;
GtkMenuItem* aboutUs;

GtkButton* account;

GtkButton* back_profil;
GtkButton* back_maths;
GtkButton* back_algo;
GtkButton* back_ca;
GtkButton* back_elec;
GtkButton* back_phy;
GtkButton* back_mcq;

GtkButton* close_about_us;

void enter_main()
{
    gtk_widget_hide(GTK_WIDGET(loginWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void enter_profile()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(profileWindow));
}

void enter_maths()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_algo()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_phy()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(phyWindow));
}

void enter_elec()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(elecWindow));
}

void enter_archi()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_mcq()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(mcqWindow));
}

void enter_aboutUs()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(aboutUsWindow));
}


void close_profile()
{
    gtk_widget_hide(GTK_WIDGET(profileWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_maths()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_algo()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_phy()
{
    gtk_widget_hide(GTK_WIDGET(phyWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_elec()
{
    gtk_widget_hide(GTK_WIDGET(elecWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_archi()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_mcq()
{
    gtk_widget_hide(GTK_WIDGET(mcqWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_aboutUs()
{
    gtk_widget_hide(GTK_WIDGET(aboutUsWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

GtkBuilder *init_gui()
{
    // Initializes GTK.
    gtk_init(NULL, NULL);

    // Constructs a GtkBuilder instance.
    builder = gtk_builder_new ();

    GError* error = NULL;
    if (gtk_builder_add_from_file(builder, "res/EpiLearn.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return NULL;
    }
    
    // Gets the widgets.
    mainWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.main"));
    loginWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.login"));
    
    mathsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.mathematics"));
    algoWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algorithm"));
    phyWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.physic"));
    elecWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.electronic"));
    archiWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.computer_architecture"));
    profileWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.profil"));
    aboutUsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.about_us"));
    mcqWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.mcq"));

    login = GTK_BUTTON(gtk_builder_get_object(builder,"login"));
    Mathematics = GTK_BUTTON(gtk_builder_get_object(builder,"Mathematics"));
    Algorithm = GTK_BUTTON(gtk_builder_get_object(builder,"Algorithm"));
    Physic = GTK_BUTTON(gtk_builder_get_object(builder,"Physic"));
    Electronic = GTK_BUTTON(gtk_builder_get_object(builder,"Electronic"));
    Computer_architecture = GTK_BUTTON(gtk_builder_get_object(builder,"Computer architecture"));
    mcq = GTK_BUTTON(gtk_builder_get_object(builder,"mcq enter"));
    aboutUs = GTK_MENU_ITEM(gtk_builder_get_object(builder,"about us b"));

    account = GTK_BUTTON(gtk_builder_get_object(builder,"account"));

    back_profil = GTK_BUTTON(gtk_builder_get_object(builder,"Back profil"));
    back_maths = GTK_BUTTON(gtk_builder_get_object(builder,"back maths"));
    back_algo = GTK_BUTTON(gtk_builder_get_object(builder,"back algo"));
    back_ca = GTK_BUTTON(gtk_builder_get_object(builder,"back ca"));
    back_elec = GTK_BUTTON(gtk_builder_get_object(builder,"back elec"));
    back_phy = GTK_BUTTON(gtk_builder_get_object(builder,"back phy"));
    back_mcq = GTK_BUTTON(gtk_builder_get_object(builder,"quit mcq"));

    close_about_us = GTK_BUTTON(gtk_builder_get_object(builder,"close about us"));

    // Connects event handlers.
    g_signal_connect(mainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show(GTK_WIDGET(loginWindow));

    g_signal_connect(login,"clicked",G_CALLBACK(enter_main),NULL);
    g_signal_connect(Mathematics,"clicked",G_CALLBACK(enter_maths),NULL);
    g_signal_connect(Algorithm,"clicked",G_CALLBACK(enter_algo),NULL);
    g_signal_connect(Physic,"clicked",G_CALLBACK(enter_phy),NULL);
    g_signal_connect(Electronic,"clicked",G_CALLBACK(enter_elec),NULL);
    g_signal_connect(Computer_architecture,"clicked",G_CALLBACK(enter_archi),NULL);
    g_signal_connect(mcq,"clicked",G_CALLBACK(enter_mcq),NULL);
    g_signal_connect(account,"clicked",G_CALLBACK(enter_profile),NULL);
    g_signal_connect(aboutUs,"activate",G_CALLBACK(enter_aboutUs),NULL);

    g_signal_connect(back_maths,"clicked",G_CALLBACK(close_maths),NULL);
    g_signal_connect(back_algo,"clicked",G_CALLBACK(close_algo),NULL);
    g_signal_connect(back_phy,"clicked",G_CALLBACK(close_phy),NULL);
    g_signal_connect(back_elec,"clicked",G_CALLBACK(close_elec),NULL);
    g_signal_connect(back_ca,"clicked",G_CALLBACK(close_archi),NULL);
    g_signal_connect(back_mcq,"clicked",G_CALLBACK(close_mcq),NULL);
    g_signal_connect(back_profil,"clicked",G_CALLBACK(close_profile),NULL);
    g_signal_connect(close_about_us,"clicked",G_CALLBACK(close_aboutUs),NULL);

    // Run the main window.
    gtk_main();
    
    return builder;
}
