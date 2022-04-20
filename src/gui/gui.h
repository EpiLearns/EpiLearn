#ifndef GUI_H
#define GUI_H

#include <stdio.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include <stdlib.h>
#include <string.h>

#include "../mcqGenerator/mcqGenerator.h"

#include "../property/mathematics/complex_number/complex_number.h"
#include "../property/computer_architecture/integer_representation/integer_representation.h"

#include "../mcqGenerator/mathematics/mathematics.h"
#include "../mcqGenerator/computer_architecture/computer_architecture.h"

#include "../calculator/calculator.h"
#include "../graph/graph.h"

// Builder important Window

GtkBuilder* builder;
GtkWindow* current_window; 
GtkMenuItem* open_calculator;
GtkMenuItem* open_graph;

// Main Window

GtkWindow* mainWindow;
GtkWindow* loginWindow;
GtkWindow* profileWindow;
GtkWindow* aboutUsWindow;

// Courses Main Window

GtkWindow* mathsWindow;
GtkWindow* algoWindow;
GtkWindow* phyWindow;
GtkWindow* elecWindow;
GtkWindow* archiWindow;

// Courses Window

GtkWindow* cours_math_1_1;
GtkWindow* cours_math_1_2;
GtkWindow* cours_math_2_1;
GtkWindow* cours_math_2_2;
GtkWindow* cours_math_3_1;
GtkWindow* cours_math_3_2;
GtkWindow* cours_math_3_3;
GtkWindow* cours_math_4_1;
GtkWindow* cours_math_4_2;

GtkWindow* cours_algo_1_1;
GtkWindow* cours_algo_2_1;
GtkWindow* cours_algo_2_2;
GtkWindow* cours_algo_3_1;

GtkWindow* cours_archi_1_1;
GtkWindow* cours_archi_1_2;
GtkWindow* cours_archi_1_3;
GtkWindow* cours_archi_1_4;

GtkWindow* cours_elec_1_1;

GtkWindow* cours_phy_1_1;
GtkWindow* cours_phy_1_2;

// Mcq Window

GtkWindow* qcm_mt1;

GtkWindow* qcm_at1;

GtkWindow* qcm_archi1;
GtkWindow* qcm_archi2;

// Open/Close Main Window Button

GtkButton* open_main;
GtkMenuItem* open_about_us;
GtkButton* open_profil;

GtkButton* close_about_us;
GtkButton* close_profil;

// Open/Close Courses Window Button

GtkButton* open_mathematics;
GtkButton* open_algorithm;
GtkButton* open_physic;
GtkButton* open_electronic;
GtkButton* open_computer_architecture;

GtkButton* close_mathematics;
GtkButton* close_algorithm;
GtkButton* close_physic;
GtkButton* close_electronic;
GtkButton* close_computer_architecture;

// Open/Close Courses

GtkButton* math_1_1;
GtkButton* math_1_2;
GtkButton* math_2_1;
GtkButton* math_2_2;
GtkButton* math_3_1;
GtkButton* math_3_2;
GtkButton* math_3_3;
GtkButton* math_4_1;
GtkButton* math_4_2;

GtkButton* algo_1_1;
GtkButton* algo_2_1;
GtkButton* algo_2_2;
GtkButton* algo_3_1;

GtkButton* archi_1_1;
GtkButton* archi_1_2;
GtkButton* archi_1_3;
GtkButton* archi_1_4;

GtkButton* elec_1_1;

GtkButton* phy_1_1;
GtkButton* phy_1_2;


GtkButton* quit_math_1_1;
GtkButton* quit_math_1_2;
GtkButton* quit_math_2_1;
GtkButton* quit_math_2_2;
GtkButton* quit_math_3_1;
GtkButton* quit_math_3_2;
GtkButton* quit_math_3_3;
GtkButton* quit_math_4_1;
GtkButton* quit_math_4_2;

GtkButton* quit_algo_1_1;
GtkButton* quit_algo_2_1;
GtkButton* quit_algo_2_2;
GtkButton* quit_algo_3_1;

GtkButton* quit_archi_1_1;
GtkButton* quit_archi_1_2;
GtkButton* quit_archi_1_3;
GtkButton* quit_archi_1_4;

GtkButton* quit_elec_1_1;

GtkButton* quit_phy_1_1;
GtkButton* quit_phy_1_2;

// Open Mcq Button

GtkButton* open_mt1;
GtkButton* open_mt2;

GtkButton* open_at1;
GtkButton* open_at2;
GtkButton* open_at3;

GtkButton* open_ct1;
GtkButton* open_ct2;
GtkButton* open_ct3;

GtkButton* open_et1;

GtkButton* open_pt1;

//Close Mcq Button

GtkButton* quit_qcm_mt1;

GtkButton* quit_qcm_at1;

GtkButton* quit_qcm_ct1;
GtkButton* quit_qcm_ct2;

///////////////////////////////

// For qcm_mt1
GtkButton* valide_mt1;
GtkWidget* question_mt1;
GtkWidget* im_mt1;
GtkWidget* re_mt1;
GtkWidget* answer_mt1;

GtkWidget* question_number_mt1;
GtkWidget* score_mt1;

GtkButton* prev_mt1;
GtkButton* next_mt1;

// For qcm_ct1
GtkButton* valide_ct1;
GtkWidget* question_ct1;
GtkWidget* user_answer_ct1;
GtkWidget* answer_ct1;

GtkWidget* question_number_ct1;
GtkWidget* score_ct1;

GtkButton* prev_ct1;
GtkButton* next_ct1;

// For qcm_ct2
GtkButton* valide_ct2;
GtkWidget* question_ct2;
GtkWidget* user_answer_ct2;
GtkWidget* answer_ct2;

GtkWidget* question_number_ct2;
GtkWidget* score_ct2;

GtkButton* prev_ct2;
GtkButton* next_ct2;

GtkBuilder *init_gui();

#endif
