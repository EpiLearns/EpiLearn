#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "parser.h"
#include <math.h>

GtkBuilder *builder;
GtkWidget *entrycalculator;
GtkWidget *labelcalculator;
char* expressioncalculator = "";

const char* f(char *expression)
{
    node* head;
    double result;
    
    int syntax = checkSyntax(expression);
    if (syntax)
    {
        head = parseExpression(expression);
        result = evaluate(head);
        printf("%f\n", result);
    }
    const char *s = malloc(sizeof(double));
    sprintf((char*)s,"%.2f",result);
    return s;
}

void on_button_enter_calculator(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    gtk_label_set_text(GTK_LABEL(labelcalculator), f(expressioncalculator));
    

}

void on_button_clear_calculator(GtkWidget *e, gpointer user_data)
{
    expressioncalculator = NULL;
    const char *entryvalue = "";
    gtk_entry_set_text(GTK_ENTRY(entrycalculator), entryvalue);
    g_print("expression when button2 = %s\n", expressioncalculator);
}

void on_button_po(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "(");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_pc(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, ")");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_star(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "^");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number9(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "9");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}
void on_button_number8(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "8");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number7(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "7");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number6(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "6");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number5(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "5");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number4(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "4");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}
void on_button_number3(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "3");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}
void on_button_number2(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "2");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}
void on_button_number1(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "1");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_number0(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "0");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_dot(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, ".");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_equal(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "=");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_calculatorplus(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "+");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_calculatorminus(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "-");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_calculatorproduct(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "*");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

void on_button_calculatorslash(GtkWidget *e, gpointer user_data)
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entrycalculator));
    expressioncalculator = strdup(entryvalue);
    expressioncalculator = strcat(expressioncalculator, "/");
   
    gtk_entry_set_text(GTK_ENTRY(entrycalculator),expressioncalculator);
}

int main(int argc, char **argv)
{
    GtkWidget *windowcalculator;
    GtkWidget *buttonentercalculator;
    GtkWidget *buttonclearcalculator;
    GtkWidget *buttonpo;
    GtkWidget *buttonpc;
    GtkWidget *buttonstar;
    GtkWidget *buttonnumber9;
    GtkWidget *buttonnumber8;
    GtkWidget *buttonnumber7;
    GtkWidget *buttonnumber6;
    GtkWidget *buttonnumber5;
    GtkWidget *buttonnumber4;
    GtkWidget *buttonnumber3;
    GtkWidget *buttonnumber2;
    GtkWidget *buttonnumber1;
    GtkWidget *buttonnumber0;
    GtkWidget *buttondot;
    GtkWidget *buttonequal;
    GtkWidget *buttoncalculatorplus;
    GtkWidget *buttoncalculatorminus;
    GtkWidget *buttoncalculatorproduct;
    GtkWidget *buttoncalculatorslash;

    gtk_init (&argc, &argv);
    {
        builder = gtk_builder_new_from_file("calculator.glade");
        windowcalculator = GTK_WIDGET(gtk_builder_get_object(builder,"windowcalculator"));
        gtk_builder_connect_signals(builder, NULL);

        entrycalculator = GTK_WIDGET(gtk_builder_get_object(builder,"entrycalculator"));
        labelcalculator = GTK_WIDGET(gtk_builder_get_object(builder,"labelcalculator"));
        buttonentercalculator = GTK_WIDGET(gtk_builder_get_object(builder,"buttonentercalculator"));
        buttonclearcalculator = GTK_WIDGET(gtk_builder_get_object(builder,"buttonclearcalculator"));
        buttonpo = GTK_WIDGET(gtk_builder_get_object(builder,"button("));
        buttonpc = GTK_WIDGET(gtk_builder_get_object(builder,"button)"));
        buttonstar = GTK_WIDGET(gtk_builder_get_object(builder,"button^"));
        buttonnumber9 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber9"));
        buttonnumber8 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber8"));
        buttonnumber7 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber7"));
        buttonnumber6 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber6"));
        buttonnumber5 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber5"));
        buttonnumber4 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber4"));
        buttonnumber3 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber3"));
        buttonnumber2 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber2"));
        buttonnumber1 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber1"));
        buttonnumber0 = GTK_WIDGET(gtk_builder_get_object(builder,"buttonnumber0"));
        buttondot = GTK_WIDGET(gtk_builder_get_object(builder,"button."));
        buttonequal = GTK_WIDGET(gtk_builder_get_object(builder,"button="));
        buttoncalculatorplus = GTK_WIDGET(gtk_builder_get_object(builder,"button+"));
        buttoncalculatorminus = GTK_WIDGET(gtk_builder_get_object(builder,"button-"));
        buttoncalculatorproduct = GTK_WIDGET(gtk_builder_get_object(builder,"button*;"));
        buttoncalculatorslash = GTK_WIDGET(gtk_builder_get_object(builder,"button/"));

        
    

        gtk_widget_show_all(windowcalculator);
        gtk_main();
        return 0;

        
    }



}
