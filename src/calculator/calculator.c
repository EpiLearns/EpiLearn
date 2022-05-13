#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"
#include "node.h"
#include "parser.h"
#include <math.h>

GtkBuilder *builder;
GtkWidget *entrycalculator;
GtkButton *openintegral;
GtkWidget *labelcalculator;
char *expressioncalculator = "";


const char *calculator_f(char *expression)
{
    node *head;
    double result;

    int syntax = calculator_checkSyntax(expression);
    if (syntax)
    {
        head = calculator_parseExpression(expression);
        result = calculator_evaluate(head);
    }
    const char *s = malloc(sizeof(double));
    sprintf((char *)s, "%.2f", result);
    return s;
}

void on_button_enter_calculator()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    gtk_label_set_text(GTK_LABEL(labelcalculator), calculator_f(expressioncalculator));
}

void on_button_clear_calculator()
{
    expressioncalculator = NULL;
    const char *entryvalue = "";
    gtk_entry_set_text(GTK_ENTRY(entrycalculator), entryvalue);
}

void on_button_po()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "(");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_pc()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, ")");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_star()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "^");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number9()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "9");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number8()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "8");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number7()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "7");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number6()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "6");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number5()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "5");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number4()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "4");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}
void on_button_number3()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "3");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}
void on_button_number2()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "2");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}
void on_button_number1()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "1");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_number0()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "0");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_dot()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, ".");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_equal()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "=");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_calculatorplus()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "+");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_calculatorminus()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "-");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_calculatorproduct()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "*");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}

void on_button_calculatorslash()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "/");

    gtk_entry_set_text(GTK_ENTRY(entrycalculator), expressioncalculator);
}
void on_button_sqrtcalculator()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "sqrt");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_ecalculator()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "e");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_lncalculator()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "ln");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_coscalculator()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "cos");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}
void on_button_sincalcultor()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "sin");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}




void open_calculator_fct()
{
    GtkWidget *windowcalculator;

    gtk_init(NULL, NULL);
    {
        builder = gtk_builder_new_from_file("../src/calculator/calculator.glade");
        windowcalculator = GTK_WIDGET(gtk_builder_get_object(builder, "windowcalculator"));
        gtk_builder_connect_signals(builder, NULL);

        entrycalculator = GTK_WIDGET(gtk_builder_get_object(builder, "entrycalculator"));
        labelcalculator = GTK_WIDGET(gtk_builder_get_object(builder, "labelcalculator"));
        openintegral = GTK_BUTTON(gtk_builder_get_object(builder, "openintegral"));

        g_signal_connect(openintegral, "clicked", G_CALLBACK(open_integral_fct),NULL);

        gtk_widget_show_all(windowcalculator);
        gtk_main();
    }
}
