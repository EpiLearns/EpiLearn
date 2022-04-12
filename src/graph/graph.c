#include <gtk/gtk.h>
#include <math.h>
#include <cairo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "parser.h"

GtkBuilder *builder;
GtkWidget *entry1;


#define WIDTH   640
#define HEIGHT  480

double ZOOM_X  = 100.0;
double ZOOM_Y  = 100.0;


char* expression = NULL;

double f (double x)
{
    /*function that calculates the expression */
    node* head;
    double result;
    char* res = NULL;
    char *s = malloc(sizeof(double));
    sprintf(s,"(%.2f)", x);
    res = replaceWord(expression, "x", s);
    int syntax = checkSyntax(res);
    if(syntax)
    {
        head = parseExpression(res);
        result = evaluate(head);
    }
    return result;
    


}


static gboolean
on_draw (GtkWidget *widget, cairo_t *cr)
{
    GdkRectangle da;            /* GtkDrawingArea size */
    double dx = 5.0, dy = 5.0; /* Pixels between each point */
    double i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
    GtkDrawingArea *window = GTK_DRAWING_AREA(widget);//user_data;

    /* Determine GtkDrawingArea dimensions */
    da.x = 0;
    da.y = 0;
    da.height = gtk_widget_get_allocated_height((GtkWidget*) window);
    da.width = gtk_widget_get_allocated_width((GtkWidget*) window);
    
    /*gdk_window_get_geometry (window,
            &da.x,
            &da.y,
            &da.width,
            &da.height);
    */
    cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
    cairo_paint (cr);

    /* Change the transformation matrix */
    cairo_translate (cr, da.width / 2, da.height / 2);
    cairo_scale (cr, ZOOM_X, -ZOOM_Y);

    /* Determine the data points to calculate (ie. those in the clipping zone */
    cairo_device_to_user_distance (cr, &dx, &dy);
    cairo_clip_extents (cr, &clip_x1, &clip_y1, &clip_x2, &clip_y2);
    cairo_set_line_width (cr, dx);

    /* Draws x and y axis */
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    cairo_move_to (cr, clip_x1, 0.0);
    cairo_line_to (cr, clip_x2, 0.0);
    cairo_move_to (cr, 0.0, clip_y1);
    cairo_line_to (cr, 0.0, clip_y2);
    cairo_stroke (cr);

    
    /* Link each data point */
    for (i = clip_x1; i < clip_x2; i += dx)
    {
        if (expression == NULL)
        {
            break;
        } 
        cairo_line_to (cr, i, f (i));
        
    }
    /* Draw the curve */
    cairo_set_source_rgba (cr, 1, 0.2, 0.2, 0.6);
    cairo_stroke (cr);
    

    return FALSE;
}

void on_button2_clicked()
{
    /*function that clear the entry text and sets the expression to NULL*/
    expression = NULL;
    const char *entry_value = "";
    gtk_entry_set_text(GTK_ENTRY(entry1), entry_value);
    g_print("expression when button2 = %s\n", expression);
    
    
}


void on_button1_clicked()
{
    /*function that retrieves the input*/
    const char *entry_value; 
    entry_value = gtk_entry_get_text(GTK_ENTRY(entry1));
    expression = strdup(entry_value);
}

void on_plusbutton_clicked()
{
    ZOOM_X = ZOOM_X + (double)10;
    ZOOM_Y = ZOOM_Y + (double)10;
}

void on_minusbutton_clicked()
{
    ZOOM_X = ZOOM_X -(double)10;
    ZOOM_Y = ZOOM_Y - (double)10;
}

void on_quitbutton_clicked(gpointer user_data)
{
    gtk_window_close(user_data);
}

int main (int argc, char **argv)
{
    
    GtkWidget *window;
    GtkWidget *da;
    GtkWidget *button1;
    GtkWidget *plusbutton;
    GtkWidget *minusbutton;
    GtkWidget *quitbutton;


    
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file("../src/graph/graph.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    gtk_builder_connect_signals(builder, NULL);
    entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    plusbutton = GTK_WIDGET(gtk_builder_get_object(builder, "plusbutton"));
    minusbutton = GTK_WIDGET(gtk_builder_get_object(builder, "minusbutton"));
    quitbutton = GTK_WIDGET(gtk_builder_get_object(builder, "quitbutton"));
    da = GTK_WIDGET(gtk_builder_get_object(builder, "da"));


    gtk_window_set_title (GTK_WINDOW (window), "Graph drawing");
    g_signal_connect (G_OBJECT (window), "destroy", gtk_main_quit, NULL);
    g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(on_button1_clicked),NULL);
    g_signal_connect(G_OBJECT(plusbutton), "clicked", G_CALLBACK(on_plusbutton_clicked),NULL);
    g_signal_connect(G_OBJECT(minusbutton), "clicked", G_CALLBACK(on_minusbutton_clicked),NULL);
    g_signal_connect(G_OBJECT(quitbutton), "clicked", G_CALLBACK(on_quitbutton_clicked), window);
    g_signal_connect (G_OBJECT (da),"draw",G_CALLBACK (on_draw),da);

    gtk_widget_show_all(window);
    gtk_main ();

    return 0;
}