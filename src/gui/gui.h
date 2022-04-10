#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include<stdlib.h>
#include "../property/mathamatics/complex_number/complex_number.h"

typedef struct User
{
    char name[256];
    char password[256];
    char email[256];

    char answer[8];
    int num_of_question;
    int score;

    int qmt1;
    int scoremt1;
    char answer_im[8];
    char answer_re[8];
    Complex* a;
    Complex* b;
    
} User;

GtkBuilder *init_gui();

#endif
