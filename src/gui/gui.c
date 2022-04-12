#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>
#include "gui.h"
#include <stdlib.h>
#include <string.h>

#include "../property/mathamatics/complex_number/complex_number.h"
#include "../property/computer_architecture/integer_representation/integer_representation.h"
#include "../calculator/calculator.h"

GtkBuilder* builder;
GtkMenuItem* Calculatrice;
//GtkMenuItem* Graphe;

GtkWindow* mainWindow;
GtkWindow* loginWindow;
GtkWindow* mathsWindow;
GtkWindow* algoWindow;
GtkWindow* phyWindow;
GtkWindow* elecWindow;
GtkWindow* archiWindow;
GtkWindow* profileWindow;
GtkWindow* aboutUsWindow;

GtkButton* login;

GtkButton* Mathematics;
GtkButton* Algorithm;
GtkButton* Physic;
GtkButton* Electronic;
GtkButton* Computer_architecture;
GtkButton* mcq;
GtkMenuItem* aboutUs;

GtkButton* account;

GtkButton* back_profil;
GtkButton* back_maths;
GtkButton* back_algo;
GtkButton* back_ca;
GtkButton* back_elec;
GtkButton* back_phy;
GtkButton* back_mcq;

GtkButton* close_about_us;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GtkWindow* cours_algo_1_1;
GtkWindow* cours_algo_2_1;
GtkWindow* cours_algo_2_2;
GtkWindow* cours_algo_3_1;
GtkWindow* cours_algo_3_2;

GtkButton* algo_1_1;
GtkButton* quit_algo_1_1;

GtkButton* algo_2_1;
GtkButton* quit_algo_2_1;

GtkButton* algo_2_2;
GtkButton* quit_algo_2_2;

GtkButton* algo_3_1;
GtkButton* quit_algo_3_1;


GtkWindow* cours_archi_1_1;
GtkWindow* cours_archi_1_2;
GtkWindow* cours_archi_1_3;
GtkWindow* cours_archi_1_4;

GtkButton* archi_1_1;
GtkButton* quit_archi_1_1;

GtkButton* archi_1_2;
GtkButton* quit_archi_1_2;

GtkButton* archi_1_3;
GtkButton* quit_archi_1_3;

GtkButton* archi_1_4;
GtkButton* quit_archi_1_4;


GtkWindow* cours_elec_1_1;

GtkButton* elec_1_1;
GtkButton* quit_elec_1_1;


GtkWindow* cours_math_1_1;
GtkWindow* cours_math_1_2;
GtkWindow* cours_math_2_1;
GtkWindow* cours_math_2_2;
GtkWindow* cours_math_3_1;
GtkWindow* cours_math_3_2;
GtkWindow* cours_math_3_3;
GtkWindow* cours_math_4_1;
GtkWindow* cours_math_4_2;

GtkButton* math_1_1;
GtkButton* quit_math_1_1;

GtkButton* math_1_2;
GtkButton* quit_math_1_2;

GtkButton* math_2_1;
GtkButton* quit_math_2_1;

GtkButton* math_2_2;
GtkButton* quit_math_2_2;

GtkButton* math_3_1;
GtkButton* quit_math_3_1;

GtkButton* math_3_2;
GtkButton* quit_math_3_2;

GtkButton* math_3_3;
GtkButton* quit_math_3_3;

GtkButton* math_4_1;
GtkButton* quit_math_4_1;

GtkButton* math_4_2;
GtkButton* quit_math_4_2;


GtkWindow* cours_phy_1_1;
GtkWindow* cours_phy_1_2;

GtkButton* phy_1_1;
GtkButton* quit_phy_1_1;

GtkButton* phy_1_2;
GtkButton* quit_phy_1_2;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//training button

GtkButton* mt1;
GtkButton* mt2;
GtkButton* mt3;
GtkButton* mt4;

GtkButton* at1;
GtkButton* at2;
GtkButton* at3;

GtkButton* ct1;
GtkButton* ct2;
GtkButton* ct3;

GtkButton* et1;

GtkButton* pt1;

GtkWindow* qcmarchi;

GtkButton* quit_qcm_a;

GtkWindow* qcmmt1;
GtkButton* quit_qcm_mt1;

GtkWindow* qcmarchi2;

GtkButton* quit_qcm_a1;


GtkWindow* qcmat1;
GtkButton* quit_at1;

void enter_main()
{
    gtk_widget_hide(GTK_WIDGET(loginWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void enter_profile()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(profileWindow));
}

void enter_maths()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_algo()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_phy()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(phyWindow));
}

void enter_elec()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(elecWindow));
}

void enter_archi()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_at1()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(qcmat1));
}

void enter_aboutUs()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(aboutUsWindow));
}


void close_profile()
{
    gtk_widget_hide(GTK_WIDGET(profileWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_maths()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_algo()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_phy()
{
    gtk_widget_hide(GTK_WIDGET(phyWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_elec()
{
    gtk_widget_hide(GTK_WIDGET(elecWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_archi()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_at1()
{
    gtk_widget_hide(GTK_WIDGET(qcmat1));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void close_aboutUs()
{
    gtk_widget_hide(GTK_WIDGET(aboutUsWindow));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void enter_algo_1_1()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(cours_algo_1_1));
}

void close_algo_1_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_algo_1_1));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_algo_2_1()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(cours_algo_2_1));
}

void close_algo_2_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_algo_2_1));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_algo_2_2()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(cours_algo_2_2));
}

void close_algo_2_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_algo_2_2));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_algo_3_1()
{
    gtk_widget_hide(GTK_WIDGET(algoWindow));
    gtk_widget_show(GTK_WIDGET(cours_algo_3_1));
}

void close_algo_3_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_algo_3_1));
    gtk_widget_show(GTK_WIDGET(algoWindow));
}

void enter_archi_1_1()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(cours_archi_1_1));
}

void close_archi_1_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_archi_1_1));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_archi_1_2()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(cours_archi_1_2));
}

void close_archi_1_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_archi_1_2));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_archi_1_3()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(cours_archi_1_3));
}

void close_archi_1_3()
{
    gtk_widget_hide(GTK_WIDGET(cours_archi_1_3));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_archi_1_4()
{
    gtk_widget_hide(GTK_WIDGET(archiWindow));
    gtk_widget_show(GTK_WIDGET(cours_archi_1_4));
}

void close_archi_1_4()
{
    gtk_widget_hide(GTK_WIDGET(cours_archi_1_4));
    gtk_widget_show(GTK_WIDGET(archiWindow));
}

void enter_elec_1_1()
{
    gtk_widget_hide(GTK_WIDGET(elecWindow));
    gtk_widget_show(GTK_WIDGET(cours_elec_1_1));
}

void close_elec_1_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_elec_1_1));
    gtk_widget_show(GTK_WIDGET(elecWindow));
}

void enter_math_1_1()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_1_1));
}

void close_math_1_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_1_1));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_1_2()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_1_2));
}

void close_math_1_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_1_2));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_2_1()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_2_1));
}

void close_math_2_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_2_1));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_2_2()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_2_2));
}

void close_math_2_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_2_2));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}


void enter_math_3_1()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_3_1));
}

void close_math_3_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_3_1));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_3_2()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_3_2));
}

void close_math_3_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_3_2));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_3_3()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_3_3));
}

void close_math_3_3()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_3_3));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}


void enter_math_4_1()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_4_1));
}

void close_math_4_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_4_1));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}

void enter_math_4_2()
{
    gtk_widget_hide(GTK_WIDGET(mathsWindow));
    gtk_widget_show(GTK_WIDGET(cours_math_4_2));
}

void close_math_4_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_math_4_2));
    gtk_widget_show(GTK_WIDGET(mathsWindow));
}


void enter_phy_1_1()
{
    gtk_widget_hide(GTK_WIDGET(phyWindow));
    gtk_widget_show(GTK_WIDGET(cours_phy_1_1));
}

void close_phy_1_1()
{
    gtk_widget_hide(GTK_WIDGET(cours_phy_1_1));
    gtk_widget_show(GTK_WIDGET(phyWindow));
}

void enter_phy_1_2()
{
    gtk_widget_hide(GTK_WIDGET(phyWindow));
    gtk_widget_show(GTK_WIDGET(cours_phy_1_2));
}

void close_phy_1_2()
{
    gtk_widget_hide(GTK_WIDGET(cours_phy_1_2));
    gtk_widget_show(GTK_WIDGET(phyWindow));
}

GtkButton* valide_1;
GtkWidget* statement1;
GtkWidget* reponse1;
GtkWidget* rep_ct1;

void enter_ct1()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(qcmarchi));
}

void close_ct1()
{   
    gtk_widget_hide(GTK_WIDGET(qcmarchi));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void enter_question_ct1(gpointer user)
{
    User* client = user;
    char state[256];
    char rep[8];
    char reponse[256];
   
    sprintf(rep,"%s",gtk_entry_get_text(GTK_ENTRY(reponse1)));
    gtk_entry_set_text(GTK_ENTRY(reponse1),"");
    gtk_label_set_text(GTK_LABEL(rep_ct1),(const gchar*)"");

    if (strlen(rep) != 0)
    { 
        if (strcmp(rep,client->answer_archi) == 0)
        {
            gtk_label_set_text(GTK_LABEL(rep_ct1),(const gchar*) "Bonne réponse !");
        }

        else
        {
            sprintf(reponse,"Mauvaise réponse!\n Correction: %s",client->answer_archi);
            gtk_label_set_text(GTK_LABEL(rep_ct1),(const gchar*)reponse);
        }
    }

    int n = rand()%17;

    sprintf(state,"Combien fait 2^%i ?",n);

    gtk_label_set_text(GTK_LABEL(statement1),(const gchar*) state);
    
    sprintf(client->answer_archi,"%i",1<<n);
}

GtkButton* valide_2;
GtkWidget* statement2;
GtkWidget* reponse2;
GtkWidget* rep_ct2;

void enter_ct2()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(qcmarchi2));
}

void close_ct2()
{
    gtk_widget_hide(GTK_WIDGET(qcmarchi2));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void enter_question_ct2(gpointer user)
{
    User* client = user;
    
    char rep[64];
    char reponse[256];
   
    sprintf(rep,"%s",gtk_entry_get_text(GTK_ENTRY(reponse2)));
    gtk_entry_set_text(GTK_ENTRY(reponse2),"");
    gtk_label_set_text(GTK_LABEL(rep_ct2),(const gchar*)"");

    if (strlen(rep) != 0)
    { 
        if (strcmp(rep,client->answer_archi1) == 0)
        {
            gtk_label_set_text(GTK_LABEL(rep_ct2),(const gchar*) "Bonne réponse !");
        }

        else
        {
            sprintf(reponse,"Mauvaise réponse!\n Correction: %s",client->answer_archi1);
            gtk_label_set_text(GTK_LABEL(rep_ct2),(const gchar*)reponse);
        }
    }

    char state[256];

    int depart = rand()%9 + 2;
    int arrivee = rand()%9 + 2;

    int nbre = rand()%100;

    unsigned long nbre_base_depart = convertirEnbase(depart,(unsigned long)nbre,10);
    unsigned long nbre_base_arrivee = convertirEnbase(arrivee,(unsigned long) nbre,10);

    sprintf(client->answer_archi1,"%lu",nbre_base_arrivee);

    sprintf(state,"Donner la représentation en base %i de %lu (en base %i)?",arrivee,nbre_base_depart,depart);
    gtk_label_set_text(GTK_LABEL(statement2),(const gchar*) state);
    
}

GtkButton* valide_mt1;
GtkWidget* qe_mt1;
GtkWidget* im_mt1;
GtkWidget* re_mt1;

GtkWidget* rep_mt1;

void enter_mt1()
{
    gtk_widget_hide(GTK_WIDGET(mainWindow));
    gtk_widget_show(GTK_WIDGET(qcmmt1));
}

void close_mt1()
{   
    gtk_widget_hide(GTK_WIDGET(qcmmt1));
    gtk_widget_show(GTK_WIDGET(mainWindow));
}

void enter_question_mt1(gpointer user)
{
    User* client = user;

    char state[256];
    char rep_im[8];
    char rep_re[8];
    char reponse[256];

    sprintf(rep_im,"%s",gtk_entry_get_text(GTK_ENTRY(im_mt1)));
    sprintf(rep_re,"%s",gtk_entry_get_text(GTK_ENTRY(re_mt1)));

    gtk_entry_set_text(GTK_ENTRY(im_mt1),"");
    gtk_entry_set_text(GTK_ENTRY(re_mt1),"");

    gtk_label_set_text(GTK_LABEL(rep_mt1),(const gchar*)"");
    
    if (strlen(rep_im) != 0 || strlen(rep_re) != 0)
    {   
        if (strcmp(rep_im,client->answer_im) == 0 && strcmp(rep_re,client->answer_re) == 0)
        {
            gtk_label_set_text(GTK_LABEL(rep_mt1),"Bonne réponse !");
        }

        else
        {
            sprintf(reponse,"Mauvaise Réponse!\n Correction: %s i + %s", client->answer_im,client->answer_re);
            gtk_label_set_text(GTK_LABEL(rep_mt1), reponse);
        }
    }

    int n = rand()%3;

    //generate complex number
    client->a = random_comp(); 
    client->b = random_comp();

    Complex* rep; 

    if (n == 0)
    {
        sprintf(state,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 + Z2 ?",(int) client->a->Im,(int) client->a->Re,(int) client->b->Im,(int)client->b->Re);
        rep = comp_plus(client->a,client->b);
    }

    if (n == 1)
    {
        sprintf(state,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 - Z2 ?",(int) client->a->Im,(int) client->a->Re,(int) client->b->Im,(int)client->b->Re);
        rep = comp_minus(client->a,client->b);
    }

    else
    {
        sprintf(state,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 * Z2 ?",(int) client->a->Im,(int) client->a->Re,(int) client->b->Im,(int)client->b->Re);
        rep = comp_mult(client->a,client->b);
    }

    gtk_label_set_text(GTK_LABEL(qe_mt1),(const gchar*) state);
    
    sprintf(client->answer_im,"%i",(int)rep->Im);
    sprintf(client->answer_re,"%i",(int)rep->Re);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GtkBuilder *init_gui()
{
    // Initializes GTK.
    gtk_init(NULL, NULL);

    // Constructs a GtkBuilder instance.
    builder = gtk_builder_new ();

    GError* error = NULL;
    if (gtk_builder_add_from_file(builder, "../res/EpiLearn.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return NULL;
    }

    User* client = calloc(1,sizeof(User));

    if (!client)

    {
        return NULL;
    }

    // Gets the widgets.
    mainWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.main"));
    loginWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.login"));
    
    mathsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.mathematics"));
    algoWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algorithm"));
    phyWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.physic"));
    elecWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.electronic"));
    archiWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.computer_architecture"));
    profileWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.profil"));
    aboutUsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.about_us"));

    //courses

    cours_algo_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap1.lesson1"));
    algo_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_1_1"));
    quit_algo_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_1_1"));

    cours_algo_2_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap2.lesson1"));
    algo_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_2_1"));
    quit_algo_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_2_1"));

    cours_algo_2_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap2.lesson2"));
    algo_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_2_2"));
    quit_algo_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_2_2"));

    cours_algo_3_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap3.lesson1"));
    algo_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_3_1"));
    quit_algo_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_3_1"));


    cours_archi_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson1"));
    cours_archi_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson2"));
    cours_archi_1_3 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson3"));
    cours_archi_1_4 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson4"));

    archi_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_1"));
    archi_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_2"));
    archi_1_3 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_3"));
    archi_1_4 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_4"));

    quit_archi_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_1"));
    quit_archi_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_2"));
    quit_archi_1_3 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_3"));
    quit_archi_1_4 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_4"));

    
    cours_elec_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.elec.chap1.lesson1"));

    elec_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"elec_1_1"));;

    quit_elec_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_elec_1_1"));


    cours_math_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap1.lesson1"));
    cours_math_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap1.lesson2"));
    cours_math_2_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap2.lesson1"));
    cours_math_2_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap2.lesson2"));
    cours_math_3_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson1"));
    cours_math_3_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson2"));
    cours_math_3_3 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson3"));
    cours_math_4_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap4.lesson1"));
    cours_math_4_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap4.lesson2"));

    math_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_1_1"));
    math_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_1_2"));
    math_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_2_1"));
    math_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_2_2"));
    math_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_1"));
    math_3_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_2"));
    math_3_3 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_3"));
    math_4_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_4_1"));
    math_4_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_4_2"));
   
    quit_math_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_1_1"));
    quit_math_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_1_2"));
    quit_math_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_2_1"));    
    quit_math_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_2_2"));
    quit_math_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_1"));
    quit_math_3_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_2"));
    quit_math_3_3 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_3"));    
    quit_math_4_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_4_1"));
    quit_math_4_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_4_2"));

    cours_phy_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.phy.chap1.lesson1"));
    cours_phy_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.phy.chap1.lesson2"));

    phy_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"phy_1_1"));
    phy_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"phy_1_2"));

    quit_phy_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_phy_1_1"));
    quit_phy_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_phy_1_2"));

    //traning button

    mt1 = GTK_BUTTON(gtk_builder_get_object(builder,"mt1"));
    mt2 = GTK_BUTTON(gtk_builder_get_object(builder,"mt2"));
    mt3 = GTK_BUTTON(gtk_builder_get_object(builder,"mt3"));
    mt4 = GTK_BUTTON(gtk_builder_get_object(builder,"mt'"));

    at1 = GTK_BUTTON(gtk_builder_get_object(builder,"at1"));
    at2 = GTK_BUTTON(gtk_builder_get_object(builder,"at2"));
    at3 = GTK_BUTTON(gtk_builder_get_object(builder,"at3"));

    ct1 = GTK_BUTTON(gtk_builder_get_object(builder,"ct1"));
    ct2 = GTK_BUTTON(gtk_builder_get_object(builder,"ct2"));
    ct3 = GTK_BUTTON(gtk_builder_get_object(builder,"ct3"));

    et1 = GTK_BUTTON(gtk_builder_get_object(builder,"et1"));

    pt1 = GTK_BUTTON(gtk_builder_get_object(builder,"pt1"));

    qcmarchi = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.archi"));
    quit_qcm_a = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_a"));

    qcmmt1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.maths.mt1"));
    quit_qcm_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_mt1"));
    valide_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_mt1"));

    qcmarchi2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.archi_1"));
    quit_qcm_a1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_a1"));

    qcmat1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm_at1"));
    quit_at1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_at1"));

    Calculatrice = GTK_MENU_ITEM(gtk_builder_get_object(builder, "Calculatrice"));
    //Graphe = GTK_MENU_ITEM(gtk_builder_get_object(builder, "Graphe"));

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    valide_1 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_1"));
    statement1 = GTK_WIDGET(gtk_builder_get_object(builder, "statement1"));
    reponse1 = GTK_WIDGET(gtk_builder_get_object(builder, "reponse1"));
    rep_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "rep_ct1"));

    qe_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "qe_mt1"));
    im_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "im_mt1"));
    re_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "re_mt1"));
    rep_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "rep_mt1"));

    valide_2 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_2"));
    statement2 = GTK_WIDGET(gtk_builder_get_object(builder, "statement2"));
    reponse2 = GTK_WIDGET(gtk_builder_get_object(builder, "reponse2"));
    rep_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "rep_ct2"));


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    login = GTK_BUTTON(gtk_builder_get_object(builder,"login"));
    Mathematics = GTK_BUTTON(gtk_builder_get_object(builder,"Mathematics"));
    Algorithm = GTK_BUTTON(gtk_builder_get_object(builder,"Algorithm"));
    Physic = GTK_BUTTON(gtk_builder_get_object(builder,"Physic"));
    Electronic = GTK_BUTTON(gtk_builder_get_object(builder,"Electronic"));
    Computer_architecture = GTK_BUTTON(gtk_builder_get_object(builder,"Computer architecture"));
    mcq = GTK_BUTTON(gtk_builder_get_object(builder,"mcq enter"));
    aboutUs = GTK_MENU_ITEM(gtk_builder_get_object(builder,"about us b"));

    account = GTK_BUTTON(gtk_builder_get_object(builder,"account"));

    back_profil = GTK_BUTTON(gtk_builder_get_object(builder,"Back profil"));
    back_maths = GTK_BUTTON(gtk_builder_get_object(builder,"back maths"));
    back_algo = GTK_BUTTON(gtk_builder_get_object(builder,"back algo"));
    back_ca = GTK_BUTTON(gtk_builder_get_object(builder,"back ca"));
    back_elec = GTK_BUTTON(gtk_builder_get_object(builder,"back elec"));
    back_phy = GTK_BUTTON(gtk_builder_get_object(builder,"back phy"));
    back_mcq = GTK_BUTTON(gtk_builder_get_object(builder,"quit mcq"));

    close_about_us = GTK_BUTTON(gtk_builder_get_object(builder,"close about us"));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

    g_signal_connect(ct1,"clicked",G_CALLBACK(enter_ct1),NULL);
    g_signal_connect(quit_qcm_a,"clicked",G_CALLBACK(close_ct1),NULL);

    g_signal_connect(valide_1,"clicked",G_CALLBACK(enter_question_ct1),client);

    g_signal_connect(mt1,"clicked",G_CALLBACK(enter_mt1),NULL);
    g_signal_connect(quit_qcm_mt1,"clicked",G_CALLBACK(close_mt1),NULL);

    g_signal_connect(valide_mt1,"clicked",G_CALLBACK(enter_question_mt1),client);

    g_signal_connect(ct2,"clicked",G_CALLBACK(enter_ct2),NULL);
    g_signal_connect(quit_qcm_a1,"clicked",G_CALLBACK(close_ct2),NULL);

    g_signal_connect(valide_2,"clicked",G_CALLBACK(enter_question_ct2),client);
    
    g_signal_connect(Calculatrice,"activate",G_CALLBACK(open_calculator),NULL);
    //g_signal_connect(Graphe,"activate",G_CALLBACK(open_graphe),NULL);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    // Connects event handlers.
    g_signal_connect(mainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show(GTK_WIDGET(loginWindow));

    g_signal_connect(login,"clicked",G_CALLBACK(enter_main),NULL);
    g_signal_connect(Mathematics,"clicked",G_CALLBACK(enter_maths),NULL);
    g_signal_connect(Algorithm,"clicked",G_CALLBACK(enter_algo),NULL);
    g_signal_connect(Physic,"clicked",G_CALLBACK(enter_phy),NULL);
    g_signal_connect(Electronic,"clicked",G_CALLBACK(enter_elec),NULL);
    g_signal_connect(Computer_architecture,"clicked",G_CALLBACK(enter_archi),NULL);
    g_signal_connect(account,"clicked",G_CALLBACK(enter_profile),NULL);
    g_signal_connect(aboutUs,"activate",G_CALLBACK(enter_aboutUs),NULL);

    g_signal_connect(back_maths,"clicked",G_CALLBACK(close_maths),NULL);
    g_signal_connect(back_algo,"clicked",G_CALLBACK(close_algo),NULL);
    g_signal_connect(back_phy,"clicked",G_CALLBACK(close_phy),NULL);
    g_signal_connect(back_elec,"clicked",G_CALLBACK(close_elec),NULL);
    g_signal_connect(back_ca,"clicked",G_CALLBACK(close_archi),NULL);
    g_signal_connect(back_profil,"clicked",G_CALLBACK(close_profile),NULL);
    g_signal_connect(close_about_us,"clicked",G_CALLBACK(close_aboutUs),NULL);

    //courses
    g_signal_connect(algo_1_1,"clicked",G_CALLBACK(enter_algo_1_1),NULL);
    g_signal_connect(quit_algo_1_1,"clicked",G_CALLBACK(close_algo_1_1),NULL);

    g_signal_connect(algo_2_1,"clicked",G_CALLBACK(enter_algo_2_1),NULL);
    g_signal_connect(quit_algo_2_1,"clicked",G_CALLBACK(close_algo_2_1),NULL);

    g_signal_connect(algo_2_2,"clicked",G_CALLBACK(enter_algo_2_2),NULL);
    g_signal_connect(quit_algo_2_2,"clicked",G_CALLBACK(close_algo_2_2),NULL);

    g_signal_connect(algo_3_1,"clicked",G_CALLBACK(enter_algo_3_1),NULL);
    g_signal_connect(quit_algo_3_1,"clicked",G_CALLBACK(close_algo_3_1),NULL);


    g_signal_connect(archi_1_1,"clicked",G_CALLBACK(enter_archi_1_1),NULL);
    g_signal_connect(quit_archi_1_1,"clicked",G_CALLBACK(close_archi_1_1),NULL);

    g_signal_connect(archi_1_2,"clicked",G_CALLBACK(enter_archi_1_2),NULL);
    g_signal_connect(quit_archi_1_2,"clicked",G_CALLBACK(close_archi_1_2),NULL);

    g_signal_connect(archi_1_3,"clicked",G_CALLBACK(enter_archi_1_3),NULL);
    g_signal_connect(quit_archi_1_3,"clicked",G_CALLBACK(close_archi_1_3),NULL);

    g_signal_connect(archi_1_4,"clicked",G_CALLBACK(enter_archi_1_4),NULL);
    g_signal_connect(quit_archi_1_4,"clicked",G_CALLBACK(close_archi_1_4),NULL);


    g_signal_connect(elec_1_1,"clicked",G_CALLBACK(enter_elec_1_1),NULL);
    g_signal_connect(quit_elec_1_1,"clicked",G_CALLBACK(close_elec_1_1),NULL);


    g_signal_connect(math_1_1,"clicked",G_CALLBACK(enter_math_1_1),NULL);
    g_signal_connect(quit_math_1_1,"clicked",G_CALLBACK(close_math_1_1),NULL);

    g_signal_connect(math_1_2,"clicked",G_CALLBACK(enter_math_1_2),NULL);
    g_signal_connect(quit_math_1_2,"clicked",G_CALLBACK(close_math_1_2),NULL);

    g_signal_connect(math_2_1,"clicked",G_CALLBACK(enter_math_2_1),NULL);
    g_signal_connect(quit_math_2_1,"clicked",G_CALLBACK(close_math_2_1),NULL);

    g_signal_connect(math_2_2,"clicked",G_CALLBACK(enter_math_2_2),NULL);
    g_signal_connect(quit_math_2_2,"clicked",G_CALLBACK(close_math_2_2),NULL);

    g_signal_connect(math_3_1,"clicked",G_CALLBACK(enter_math_3_1),NULL);
    g_signal_connect(quit_math_3_1,"clicked",G_CALLBACK(close_math_3_1),NULL);

    g_signal_connect(math_3_2,"clicked",G_CALLBACK(enter_math_3_2),NULL);
    g_signal_connect(quit_math_3_2,"clicked",G_CALLBACK(close_math_3_2),NULL);

    g_signal_connect(math_3_3,"clicked",G_CALLBACK(enter_math_3_3),NULL);
    g_signal_connect(quit_math_3_3,"clicked",G_CALLBACK(close_math_3_3),NULL);

    g_signal_connect(math_4_1,"clicked",G_CALLBACK(enter_math_4_1),NULL);
    g_signal_connect(quit_math_4_1,"clicked",G_CALLBACK(close_math_4_1),NULL);

    g_signal_connect(math_4_2,"clicked",G_CALLBACK(enter_math_4_2),NULL);
    g_signal_connect(quit_math_4_2,"clicked",G_CALLBACK(close_math_4_2),NULL);


    g_signal_connect(phy_1_1,"clicked",G_CALLBACK(enter_phy_1_1),NULL);
    g_signal_connect(quit_phy_1_1,"clicked",G_CALLBACK(close_phy_1_1),NULL);

    g_signal_connect(phy_1_2,"clicked",G_CALLBACK(enter_phy_1_2),NULL);
    g_signal_connect(quit_phy_1_2,"clicked",G_CALLBACK(close_phy_1_2),NULL);    

    g_signal_connect(at1,"clicked",G_CALLBACK(enter_at1),NULL);
    g_signal_connect(quit_at1,"clicked",G_CALLBACK(close_at1),NULL);
    g_signal_connect(quit_phy_1_2,"clicked",G_CALLBACK(close_phy_1_2),NULL);   

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Run the main window.
    gtk_main();
    
    return builder;
}
