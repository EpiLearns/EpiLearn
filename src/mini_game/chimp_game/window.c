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


// game
int level = 1;
guint event;
int nb;
int l[26];
int m[26];
int current = 0;

void create_grid2(int level,  int l[], int m[]) // 0 en trop !! 
{
    int b = 0;
    while (b < 25)
    {
        l[b] = 0;
		m[b] = 0;
        b = b +1;
    }
    

    srand(time(NULL));
    int length = 24;
    int i = 1;
    while (i < level) // struct of the grid // <= ?
    {
        if (i%3 == 0)
        {
            length++;
        }
        i++;
    }

    int a = 0;
    int random;
    while (a < level)
    {
		if(m[a] == 0)
		{
			random = rand() % 24 + 1;
			l[a] = random;
			m[a] = 1;
			a++;
		}
    }
}
// signal

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

gboolean back_normal()
{
	gtk_widget_hide(green1);
	gtk_widget_hide(green2);
	gtk_widget_hide(green3);
	gtk_widget_hide(green4);
	gtk_widget_hide(green5);
	gtk_widget_hide(green6);
	gtk_widget_hide(green7);
	gtk_widget_hide(green8);
	gtk_widget_hide(green9);
	gtk_widget_hide(green10);
	gtk_widget_hide(green11);
	gtk_widget_hide(green12);
	gtk_widget_hide(green13);
	gtk_widget_hide(green14);
	gtk_widget_hide(green15);
	gtk_widget_hide(green16);
	gtk_widget_hide(green17);
	gtk_widget_hide(green18);
	gtk_widget_hide(green19);
	gtk_widget_hide(green20);
	gtk_widget_hide(green21);
	gtk_widget_hide(green22);
	gtk_widget_hide(green23);
	gtk_widget_hide(green24);
	gtk_widget_hide(green25);
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

	return TRUE;
}

gboolean print_button()
{	
	current = 0;
	while (current < level)
	{
		switch (l[current])
		{
			case 0:
				gtk_widget_show(button1);
				break;
			case 1:
				gtk_widget_show(button2);
				break;
			case 2:
				gtk_widget_show(button3);
				break;
			case 3:
				gtk_widget_show(button4);
				break;
			case 4:
				gtk_widget_show(button5);
				break;
			case 5:
				gtk_widget_show(button6);
				break;
			case 6:
				gtk_widget_show(button7);
				break;
			case 7:
				gtk_widget_show(button8);
				break;
			case 8:
				gtk_widget_show(button9);
				break;
			case 9:
				gtk_widget_show(button10);
				break;
			case 10:
				gtk_widget_show(button11);
				break;
			case 11:
				gtk_widget_show(button12);
				break;
			case 12:
				gtk_widget_show(button13);
				break;
			case 13:
				gtk_widget_show(button14);
				break;
			case 14:
				gtk_widget_show(button15);
				break;
			case 15:
				gtk_widget_show(button16);
				break;
			case 16:
				gtk_widget_show(button17);
				break;
			case 17:
				gtk_widget_show(button18);
				break;
			case 18:
				gtk_widget_show(button19);
				break;
			case 19:
				gtk_widget_show(button20);
				break;
			case 20:
				gtk_widget_show(button21);
				break;
			case 21:
				gtk_widget_show(button22);
				break;
			case 22:
				gtk_widget_show(button23);
				break;
			case 23:
				gtk_widget_show(button24);
				break;
			case 24:
				gtk_widget_show(button25);
				break;
			default:
				break;
		}
		current++;
	}
	current = 0;
	
	return FALSE;
}

gboolean back_button()
{
	gtk_widget_hide(green1);
	gtk_widget_hide(green2);
	gtk_widget_hide(green3);
	gtk_widget_hide(green4);
	gtk_widget_hide(green5);
	gtk_widget_hide(green6);
	gtk_widget_hide(green7);
	gtk_widget_hide(green8);
	gtk_widget_hide(green9);
	gtk_widget_hide(green10);
	gtk_widget_hide(green11);
	gtk_widget_hide(green12);
	gtk_widget_hide(green13);
	gtk_widget_hide(green14);
	gtk_widget_hide(green15);
	gtk_widget_hide(green16);
	gtk_widget_hide(green17);
	gtk_widget_hide(green18);
	gtk_widget_hide(green19);
	gtk_widget_hide(green20);
	gtk_widget_hide(green21);
	gtk_widget_hide(green22);
	gtk_widget_hide(green23);
	gtk_widget_hide(green24);
	gtk_widget_hide(green25);
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
	print_button();
	return TRUE;
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

	//green
	green1 = GTK_WIDGET(gtk_builder_get_object(builder, "green1"));
	green2 = GTK_WIDGET(gtk_builder_get_object(builder, "green2"));
	green3 = GTK_WIDGET(gtk_builder_get_object(builder, "green3"));
	green4 = GTK_WIDGET(gtk_builder_get_object(builder, "green4"));
	green5 = GTK_WIDGET(gtk_builder_get_object(builder, "green5"));
	green6 = GTK_WIDGET(gtk_builder_get_object(builder, "green6"));
	green7 = GTK_WIDGET(gtk_builder_get_object(builder, "green7"));
	green8 = GTK_WIDGET(gtk_builder_get_object(builder, "green8"));
	green9 = GTK_WIDGET(gtk_builder_get_object(builder, "green9"));
	green10 = GTK_WIDGET(gtk_builder_get_object(builder, "green10"));
	green11 = GTK_WIDGET(gtk_builder_get_object(builder, "green11"));
	green12 = GTK_WIDGET(gtk_builder_get_object(builder, "green12"));
	green13 = GTK_WIDGET(gtk_builder_get_object(builder, "green13"));
	green14 = GTK_WIDGET(gtk_builder_get_object(builder, "green14"));
	green15 = GTK_WIDGET(gtk_builder_get_object(builder, "green15"));
	green16 = GTK_WIDGET(gtk_builder_get_object(builder, "green16"));
	green17 = GTK_WIDGET(gtk_builder_get_object(builder, "green17"));
	green18 = GTK_WIDGET(gtk_builder_get_object(builder, "green18"));
	green19 = GTK_WIDGET(gtk_builder_get_object(builder, "green19"));
	green20 = GTK_WIDGET(gtk_builder_get_object(builder, "green20"));
	green21 = GTK_WIDGET(gtk_builder_get_object(builder, "green21"));
	green22 = GTK_WIDGET(gtk_builder_get_object(builder, "green22"));
	green23 = GTK_WIDGET(gtk_builder_get_object(builder, "green23"));
	green24 = GTK_WIDGET(gtk_builder_get_object(builder, "green24"));
	green25 = GTK_WIDGET(gtk_builder_get_object(builder, "green25"));


	level_print = GTK_WIDGET(gtk_builder_get_object(builder, "level"));

	gtk_widget_show(window);
	hide_all();
	gboolean x = back_normal();
	if(x == 123)
	{
		return 0;
	}
	

	gtk_widget_hide(restart);
	gtk_widget_hide(end_print);

	gtk_main();

	return EXIT_SUCCESS;
	}

// signal funtion

gboolean change_color()
{
	switch (l[current])
	{
		case 0:
			gtk_widget_show(green1);
			break;
		case 1:
			gtk_widget_show(green2);
			break;
		case 2:
			gtk_widget_show(green3);
			break;
		case 3:
			gtk_widget_show(green4);
			break;
		case 4:
			gtk_widget_show(green5);
			break;
		case 5:
			gtk_widget_show(green6);
			break;
		case 6:
			gtk_widget_show(green7);
			break;
		case 7:
			gtk_widget_show(green8);
			break;
		case 8:
			gtk_widget_show(green9);
			break;
		case 9:
			gtk_widget_show(green10);
			break;
		case 10:
			gtk_widget_show(green11);
			break;
		case 11:
			gtk_widget_show(green12);
			break;
		case 12:
			gtk_widget_show(green13);
			break;
		case 13:
			gtk_widget_show(green14);
			break;
		case 14:
			gtk_widget_show(green15);
			break;
		case 15:
			gtk_widget_show(green16);
			break;
		case 16:
			gtk_widget_show(green17);
			break;
		case 17:
			gtk_widget_show(green18);
			break;
		case 18:
			gtk_widget_show(green19);
			break;
		case 19:
			gtk_widget_show(green20);
			break;
		case 20:
			gtk_widget_show(green21);
			break;
		case 21:
			gtk_widget_show(green22);
			break;
		case 22:
			gtk_widget_show(green23);
			break;
		case 23:
			gtk_widget_show(green24);
			break;
		case 24:
			gtk_widget_show(green25);
			break;
		default:
			break;
	}
	current++;
	if (current == level)
	{
		g_timeout_add(1000,back_button,NULL);
		return FALSE;
	}
	
	return TRUE;
}


void change_level()
{
	create_grid2(level,l,m);
	nb = level;
	current = 0;
	char level_p[128];
    sprintf(level_p,"CURRENT LEVEL : %d",level);
    gtk_label_set_text (GTK_LABEL(level_print), (const gchar*) level_p);
	int sec = 1000;
	event = g_timeout_add(sec,change_color,NULL);
}

void	on_start_button_clicked () {
	gtk_widget_hide(start_button);
	gtk_widget_show(level_print);
	level = 3;
	current = 0;
	change_level(level);
	}

void on_restart_clicked ()
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
 


void	on_button_clicked (GtkButton *b) {
	const gchar *text = gtk_button_get_label (b);
	current = level - nb;
	int i;
	int a = atoi(text);
	i = a - 1;
	int x = l[current];
	current = current +1;
	if(x == i)
	{
		nb = nb - 1;
		if (nb == 0)
		{
			level = level+1;
			change_level();
		}
	}
	else
	{
		hide_all();
		end_window();
	}

}
