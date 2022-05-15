#ifndef __H__WIN_
#define __H__WIN_

#include<gtk/gtk.h>
#include<glib.h>
#include"shape.h"
#include"checker.h"



typedef struct _TetWin{
    TetChecker* checker;
    TetChecker* preview;
    TetShape*shape;
    GtkWidget* info;
    
    GtkWidget* start,*stop,*pause,*close;

    GtkWidget*window;

    gint score;
    gint time_start;
    gint timeout;
    gint key_sig_no;
    gboolean paused;

}TetWin;




TetWin* tet_window_new();
void tet_window_set_preview(TetWin*win,Shape type);
void tet_window_set_info(TetWin*win);
void tet_window_set_shape(TetWin*win,TetShape*shape);

void tet_window_over(TetWin*tetwin);
void tet_window_reset(TetWin*win);


#endif