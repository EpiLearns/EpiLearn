#include "fifo_lifo.h"

// Function get_tools_object

void get_tools_object()
{
    // Fifo/Lifo tools
    fifo_lifo_Window = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.tools.fifo_lifo"));

    tool_pile_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_text"));
    tool_file_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_text"));

    tool_pile_isempty_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_isempty_text"));
    tool_file_isempty_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_isempty_text"));

    tool_pile_push_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_push_entry"));
    tool_pile_push_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_pile_push_button"));
    tool_pile_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_pile_pop_button"));

    tool_file_enqueue_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_enqueue_entry"));
    tool_file_enqueue_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_file_enqueue_button"));
    tool_file_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_file_pop_button"));
}

void ui_fifo_push(GtkButton* button, gpointer user)
{
    Fifo* fifo = user;

    const gchar* number = gtk_entry_get_text(GTK_ENTRY(tool_pile_push_entry));

    fifo_push(fifo,atoi(number));

    gtk_label_set_text(GTK_LABEL(tool_pile_text),fifo_to_string(fifo));

    if (fifo_is_empty(fifo))
    {
        gtk_label_set_text(GTK_LABEL(tool_pile_isempty_text),"La pile est vide");
    }

    else
    {
        gtk_label_set_text(GTK_LABEL(tool_pile_isempty_text),"La pile n'est pas vide");
    }
    

    gtk_entry_set_text(GTK_ENTRY(tool_pile_push_entry),"");

    useless_button2 = button;
}

void ui_fifo_pop(GtkButton* button, gpointer user)
{
    Fifo* fifo = user;

    fifo_pop(fifo);
    gtk_label_set_text(GTK_LABEL(tool_pile_text),fifo_to_string(fifo));

    if (fifo_is_empty(fifo))
    {
        gtk_label_set_text(GTK_LABEL(tool_pile_isempty_text),"La pile est vide");
    }

    else
    {
        gtk_label_set_text(GTK_LABEL(tool_pile_isempty_text),"La pile n'est pas vide");
    }

    useless_button2 = button;
}

void ui_lifo_enqueue(GtkButton* button,gpointer user)
{
    Lifo* lifo = user;

    const gchar* number = gtk_entry_get_text(GTK_ENTRY(tool_file_enqueue_entry));

    lifo_enqueue(lifo,atoi(number));

    gtk_label_set_text(GTK_LABEL(tool_file_text),lifo_to_string(lifo));

    if (lifo_is_empty(lifo))
    {
        gtk_label_set_text(GTK_LABEL(tool_file_isempty_text),"La file est vide");
    }

    else
    {
        gtk_label_set_text(GTK_LABEL(tool_file_isempty_text),"La file n'est pas vide");
    }
    

    gtk_entry_set_text(GTK_ENTRY(tool_file_enqueue_entry),"");

    useless_button2 = button;
}

void ui_lifo_dequeue(GtkButton* button,gpointer user)
{
    Lifo* lifo = user;

    lifo_dequeue(lifo);
    gtk_label_set_text(GTK_LABEL(tool_file_text),lifo_to_string(lifo));

    if (lifo_is_empty(lifo))
    {
        gtk_label_set_text(GTK_LABEL(tool_file_isempty_text),"La file est vide");
    }

    else
    {
        gtk_label_set_text(GTK_LABEL(tool_file_isempty_text),"La file n'est pas vide");
    }

    useless_button2 = button;
}

void fifo_lifo_signal()
{
    Fifo* fifo = init_fifo();
    Lifo* lifo = init_lifo();

    g_signal_connect(tool_pile_push_button,"clicked",G_CALLBACK(ui_fifo_push),fifo);
    g_signal_connect(tool_pile_pop_button,"clicked",G_CALLBACK(ui_fifo_pop),fifo);

    g_signal_connect(tool_file_enqueue_button,"clicked",G_CALLBACK(ui_lifo_enqueue),lifo);
    g_signal_connect(tool_file_pop_button,"clicked",G_CALLBACK(ui_lifo_dequeue),lifo);
}

void open_fifo_lifo_fct()
{
    gtk_init(NULL, NULL);
    builder = gtk_builder_new ();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, "../res/fifo_lifo.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    get_tools_object();

    fifo_lifo_signal();

    // Connects event handlers.
    g_signal_connect(fifo_lifo_Window,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(GTK_WIDGET(fifo_lifo_Window));
    // Run the main window.
    gtk_main();

}