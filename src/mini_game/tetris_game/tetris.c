#include<gtk/gtk.h>
#include<glib.h>

#include"checker.h"
#include"shape.h"
#include"tetwin.h"

#include "tetris.h"

TetShape *curshape, *nextshape;


GRand *randomp;

gboolean timeout_act(TetWin*win)
{
    int n_eliminated;
    CollisionType col;
    //TetShape*shape=win->shape;
    TetChecker*checker=win->checker;
    //TetChecker*preview=win->preview;

    /*fall*/
    tet_shape_move_down(win->shape);

    col=tet_shape_is_collision(win->shape);
    if(COLLISION_FILL &col)
    {
        //can not fall anymore;
        tet_shape_move_restore(win->shape);
        n_eliminated=tet_checker_eliminate(checker,win->shape->x);
        win->score+=n_eliminated; 

        tet_window_set_info(win);
        tet_shape_free(win->shape);
        
        /*get next shape*/
        //win->shape=nextshape;
        tet_window_set_shape(win,nextshape);

        col=tet_shape_is_collision(win->shape);
        if(COLLISION_FILL&col)
        {
            //g_message("GameOver..");
            tet_window_over(win);
            return FALSE;
        }
        tet_shape_realize(win->shape);
 
        Shape next=get_shape_type();
        nextshape=tet_shape_new(checker,0,3,next);
        tet_window_set_preview(win,next);

        return TRUE;
    }
    else
    {
        tet_shape_realize(win->shape);
        return TRUE;
    } 
}


gboolean move_cb(GtkWidget * widget, GdkEventKey * event, TetWin*win)
{
    TetShape * shape=win->shape;
    if (event->type == GDK_KEY_PRESS) 
    {
        if (event->keyval == GDK_KEY_Left||event->keyval == GDK_KEY_h) 
        {
            tet_shape_move_left(shape);
            if (tet_shape_is_collision(shape) & COLLISION_FILL) 
            {
                tet_shape_move_restore(shape);
            } 
            else 
            {
                tet_shape_realize(shape);
            }

        } 
        else if (event->keyval == GDK_KEY_Right||event->keyval == GDK_KEY_l) 
        {
            tet_shape_move_right(shape);
            if (tet_shape_is_collision(shape) & COLLISION_FILL) 
            {
                tet_shape_move_restore(shape);
            } 
            else 
            {
                tet_shape_realize(shape);
            }
        } 
        else if (event->keyval == GDK_KEY_Down||event->keyval == GDK_KEY_j) 
        {
            timeout_act(win);
        }
        else if(event->keyval==GDK_KEY_Up||event->keyval == GDK_KEY_k)
        {
            tet_shape_transform(shape);
            if(tet_shape_is_collision(shape)&COLLISION_FILL)
            {
                //    tet_shape_move_restore(shape);
                tet_shape_transform_restore(shape);
            }
            else
            {
                tet_shape_realize(shape);
            }
        }
    }

    useless_widget2 = widget;

    return TRUE;
}

void close_cb(GtkWidget *widget, TetWin *tetwin)
{
    
    g_source_remove(tetwin->timeout);
    g_signal_handler_disconnect(tetwin->window,tetwin->key_sig_no);
    GtkWidget*msgdialog=gtk_message_dialog_new(GTK_WINDOW(tetwin->window),GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_CLOSE,"Your score is %d.",tetwin->score);

    if(GTK_RESPONSE_CLOSE==gtk_dialog_run(GTK_DIALOG(msgdialog)))
    {    
        tet_window_reset(tetwin);
        tet_checker_clear_all (tetwin->checker);
        tet_checker_clear_all (tetwin->preview);
        tet_checker_fill_all(tetwin->checker,FALSE);
    }
    gtk_widget_destroy(msgdialog);
    gtk_widget_set_sensitive(tetwin->start,TRUE);
    gtk_widget_set_sensitive(tetwin->pause,FALSE);
    gtk_widget_set_sensitive(tetwin->stop,FALSE);

    /*tet_checker_clear_all (tetwin->checker);
    tet_checker_clear_all (tetwin->preview);
    tet_checker_fill_all(tetwin->checker,FALSE);
    tet_window_reset(tetwin);*/
    gtk_widget_destroy(tetwin->window);

    useless_widget2 = widget;
}

void stop_cb (GtkWidget * widget, TetWin * tetwin)
{
    g_source_remove(tetwin->timeout);
    g_signal_handler_disconnect(tetwin->window,tetwin->key_sig_no);
    GtkWidget*msgdialog=gtk_message_dialog_new(GTK_WINDOW(tetwin->window),GTK_DIALOG_MODAL|GTK_DIALOG_DESTROY_WITH_PARENT,GTK_MESSAGE_INFO,GTK_BUTTONS_CLOSE,"Your score is %d.",tetwin->score);

    if(GTK_RESPONSE_CLOSE==gtk_dialog_run(GTK_DIALOG(msgdialog)))
    {    
        tet_window_reset(tetwin);
        tet_checker_clear_all (tetwin->checker);
        tet_checker_clear_all (tetwin->preview);
        tet_checker_fill_all(tetwin->checker,FALSE);
    }
    gtk_widget_destroy(msgdialog);
    gtk_widget_set_sensitive(tetwin->start,TRUE);
    gtk_widget_set_sensitive(tetwin->pause,FALSE);
    gtk_widget_set_sensitive(tetwin->stop,FALSE);

    useless_widget2 = widget;
}


void
pause_cb (GtkWidget * widget, TetWin * tetwin)
{
    if(tetwin->paused)
    {
        //restart
        gtk_button_set_label(GTK_BUTTON(tetwin->pause),"Pause");
        tetwin->paused=FALSE;
        g_signal_handler_unblock(tetwin->window,tetwin->key_sig_no);
        tetwin->timeout=g_timeout_add(1000,(GSourceFunc)timeout_act,tetwin);
    }
    else
    {
        gtk_button_set_label(GTK_BUTTON(tetwin->pause),"Resume");
    
        tetwin->paused=TRUE;
        g_signal_handler_block(tetwin->window,tetwin->key_sig_no);
        g_source_remove(tetwin->timeout);
    }

    useless_widget2 = widget;
}




void
start_cb (GtkWidget * widget, TetWin * tetwin)
{
    tet_window_reset(tetwin);
    tet_checker_clear_all (tetwin->checker);
    tet_checker_clear_all (tetwin->preview);
    tet_checker_fill_all(tetwin->checker,FALSE);

    Shape cur,next;
    next=get_shape_type();
    tet_window_set_preview (tetwin, next);
    nextshape = tet_shape_new (tetwin->checker, 0, CHECKER_MID, next);
  
    cur=get_shape_type();
    curshape = tet_shape_new (tetwin->checker, -1, CHECKER_MID, cur);
    tetwin->shape=curshape;

    tetwin->timeout=g_timeout_add(800,(GSourceFunc)timeout_act,tetwin);

    tetwin->key_sig_no=g_signal_connect(G_OBJECT(tetwin->window), "key-press-event",G_CALLBACK(move_cb), tetwin);

    gtk_widget_set_sensitive(tetwin->start,FALSE);
    gtk_widget_set_sensitive(tetwin->pause,TRUE);
    gtk_widget_set_sensitive(tetwin->stop,TRUE);

    useless_widget2 = widget;
}


void open_tetris_fct ()
{
    gtk_init (NULL,NULL);

    TetWin *tetwin = tet_window_new ();

    randomp = g_rand_new();

    gtk_widget_show_all (tetwin->window);

    GtkWidget*but_start = tetwin->start;
    GtkWidget*but_stop = tetwin->stop;
    GtkWidget*but_pause = tetwin->pause;
    GtkWidget*but_close = tetwin->close;

    g_signal_connect(G_OBJECT(but_start),"clicked",G_CALLBACK(start_cb),tetwin);
    g_signal_connect(G_OBJECT(but_stop),"clicked",G_CALLBACK(stop_cb),tetwin);
    g_signal_connect(G_OBJECT(but_pause),"clicked",G_CALLBACK(pause_cb),tetwin);
    g_signal_connect(G_OBJECT(but_close),"clicked",G_CALLBACK(close_cb),tetwin);

    gtk_main ();
}