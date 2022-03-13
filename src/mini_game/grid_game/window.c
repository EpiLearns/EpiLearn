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

GtkWidget	*level_print;


// game
int level = 1;
guint event;
int lives = 3;
int nb;
int l[26];

void create_grid2(int level,  int l[]) // 0 en trop !! 
{
    int b = 0;
    while (b < 25)
    {
        l[b] = 0;
        b =b +1;
    }
    

    srand(time(NULL));
    int length = 3;
    int nb = 1;
    int i = 1;
    while (i < level) // struct of the grid // <= ?
    {
        if (i%3 == 0)
        {
            length++;
        }
        nb++; // +1 ?
        i++;
    }

    int length_length = length*length;
    int a = 0;
    int random;
    while (a < nb)
    {
        random = rand() % length_length + 1;
        if (l[random] == 0)
        {
            l[random] = 1;
            a++;
        }
    }
    
}

// signal

G_MODULE_EXPORT void	on_start_button_clicked (GtkButton *b);

void hide_all()
{
	gtk_widget_hide(button1);
	gtk_widget_hide(button2);
	gtk_widget_hide(button3);
	gtk_widget_hide(button4);
	gtk_widget_hide(button5);
	gtk_widget_hide(button6);
	gtk_widget_hide(button7);
	gtk_widget_hide(button8);
	gtk_widget_hide(button9);
	gtk_widget_hide(button10);
	gtk_widget_hide(button11);
	gtk_widget_hide(button12);
	gtk_widget_hide(button13);
	gtk_widget_hide(button14);
	gtk_widget_hide(button15);
	gtk_widget_hide(button16);
	gtk_widget_hide(button17);
	gtk_widget_hide(button18);
	gtk_widget_hide(button19);
	gtk_widget_hide(button20);
	gtk_widget_hide(button21);
	gtk_widget_hide(button22);
	gtk_widget_hide(button23);
	gtk_widget_hide(button24);
	gtk_widget_hide(button25);
	gtk_widget_hide(level_print);
}

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("window.glade");
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_builder_connect_signals(builder, NULL);

	start_fixed = GTK_WIDGET(gtk_builder_get_object(builder, "start_fixed"));
	start_button = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
    end_print = GTK_WIDGET(gtk_builder_get_object(builder, "end_print"));
    restart = GTK_WIDGET(gtk_builder_get_object(builder, "restart"));
	// button
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
	button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
	button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
	button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));
	button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
	button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));
	button7 = GTK_WIDGET(gtk_builder_get_object(builder, "button7"));
	button8 = GTK_WIDGET(gtk_builder_get_object(builder, "button8"));
	button9 = GTK_WIDGET(gtk_builder_get_object(builder, "button9"));
	button10 = GTK_WIDGET(gtk_builder_get_object(builder, "button10"));
	button11 = GTK_WIDGET(gtk_builder_get_object(builder, "button11"));
	button12 = GTK_WIDGET(gtk_builder_get_object(builder, "button12"));
	button13 = GTK_WIDGET(gtk_builder_get_object(builder, "button13"));
	button14 = GTK_WIDGET(gtk_builder_get_object(builder, "button14"));
	button15 = GTK_WIDGET(gtk_builder_get_object(builder, "button15"));
	button16 = GTK_WIDGET(gtk_builder_get_object(builder, "button16"));
	button17 = GTK_WIDGET(gtk_builder_get_object(builder, "button17"));
	button18 = GTK_WIDGET(gtk_builder_get_object(builder, "button18"));
	button19 = GTK_WIDGET(gtk_builder_get_object(builder, "button19"));
	button20 = GTK_WIDGET(gtk_builder_get_object(builder, "button20"));
	button21 = GTK_WIDGET(gtk_builder_get_object(builder, "button21"));
	button22 = GTK_WIDGET(gtk_builder_get_object(builder, "button22"));
	button23 = GTK_WIDGET(gtk_builder_get_object(builder, "button23"));
	button24 = GTK_WIDGET(gtk_builder_get_object(builder, "button24"));
	button25 = GTK_WIDGET(gtk_builder_get_object(builder, "button25"));

	level_print = GTK_WIDGET(gtk_builder_get_object(builder, "level"));

	gtk_widget_show(window);
	hide_all();

	gtk_widget_hide(restart);
	gtk_widget_hide(end_print);

	gtk_main();

	return EXIT_SUCCESS;
	}

// signal funtion

void change_color()
{
	int i = 0;
	int length;
	char s[] = "ME";
	if(level < 3)
	{
		length = 9;
	}
	else
	{
		if (level < 6)
		{
			length = 16;
		}
		else
		{
			length = 25;
		}
	}
	while (i < length)
	{
		if (l[i] == 1)
		{
			switch (i)
			{
			case 0:
				gtk_button_set_label (GTK_BUTTON(button1), (const gchar*) s);
				break;
			case 1:
				gtk_button_set_label (GTK_BUTTON(button2), (const gchar*) s);
				break;
			case 2:
				gtk_button_set_label (GTK_BUTTON(button3), (const gchar*) s);
				break;
			case 3:
				gtk_button_set_label (GTK_BUTTON(button4), (const gchar*) s);
				break;
			case 4:
				gtk_button_set_label (GTK_BUTTON(button5), (const gchar*) s);
				break;
			case 5:
				gtk_button_set_label (GTK_BUTTON(button6), (const gchar*) s);
				break;
			case 6:
				gtk_button_set_label (GTK_BUTTON(button7), (const gchar*) s);
				break;
			case 7:
				gtk_button_set_label (GTK_BUTTON(button8), (const gchar*) s);
				break;
			case 8:
				gtk_button_set_label (GTK_BUTTON(button9), (const gchar*) s);
				break;
			default:
				break;
			}
		}
		i = i + 1;	
	}	
}

gboolean back_normal()
{
	int i = 0;
	char s[1] = "";
	int length;
	if(level < 3)
	{
		length = 9;
	}
	else
	{
		if (level < 6)
		{
			length = 16;
		}
		else
		{
			length = 25;
		}
	}
	while (i<length)
	{
		switch (i)
		{
		case 0:
			gtk_button_set_label (GTK_BUTTON(button1), (const gchar*) s);
			break;
		case 1:
			gtk_button_set_label (GTK_BUTTON(button2), (const gchar*) s);
			break;
		case 2:
			gtk_button_set_label (GTK_BUTTON(button3), (const gchar*) s);
			break;
		case 3:
			gtk_button_set_label (GTK_BUTTON(button4), (const gchar*) s);
			break;
		case 4:
			gtk_button_set_label (GTK_BUTTON(button5), (const gchar*) s);
			break;
		case 5:
			gtk_button_set_label (GTK_BUTTON(button6), (const gchar*) s);
			break;
		case 6:
			gtk_button_set_label (GTK_BUTTON(button7), (const gchar*) s);
			break;
		case 7:
			gtk_button_set_label (GTK_BUTTON(button8), (const gchar*) s);
			break;
		case 8:
			gtk_button_set_label (GTK_BUTTON(button9), (const gchar*) s);
			break;
		case 9:
			gtk_button_set_label (GTK_BUTTON(button10), (const gchar*) s);
			break;
		case 10:
			gtk_button_set_label (GTK_BUTTON(button11), (const gchar*) s);
			break;
		case 11:
			gtk_button_set_label (GTK_BUTTON(button12), (const gchar*) s);
			break;
		case 12:
			gtk_button_set_label (GTK_BUTTON(button13), (const gchar*) s);
			break;
		case 13:
			gtk_button_set_label (GTK_BUTTON(button14), (const gchar*) s);
			break;
		case 14:
			gtk_button_set_label (GTK_BUTTON(button5), (const gchar*) s);
			break;
		case 15:
			gtk_button_set_label (GTK_BUTTON(button6), (const gchar*) s);
			break;
		case 16:
			gtk_button_set_label (GTK_BUTTON(button17), (const gchar*) s);
			break;
		case 17:
			gtk_button_set_label (GTK_BUTTON(button18), (const gchar*) s);
			break;
		case 18:
			gtk_button_set_label (GTK_BUTTON(button19), (const gchar*) s);
			break;
		case 19:
			gtk_button_set_label (GTK_BUTTON(button20), (const gchar*) s);
			break;
		case 20:
			gtk_button_set_label (GTK_BUTTON(button21), (const gchar*) s);
			break;
		case 21:
			gtk_button_set_label (GTK_BUTTON(button22), (const gchar*) s);
			break;
		case 22:
			gtk_button_set_label (GTK_BUTTON(button23), (const gchar*) s);
			break;
		case 23:
			gtk_button_set_label (GTK_BUTTON(button24), (const gchar*) s);
			break;
		case 24:
			gtk_button_set_label (GTK_BUTTON(button25), (const gchar*) s);
			break;
		default:
			break;
		}
		i = i + 1;
	}
	
	
	return FALSE;
}

void change_level()
{
	create_grid2(level,l);
	nb = level;
	if (level == 6)
	{
		gtk_widget_show(button10);
		gtk_widget_show(button11);
		gtk_widget_show(button12);
		gtk_widget_show(button13);
		gtk_widget_show(button14);
		gtk_widget_show(button15);
		gtk_widget_show(button16);
	}
	if(level == 9)
	{
		gtk_widget_show(button17);
		gtk_widget_show(button18);
		gtk_widget_show(button19);
		gtk_widget_show(button20);
		gtk_widget_show(button21);
		gtk_widget_show(button22);
		gtk_widget_show(button23);
		gtk_widget_show(button24);
		gtk_widget_show(button25);
	}
	char level_p[128];
    sprintf(level_p,"CURRENT LEVEL : %d",level);
    gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) level_p);
	change_color();
	event = g_timeout_add(5000, back_normal, button1);
	
}

void	on_start_button_clicked (GtkButton *b) {
	gtk_widget_hide(start_button);
	gtk_widget_show(level_print);
	gtk_widget_show(button1);
	gtk_widget_show(button2);
	gtk_widget_show(button3);
	gtk_widget_show(button4);
	gtk_widget_show(button5);
	gtk_widget_show(button6);
	gtk_widget_show(button7);
	gtk_widget_show(button8);
	gtk_widget_show(button9);
	level = 1;
	lives = 3;
	change_level();
	}

void on_restart_clicked (GtkButton *b)
{
    gtk_widget_hide(end_print);
    gtk_widget_hide(restart);
    gtk_widget_show(start_button);
}

void end_window()
{
	char end_level[128];
    sprintf(end_level,"YOU REACHED LEVEL : %d",level);
    gtk_label_set_text (GTK_LABEL(end_print), (const gchar*) end_level);
	gtk_widget_show(end_print);
    gtk_widget_show(restart);
}
 


void	on_button1_clicked (GtkButton *b) {
	if(l[0] == 1)
	{
		l[0] == 2;
		nb = nb - 1;
	}
	if(l[0] == 0)
	{
		lives = lives - 1;
	}
	if (nb == 0)
	{
		level = level+1;
		change_level();
	}
	if (lives < 0)
	{
		hide_all();
		end_window();
	}
	else 
	{
		nb = nb;
	}
}