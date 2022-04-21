#ifndef MCQGENERATOR_H
#define MCQGENERATOR_H

#include<stdlib.h>
#include <gtk/gtk.h>

typedef struct McqObject
{
    GtkButton* valide_button;
    GtkWidget* question_text;

    GtkWidget* user_answer_object1;
    GtkWidget* user_answer_object2;

    GtkWidget* answer_text;

    GtkWidget* question_number_text;
    GtkWidget* score_text;

    GtkButton* prev_button;
    GtkButton* next_button;

} McqObject;

typedef struct Mcq
{
    int question_number; //

    char question[256]; //

    char answer1[256]; //
    char answer2[256]; //

    char user_answer1[256];
    char user_answer2[256];

    char correction[256]; //

    int activate_validate_button; //
    int already_done; //

    int activate_prev_button; //
    int activate_next_button; //

    struct Mcq *next_question; //
    struct Mcq *previous_question; //

} Mcq;

typedef struct User
{
    int score;

    // For the mcq
    struct Mcq* mcq;
    struct McqObject* mcqObject;

} User;

#endif