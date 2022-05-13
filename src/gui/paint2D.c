#include "paint2D.h"

int largeur=700,hauteur=450,bordure=8;
//gdouble coordx,coordy;

gboolean draw_cb (GtkWidget *widget,cairo_t *cr,gpointer data);

void clear_surface (void)
{
    cairo_t *cr = cairo_create (surface);

    cairo_set_source_rgb (cr, 1, 1, 1);
    cairo_paint (cr);

    cairo_destroy (cr);
}

gboolean configure_event_cb (GtkWidget* widget,GdkEventConfigure *event,gpointer data)
{
    if (surface)
        cairo_surface_destroy (surface);

    surface = gdk_window_create_similar_surface (gtk_widget_get_window (widget),CAIRO_CONTENT_COLOR,gtk_widget_get_allocated_width (widget),gtk_widget_get_allocated_height (widget));

    clear_surface ();

    return TRUE;
}

gboolean draw_cb (GtkWidget *widget, cairo_t *cr, gpointer   data)
{
    cairo_set_source_surface (cr, surface, 0, 0);
    cairo_paint (cr);

    return FALSE;
}

void draw_brush (GtkWidget *widget, gdouble x,gdouble y)
{

    /*gdouble ecartx = x - coordx;
    gdouble ecarty = y - coordy;

    if (ecartx>0 && ecarty>0)
    {
        if (ecartx>ecarty)
        {
            gdouble inc = ecartx/ecarty;

            while(coordx < x)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr, coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx += 1;
                coordy += inc;
            }

            return;
        }

        else
        {
            gdouble inc = ecarty/ecartx;

            while(coordy < y)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr, coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx += inc;
                coordy += 1;
            }

            return;
        }

    }

    if (ecartx<0 && ecarty<0)
    {
        if (ecartx>ecarty)
        {
            gdouble inc = -(ecarty/ecartx);

            while(coordx > x)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr,coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx -= 1;
                coordy -= inc;
            }

            return;
        }

        else
        {
            gdouble inc = -(ecartx/ecarty);

            while(coordy > y)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr, coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx -= inc;
                coordy -= 1;
            }

            return;
        }
    }

    if (ecartx<0 && ecarty>0)
    {
        if (-ecartx<ecarty)
        {
            gdouble inc = -(ecarty/ecartx);

            while(coordx > x)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr,coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx -= 1;
                coordy += inc;
            }

            return;
        }

        else
        {
            gdouble inc = -(ecartx/ecarty);

            while(coordy < y)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr, coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx -= inc;
                coordy += 1;
            }

            return;
        }
    }

    if (ecartx>0 && ecarty<0)
    {
        if (ecartx<-ecarty)
        {
            gdouble inc = -(ecartx/ecarty);

            while(coordx < x)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr,coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx += 1;
                coordy -= inc;
            }

            return;
        }

        else
        {
            gdouble inc = -(ecarty/ecartx);

            while(coordy > y)
            {
                cairo_t *cr = cairo_create (surface);

                cairo_rectangle (cr, coordx - 3, coordy - 3, 10, 10);
                cairo_fill (cr);

                cairo_destroy (cr);
                gtk_widget_queue_draw_area (widget, coordx - 3, coordy - 3, 6, 6);

                coordx += inc;
                coordy -= 1;
            }

            return;
        }
    }*/

    
    cairo_t *cr = cairo_create (surface);

    cairo_rectangle (cr, x, y, 10, 10);
    cairo_fill (cr);

    cairo_destroy (cr);
    gtk_widget_queue_draw_area (widget, x, y, largeur, hauteur);

    /*coordx = x;
    coordy = y;*/
}

gboolean button_press_event_cb (GtkWidget *widget,GdkEventButton *event,gpointer data)
{
    if (event->button == GDK_BUTTON_PRIMARY)
    {
        //coordx = event->x;
        //coordy = event->y;
        
        draw_brush (widget, event->x, event->y);
    }
    else if (event->button == GDK_BUTTON_SECONDARY)
    {
        clear_surface ();
        gtk_widget_queue_draw (widget);
    }

    return TRUE;
}

gboolean motion_notify_event_cb (GtkWidget *widget,GdkEventMotion *event,gpointer data)
{
    if (event->state & GDK_BUTTON1_MASK)
    {
        draw_brush (widget, event->x, event->y);
    }

    return TRUE;
}

void open_paint2D_fct()
{
    gtk_init (NULL,NULL);

    builder = gtk_builder_new_from_file("../res/Paint2D.glade");

    Paint2DWindow = GTK_WIDGET(gtk_builder_get_object(builder, "org.epilearn.paint2d"));
    
    g_signal_connect (Paint2DWindow, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    paint_draw_area = GTK_WIDGET(gtk_builder_get_object(builder, "paint_draw_area"));

    g_signal_connect (paint_draw_area, "draw",G_CALLBACK (draw_cb), NULL);
    g_signal_connect (paint_draw_area,"configure-event",G_CALLBACK (configure_event_cb), NULL);

    g_signal_connect (paint_draw_area, "motion-notify-event",G_CALLBACK (motion_notify_event_cb), NULL);
    g_signal_connect (paint_draw_area, "button-press-event",G_CALLBACK (button_press_event_cb), NULL);

    gtk_widget_set_events (paint_draw_area, gtk_widget_get_events (paint_draw_area)| GDK_BUTTON_PRESS_MASK| GDK_POINTER_MOTION_MASK);

    gtk_widget_show_all (Paint2DWindow);

    gtk_main ();
}