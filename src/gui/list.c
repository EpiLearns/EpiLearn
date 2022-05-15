#include "list.h"

void get_list_object()
{
    //List tools
    listWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.tools.list"));

    tool_list_list_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_list_text"));
    tool_list_len_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_len_text"));

    tool_list_append_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_append_entry"));
    tool_list_append_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_append_button"));

    tool_list_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_pop_button"));

    tool_list_insert_entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_insert_entry1"));
    tool_list_insert_entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_insert_entry2"));

    tool_list_insert_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_insert_button"));
}

void ui_list_append(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    const gchar* number = gtk_entry_get_text(GTK_ENTRY(tool_list_append_entry));

    list_append(list,atoi(number));

    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);

    gtk_entry_set_text(GTK_ENTRY(tool_list_append_entry),"");

    useless_button = button;
}

void ui_list_pop(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    list_pop(list);
    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);

    useless_button = button;
}

void ui_list_insert(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    const gchar* number1 = gtk_entry_get_text(GTK_ENTRY(tool_list_insert_entry1));
    const gchar* number2 = gtk_entry_get_text(GTK_ENTRY(tool_list_insert_entry2));

    list_insert(list,atoi(number1),atoi(number2));

    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);

    gtk_entry_set_text(GTK_ENTRY(tool_list_insert_entry1),"");
    gtk_entry_set_text(GTK_ENTRY(tool_list_insert_entry2),"");

    useless_button = button;
}

void list_signal()
{
    List* list = init_list();

    g_signal_connect(tool_list_append_button,"clicked",G_CALLBACK(ui_list_append),list);
    g_signal_connect(tool_list_pop_button,"clicked",G_CALLBACK(ui_list_pop),list);
    g_signal_connect(tool_list_insert_button,"clicked",G_CALLBACK(ui_list_insert),list);
}

void open_list_fct()
{
    gtk_init(NULL, NULL);
    builder = gtk_builder_new ();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, "../res/List.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    get_list_object();

    list_signal();

    // Connects event handlers.
    g_signal_connect(listWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(GTK_WIDGET(listWindow));
    // Run the main window.
    gtk_main();

}