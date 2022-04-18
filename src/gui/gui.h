#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include<stdlib.h>
#include "../property/mathematics/complex_number/complex_number.h"
#include "../mcqGenerator/mcqGenerator.h"

typedef struct User
{
    //User data
    char name[256];
    char password[256];
    char email[256];

    int score;

    // For the mcq
    struct Mcq* mcq;

    // mcq_training_mt1
    char answer_im[8];
    char answer_re[8];
    Complex* a;
    Complex* b;

    char answer_ct1[8];

    char answer_ct2[64];
} User;

GtkBuilder *init_gui();

#endif
