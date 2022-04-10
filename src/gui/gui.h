#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include<stdlib.h>

typedef struct User
{
    char name[256];
    char password[256];
    char email[256];

    int num_of_question;
    int score;
    
} User;

GtkBuilder *init_gui();

#endif
