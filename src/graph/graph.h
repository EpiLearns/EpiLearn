/*#ifndef GRAPH_H
#define GRAPH_H

#include "node.h"

double f1 (double x);

static gboolean on_draw (GtkWidget *widget, cairo_t *cr);

void on_button2_clicked();

void on_button1_clicked();

void on_plusbutton_clicked();

void on_minusbutton_clicked();

void on_quitbutton_clicked(gpointer user_data);

void open_graphe();

char* replaceWord(char* s, char* oldW,char* newW);

int checkSyntax(char* string);
     
void removeSpaces(char* str);

int findMatchingParenthesisIndexRight(char* string, int index);//Not used, but useful to have anyways

int findMatchingParenthesisIndexLeft(char* string, int index);

node* createNode(void);

double evaluate(node* head);

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double divi(double a, double b);
double power(double a, double b);

#endif*/