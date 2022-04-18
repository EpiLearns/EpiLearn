#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include<stdlib.h>
#include "../property/mathematics/complex_number/complex_number.h"

typedef struct User
{
    char name[256];
    char password[256];
    char email[256];

    char answer[8];
    char answer_im[8];
    char answer_re[8];
    char answer_archi[8];
    char answer_archi1[64];

    Complex* a;
    Complex* b;
    
} User;

GtkBuilder *init_gui();

#endif
