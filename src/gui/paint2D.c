#include "paint2D.h"

#define CHECK(pointer) \
        if(pointer == NULL) \
            return;

gboolean on_draw_paint(GtkWidget* widget,cairo_t* context, gpointer user)
{
    cairo_set_source_surface(context,surface,0,0);
    cairo_paint(context);

    return TRUE; //empêche le signal de se propager (callback suivant)
}

gboolean on_motion_paint(GtkWidget* widget,GdkEvent* event, gpointer user)
{
    GdkEventMotion* e = (GdkEventMotion*) event;

    double x = e->x;
    double y = e->y;

    cairo_t* context = cairo_create(surface);
    //cairo_set_source_rgba(context,1,1,1,1);

    cairo_rectangle(context,x,y,10,10);
    cairo_fill(context);
    cairo_destroy(context);

    gtk_widget_queue_draw_area(widget,0,0,700,450); // draw area size

    return TRUE;
}

/*void get_paint_object()
{
    Paint2DWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.paint2d"));

    surface = gdk_window_create_similar_surface(gtk_widget_get_parent_window(paint_draw_area),CAIRO_CONTENT_COLOR,700,450);
    paint_draw_area = GTK_WIDGET(gtk_builder_get_object(builder, "paint_draw_area"));

    paint_write = GTK_BUTTON(gtk_builder_get_object(builder,"paint_write"));
    paint_erase = GTK_BUTTON(gtk_builder_get_object(builder,"paint_erase"));
}*/

/*void paint_signal()
{
    g_signal_connect(paint_draw_area,"draw",G_CALLBACK(on_draw_paint),NULL);
    g_signal_connect(paint_draw_area,"motion-notify-event",G_CALLBACK(on_motion_paint),NULL);
}*/

/*void open_paint2D_fct()
{
    gtk_init(NULL, NULL);
    builder = gtk_builder_new ();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, "../res/Paint2D.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
    }

    get_paint_object();
    paint_signal();
    
    gtk_widget_add_events(paint_draw_area,GDK_POINTER_MOTION_MASK);

    cairo_t* context = cairo_create(surface);
    cairo_set_source_rgba(context,1,1,1,1);

    cairo_paint(context);
    cairo_destroy(context);

    // Connects event handlers.
    g_signal_connect(Paint2DWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(GTK_WIDGET(Paint2DWindow));

    // Run the main window.
    gtk_main();
}*/

void open_paint2D_fct(GtkApplication* app,gpointer user)
{
    gtk_init(NULL, NULL);

    builder = gtk_builder_new_from_file("../res/Paint2D.glade");
    CHECK(builder)

    Paint2DWindow = GTK_WIDGET(gtk_builder_get_object(builder, "org.epilearn.paint2d"));
    CHECK(Paint2DWindow)

    paint_draw_area = GTK_WIDGET(gtk_builder_get_object(builder, "paint_draw_area"));
    CHECK(paint_draw_area);

    gtk_widget_add_events(paint_draw_area,GDK_POINTER_MOTION_MASK);
    g_signal_connect(paint_draw_area,"motion-notify-event",G_CALLBACK(on_motion_paint),NULL);
    
    g_signal_connect(paint_draw_area,"draw",G_CALLBACK(on_draw_paint),NULL);
    g_signal_connect(Paint2DWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(Paint2DWindow);

    surface = gdk_window_create_similar_surface(gtk_widget_get_parent_window(paint_draw_area),CAIRO_CONTENT_COLOR,700,450); //window surface size

    cairo_t* context = cairo_create(surface);
    cairo_set_source_rgba(context,1,1,1,1);

    cairo_paint(context);
    cairo_destroy(context);

    gtk_main();
}