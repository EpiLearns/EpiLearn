#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "parser.h"
#include <math.h>

GtkBuilder *builder;
GtkWidget *entryintegral;
GtkWidget *labelintegral;
GtkWidget *entrysupintegral;
GtkWidget *entryinfintegral;
char* expressionintegral = "";
double a = 2;
double b = 1;

long double integral_f(long double x)
{
    node* head;
    double result;

    char* res = NULL;
    char *s = malloc(sizeof(long double));
    sprintf(s,"%Lf",x);
    res = replaceWord(expressionintegral, "x", s);
    int syntax = calculator_checkSyntax(res);
    if (syntax)
    {
        head = calculator_parseExpression(res);
        result = calculator_evaluate(head);
    }
    return result;
}

const char *simpsonRule(long double a, long double b)
{
    int n;
    n = 100;
    long double h = (b-a)/n; 
    long double x0 = integral_f(a);
    long double xn = integral_f(a+n*h);
    long double res = x0 + xn;
    for (int i = 1; i < n; i++)
    {
        if (i%2!= 0)
        {
            res = res+4*integral_f(a+i*h);
        }
        else 
        {
            res = res + 2*integral_f(a+i*h);
        }
    }
    res = (h/3)*res;
    printf("\nL'intégrale de %Lf %Lf avec la méthode simpson \nest environ égal à : %Lf \n", a, b, res); // Résultat
    const char *s = malloc(sizeof(long double));
    sprintf((char*)s, "%Lf", res);
    return s;
}

void on_button_enter_integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    b = strtod(gtk_entry_get_text(GTK_ENTRY(entrysupintegral)),NULL);
    a = strtod(gtk_entry_get_text(GTK_ENTRY(entryinfintegral)),NULL);
    expressionintegral = strdup(entryvalue);
    {
        gtk_label_set_text(GTK_LABEL(labelintegral), simpsonRule(a,b));
    }
    

}

void on_button_clear_integral()
{
    expressionintegral = NULL;
    const char *entryvalue = "";
    gtk_entry_set_text(GTK_ENTRY(entryintegral), entryvalue);
    gtk_entry_set_text(GTK_ENTRY(entrysupintegral), entryvalue);
    gtk_entry_set_text(GTK_ENTRY(entryinfintegral), entryvalue);
    gtk_label_set_text(GTK_LABEL(labelintegral), entryvalue);
    
    
}

void on_button_pointegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "(");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_pcintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, ")");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_starintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "^");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number9integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "9");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_number8integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "8");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number7integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "7");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number6integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "6");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number5integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "5");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number4integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "4");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_number3integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "3");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_number2integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "2");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_number1integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "1");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_number0integral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "0");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_dotintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, ".");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_equalintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "=");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_plusintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "+");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_minusintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "-");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_productintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "*");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_slashintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "/");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_sqrtintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "sqrt");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_eintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "e");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_lnintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "ln");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

void on_button_cosintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "cos");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}
void on_button_sinintegral()
{
    const char *entryvalue;
    entryvalue = gtk_entry_get_text(GTK_ENTRY(entryintegral));
    expressionintegral = strdup(entryvalue);
    expressionintegral = strcat(expressionintegral, "sin");
   
    gtk_entry_set_text(GTK_ENTRY(entryintegral),expressionintegral);
}

int main(int argc, char **argv)
{
    GtkWidget *windowintegral;
    gtk_init (&argc, &argv);
    {
        builder = gtk_builder_new_from_file("../src/calculator/integral.glade");
        windowintegral = GTK_WIDGET(gtk_builder_get_object(builder,"windowintegral"));
        gtk_builder_connect_signals(builder, NULL);

        entryintegral = GTK_WIDGET(gtk_builder_get_object(builder,"entryintegral"));
        labelintegral = GTK_WIDGET(gtk_builder_get_object(builder,"labelintegral"));
        entrysupintegral = GTK_WIDGET(gtk_builder_get_object(builder, "entrysupintegral"));
        entryinfintegral = GTK_WIDGET(gtk_builder_get_object(builder, "entryinfintegral"));
       
    

        gtk_widget_show_all(windowintegral);
        gtk_main();
        return 0;

        
    }



}



