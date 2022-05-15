#include "number.h"

// gcc -Wno-format -o window window.c -Wno-deprecated-declarations -rdynamic -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0`
// export DISPLAY=0:0 

 
int level_number = 1;
int lives_number = 3;

int generate_number(int level)
{
    srand(time(NULL));
    int number = 0;
    int random = 0;
    if (level != 1)
    {
        random = rand() % 9 + 1;
        number = number*10 + random;
        level = level - 1;
    }
    while (level > 0)
    {
        random = rand() % 10;
        number = number*10 + random;
        level = level - 1;
    }
    return number;
}



void open_number_game_fct() {

	gtk_init(NULL,NULL); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("../src/mini_game/number_game/window.glade");
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	start = GTK_WIDGET(gtk_builder_get_object(builder, "start"));
    number = GTK_WIDGET(gtk_builder_get_object(builder, "number"));
    response = GTK_WIDGET(gtk_builder_get_object(builder, "response"));
    number_game_label = GTK_WIDGET(gtk_builder_get_object(builder, "number_game_label"));

	//g_signal_connect(start, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(number, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //g_signal_connect(response, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    g_signal_connect(GTK_WINDOW(window),"destroy", G_CALLBACK(gtk_main_quit), NULL);

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

    background = GTK_WIDGET(gtk_builder_get_object(builder, "background"));
    level_print = GTK_WIDGET(gtk_builder_get_object(builder, "level_print"));


	gtk_widget_show(window);
    gtk_widget_show(background);
    gtk_widget_hide(level_print);
    gtk_widget_hide(response_entry);
    gtk_widget_hide(response_confirm);
    gtk_widget_hide(restart);

	gtk_main();

	}

// signal funtion

gboolean on_number()
{
    gtk_widget_hide(number_print);
    gtk_widget_show(response_entry);
    gtk_widget_show(response_confirm);
    return FALSE;
}

void	on_start_button_clicked_number () {
    gtk_widget_show(level_print);
    sprintf(l_string,"CURRENT LEVEL : %d",level_number);
    gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) l_string);
    lives_number = 3;
	gtk_widget_hide(start_button);
    n = generate_number(level_number);
    sprintf(str,"%d",n);
    gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) str);
    gtk_widget_show(number_print);
    event = g_timeout_add(3000, on_number, number_print);

    gtk_widget_hide(number_game_label);
	}

void	on_response_confirm_clicked () {
    if (strcmp(str,n_string) == 0)
    {
        level_number = level_number + 1;
    }
    else
    {
        lives_number = lives_number - 1;   
    }

    if (lives_number < 0)
    {
        gtk_widget_hide(response_confirm);
        gtk_widget_hide(response_entry);
        gtk_widget_hide(level_print);
        char end_level[128];
        sprintf(end_level,"YOU REACHED LEVEL : %d",level_number);
        gtk_label_set_text (GTK_LABEL(end_print), (const gchar*) end_level);
        gtk_widget_show(end_print);
        gtk_widget_show(restart);
    }
    else
    {
        gtk_widget_hide(response_confirm);
        gtk_widget_hide(response_entry);
        sprintf(l_string,"CURRENT LEVEL : %d",level_number);
        gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) l_string);
        n = generate_number(level_number);
        sprintf(str,"%d",n);
        gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) str);
        gtk_widget_show(number_print);
        event = g_timeout_add(3000, on_number, number_print); // 8 sec !!
    }
    gtk_editable_delete_text(GTK_EDITABLE(response_entry),0,-1);
}

void on_response_entry_changed (GtkEntry *e)
{
    sprintf(n_string,"%s", gtk_entry_get_text(e));
}

void on_restart_clicked_number ()
{
    gtk_widget_hide(end_print);
    gtk_widget_hide(restart);
    gtk_widget_show(start_button);
    level_number = 0;
}