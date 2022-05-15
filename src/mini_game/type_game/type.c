#include "type.h"

// gcc -Wno-format -o window window.c -Wno-deprecated-declarations -rdynamic -Wno-format-security -lm `pkg-config --cflags --libs gtk+-3.0`
// export DISPLAY=0:0 

// Make them global
 
int level_type = 1;
char s[14] = "test test test";
int position = 0;
int lives_type = 4;
int z  = 0;

char *strs[10] = {"hypocycloidaux ", "tachyphylaxies", "psychophysique","schizothymique","zygophyllacees",
                    "cyclothymiques","deshypothequez","hydroperoxydes","hypoglycemique","knickerbockers"};

int M[10] = {0,0,0,0,0,0,0,0,0,0};
int r = 0;
// signal

//G_MODULE_EXPORT void	on_start_button_clicked (GtkButton *b);
int choose_number()
{
    int random = -1;
    while (random == -1)
    {
        random = rand() % 10;
        if (M[random] == 0)
        {
            M[random] = 1;
        }
    }
    return random;
    
}

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("../src/mini_game/type_game/window.glade");
 
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

    end = GTK_WIDGET(gtk_builder_get_object(builder, "end"));
    end_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "end_fixed"));
    end_print = GTK_WIDGET(gtk_builder_get_object(builder, "end_print"));

    restart = GTK_WIDGET(gtk_builder_get_object(builder, "restart"));

    background = GTK_WIDGET(gtk_builder_get_object(builder, "background"));
    level_print = GTK_WIDGET(gtk_builder_get_object(builder, "level_print"));

    X1 = GTK_WIDGET(gtk_builder_get_object(builder, "X1"));
    X2 = GTK_WIDGET(gtk_builder_get_object(builder, "X2"));
    X3 = GTK_WIDGET(gtk_builder_get_object(builder, "X3"));

    response_print = GTK_WIDGET(gtk_builder_get_object(builder, "response_print"));


	gtk_widget_show(window);
    gtk_widget_show(background);
    gtk_widget_hide(level_print);
    gtk_widget_hide(response_entry);
    gtk_widget_hide(restart);
    gtk_widget_hide(X1);
    gtk_widget_hide(X2);
    gtk_widget_hide(X3);
    gtk_widget_hide(response_print);

	gtk_main();

	return EXIT_SUCCESS;
	}

// signal funtion


void	on_start_button_clicked_type () {
    const char *suppresion = "";
    gtk_entry_set_text(GTK_ENTRY(response_entry), suppresion);
    gtk_widget_show(level_print);
    gtk_widget_show(response_entry);
    sprintf(l_string,"CURRENT level : %d",level_type);
    gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) l_string);
    lives_type = 4;
    z= 0 ;
	gtk_widget_hide(start_button);
    r = choose_number();
    sprintf(s,strs[r]);
    gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) s);
    gtk_widget_show(number_print);
    gtk_label_set_text(GTK_LABEL(response_print), suppresion);
    gtk_widget_show(response_print);
	}


void on_response_entry_changed_type (GtkEntry *e)
{
    sprintf(entry_string,"%s", gtk_entry_get_text(e));
    if (entry_string[position] == s[position])
    {
        if (position == 13)
        {
            r = choose_number();
            sprintf(s,strs[r]);
            gtk_label_set_text (GTK_LABEL(number_print), (const gchar*) s);
            const char *suppresion = "";
            gtk_entry_set_text(GTK_ENTRY(response_entry), suppresion);
            position = 0;

            level_type = level_type + 1;
            sprintf(l_string,"CURRENT level : %d",level_type);
            gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) l_string);
            lives_type = 4;
            z = 0;

            gtk_label_set_text(GTK_LABEL(response_print), suppresion);

            gtk_widget_hide(X1);
            gtk_widget_hide(X2);
            gtk_widget_hide(X3);
        }
        else
        {
            gtk_label_set_text(GTK_LABEL(response_print), gtk_entry_get_text(e));
            position = position + 1;
        }
    }
    else
    {
        if (lives_type < 0)
        {
            gtk_widget_hide(response_entry);
            gtk_widget_hide(level_print);
            char end_level_type[128];
            sprintf(end_level_type,"YOU REACHED level : %d",level_type);
            gtk_label_set_text (GTK_LABEL(end_print), (const gchar*) end_level_type);
            gtk_widget_show(end_print);
            gtk_widget_show(restart);
            gtk_widget_hide(X1);
            gtk_widget_hide(X2);
            gtk_widget_hide(X3);
            const char *suppresion = "";
            gtk_label_set_text(GTK_LABEL(response_print), suppresion);
        }
        else
        {
            lives_type = lives_type - 1;
            position = 0;
            const char *suppresion = "";
            z = z + 1;
            gtk_entry_set_text(GTK_ENTRY(response_entry), suppresion);
            switch (z)
            {
            case 2:
                gtk_widget_show(X1);
                break;
            case 4:
                gtk_widget_show(X2);
                break;
            case 6:
                gtk_widget_show(X3);
                break;
            default:
                break;
            }
        }
        
    }
    
}

void on_restart_clicked_type ()
{
    gtk_widget_hide(end_print);
    gtk_widget_hide(restart);
    gtk_widget_show(start_button);
    gtk_widget_hide(number_print);
    gtk_widget_hide(response_print);
    level_type = 1;
    lives_type = 4;
    int i = 0;
    while (i < 10)
    {
        M[i] = 0;
        i = i + 1;
    }
    r = 0;
    z = 0;
}