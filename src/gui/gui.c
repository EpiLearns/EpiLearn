#include "gui.h"

// Function that return allocated User struct

User* init_user()
{
    User* client = calloc(1,sizeof(User));

    if (!client)
    {
        return NULL;
    }

    return client;
}

// Function to change page
void enter_page(GtkButton* button,gpointer parameter)
{
    GtkWindow* new_window = parameter;

    gtk_widget_hide(GTK_WIDGET(current_window));
    gtk_widget_show(GTK_WIDGET(new_window));

    current_window = new_window;
}

void open_page(GtkButton* button,gpointer parameter)
{
    GtkWindow* window = parameter;
    gtk_widget_show(GTK_WIDGET(parameter));
}

// Functions that get all the windows that is used

void get_window()
{
    mainWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.main"));
    loginWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.login"));

    profileWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.profil"));
    aboutUsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.about_us"));

    current_window = loginWindow;
}

void get_courses_window()
{
    mathsWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.mathematics"));
    algoWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algorithm"));
    phyWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.physic"));
    elecWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.electronic"));
    archiWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.computer_architecture"));
}

void get_courses_page()
{
    cours_math_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap1.lesson1"));
    cours_math_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap1.lesson2"));
    cours_math_2_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap2.lesson1"));
    cours_math_2_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap2.lesson2"));
    cours_math_3_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson1"));
    cours_math_3_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson2"));
    cours_math_3_3 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap3.lesson3"));
    cours_math_4_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap4.lesson1"));
    cours_math_4_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.math.chap4.lesson2"));

    cours_algo_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap1.lesson1"));
    cours_algo_2_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap2.lesson1"));
    cours_algo_2_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap2.lesson2"));
    cours_algo_3_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.algo.chap3.lesson1"));

    cours_archi_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson1"));
    cours_archi_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson2"));
    cours_archi_1_3 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson3"));
    cours_archi_1_4 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.archi.chap1.lesson4"));

    cours_elec_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.elec.chap1.lesson1"));

    cours_phy_1_1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.phy.chap1.lesson1"));
    cours_phy_1_2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.phy.chap1.lesson2"));
}

void get_training_window()
{
    qcm_mt1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.maths.mt1"));

    qcm_at1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm_at1"));

    qcm_archi1 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.archi_1"));
    qcm_archi2 = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.qcm.archi_2"));


}

// Functions that get all the buttons that is used

void get_main_enter_button()
{
    open_main = GTK_BUTTON(gtk_builder_get_object(builder,"open_main"));
    open_about_us = GTK_MENU_ITEM(gtk_builder_get_object(builder,"open_about_us"));
    open_profil = GTK_BUTTON(gtk_builder_get_object(builder,"open_profil"));   
}

void get_main_close_button()
{
    close_about_us = GTK_BUTTON(gtk_builder_get_object(builder,"close_about_us"));
    close_profil = GTK_BUTTON(gtk_builder_get_object(builder,"close_profil"));
}

void get_courses_enter_button()
{
    open_mathematics = GTK_BUTTON(gtk_builder_get_object(builder,"open_mathematics"));
    open_algorithm = GTK_BUTTON(gtk_builder_get_object(builder,"open_algorithm"));
    open_physic = GTK_BUTTON(gtk_builder_get_object(builder,"open_physic"));
    open_electronic = GTK_BUTTON(gtk_builder_get_object(builder,"open_electronic"));
    open_computer_architecture = GTK_BUTTON(gtk_builder_get_object(builder,"open_computer_architecture"));


}

void get_courses_close_button()
{
    close_mathematics = GTK_BUTTON(gtk_builder_get_object(builder,"close_mathematics"));
    close_algorithm = GTK_BUTTON(gtk_builder_get_object(builder,"close_algorithm"));
    close_computer_architecture = GTK_BUTTON(gtk_builder_get_object(builder,"close_computer_architecture"));
    close_electronic = GTK_BUTTON(gtk_builder_get_object(builder,"close_electronic"));
    close_physic = GTK_BUTTON(gtk_builder_get_object(builder,"close_physic"));
}

void get_courses_page_enter_button()
{
    math_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_1_1"));
    math_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_1_2"));
    math_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_2_1"));
    math_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_2_2"));
    math_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_1"));
    math_3_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_2"));
    math_3_3 = GTK_BUTTON(gtk_builder_get_object(builder,"math_3_3"));
    math_4_1 = GTK_BUTTON(gtk_builder_get_object(builder,"math_4_1"));
    math_4_2 = GTK_BUTTON(gtk_builder_get_object(builder,"math_4_2"));

    algo_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_1_1"));
    algo_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_2_1"));
    algo_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_2_2"));
    algo_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"algo_3_1"));
    
    archi_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_1"));
    archi_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_2"));
    archi_1_3 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_3"));
    archi_1_4 = GTK_BUTTON(gtk_builder_get_object(builder,"archi_1_4"));

    elec_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"elec_1_1"));;

    phy_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"phy_1_1"));
    phy_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"phy_1_2"));
}

void get_courses_page_close_button()
{
    quit_math_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_1_1"));
    quit_math_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_1_2"));
    quit_math_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_2_1"));    
    quit_math_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_2_2"));
    quit_math_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_1"));
    quit_math_3_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_2"));
    quit_math_3_3 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_3_3"));    
    quit_math_4_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_4_1"));
    quit_math_4_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_math_4_2"));

    quit_algo_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_1_1"));
    quit_algo_2_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_2_1"));
    quit_algo_2_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_2_2"));
    quit_algo_3_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_algo_3_1"));

    quit_archi_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_1"));
    quit_archi_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_2"));
    quit_archi_1_3 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_3"));
    quit_archi_1_4 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_archi_1_4"));

    quit_elec_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_elec_1_1"));

    quit_phy_1_1 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_phy_1_1"));
    quit_phy_1_2 = GTK_BUTTON(gtk_builder_get_object(builder,"quit_phy_1_2"));
}

void get_enter_training_button()
{
    open_mt1 = GTK_BUTTON(gtk_builder_get_object(builder,"open_mt1"));
    open_mt2 = GTK_BUTTON(gtk_builder_get_object(builder,"open_mt2"));

    open_at1 = GTK_BUTTON(gtk_builder_get_object(builder,"open_at1"));
    open_at2 = GTK_BUTTON(gtk_builder_get_object(builder,"open_at2"));
    open_at3 = GTK_BUTTON(gtk_builder_get_object(builder,"open_at3"));

    open_ct1 = GTK_BUTTON(gtk_builder_get_object(builder,"open_ct1"));
    open_ct2 = GTK_BUTTON(gtk_builder_get_object(builder,"open_ct2"));

    open_et1 = GTK_BUTTON(gtk_builder_get_object(builder,"open_et1"));

    open_pt1 = GTK_BUTTON(gtk_builder_get_object(builder,"open_pt1"));
}

void get_close_training_button()
{
    quit_qcm_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_mt1"));

    quit_qcm_at1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_at1"));

    quit_qcm_ct1 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_ct1"));
    quit_qcm_ct2 = GTK_BUTTON(gtk_builder_get_object(builder, "quit_qcm_ct2"));
}

// Function get_tools_object

void get_tools_object()
{
    //List tools
    listWindow = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.tools.list"));

    tool_list_list_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_list_text"));
    tool_list_len_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_len_text"));

    tool_list_append_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_append_entry"));
    tool_list_append_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_append_button"));

    tool_list_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_pop_button"));

    tool_list_insert_entry1 = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_insert_entry1"));
    tool_list_insert_entry2 = GTK_WIDGET(gtk_builder_get_object(builder, "tool_list_insert_entry2"));

    tool_list_insert_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_list_insert_button"));

    // Fifo/Lifo tools
    fifi_lifo_Window = GTK_WINDOW(gtk_builder_get_object(builder, "org.epilearn.tools.fifo_lifo"));

    tool_pile_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_text"));
    tool_file_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_text"));

    tool_pile_isempty_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_isempty_text"));
    tool_file_isempty_text = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_isempty_text"));

    tool_pile_push_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_pile_push_entry"));
    tool_pile_push_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_pile_push_button"));
    tool_pile_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_pile_pop_button"));

    tool_file_enqueue_entry = GTK_WIDGET(gtk_builder_get_object(builder, "tool_file_enqueue_entry"));
    tool_file_enqueue_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_file_enqueue_button"));
    tool_file_pop_button = GTK_BUTTON(gtk_builder_get_object(builder, "tool_file_pop_button"));
}

// Functions G_signal for the UI

void main_signal()
{
    g_signal_connect(open_main,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(open_profil,"clicked",G_CALLBACK(enter_page),profileWindow);
    g_signal_connect(open_about_us,"activate",G_CALLBACK(enter_page),aboutUsWindow);

    g_signal_connect(close_profil,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(close_about_us,"clicked",G_CALLBACK(enter_page),mainWindow);
}

void courses_signal()
{
    g_signal_connect(open_computer_architecture,"clicked",G_CALLBACK(enter_page),archiWindow);
    g_signal_connect(open_mathematics,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(open_algorithm,"clicked",G_CALLBACK(enter_page),algoWindow);
    g_signal_connect(open_physic,"clicked",G_CALLBACK(enter_page),phyWindow);
    g_signal_connect(open_electronic,"clicked",G_CALLBACK(enter_page),elecWindow);

    g_signal_connect(close_mathematics,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(close_algorithm,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(close_physic,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(close_electronic,"clicked",G_CALLBACK(enter_page),mainWindow);
    g_signal_connect(close_computer_architecture,"clicked",G_CALLBACK(enter_page),mainWindow);
}

void courses_page_signal()
{
    g_signal_connect(math_1_1,"clicked",G_CALLBACK(enter_page),cours_math_1_1);
    g_signal_connect(math_1_2,"clicked",G_CALLBACK(enter_page),cours_math_1_2);
    g_signal_connect(math_2_1,"clicked",G_CALLBACK(enter_page),cours_math_2_1);
    g_signal_connect(math_2_2,"clicked",G_CALLBACK(enter_page),cours_math_2_2);
    g_signal_connect(math_3_1,"clicked",G_CALLBACK(enter_page),cours_math_3_1);
    g_signal_connect(math_3_2,"clicked",G_CALLBACK(enter_page),cours_math_3_2);
    g_signal_connect(math_3_3,"clicked",G_CALLBACK(enter_page),cours_math_3_3);
    g_signal_connect(math_4_1,"clicked",G_CALLBACK(enter_page),cours_math_4_1);
    g_signal_connect(math_4_2,"clicked",G_CALLBACK(enter_page),cours_math_4_2);

    g_signal_connect(algo_1_1,"clicked",G_CALLBACK(enter_page),cours_algo_1_1);
    g_signal_connect(algo_2_1,"clicked",G_CALLBACK(enter_page),cours_algo_2_1);
    g_signal_connect(algo_2_2,"clicked",G_CALLBACK(enter_page),cours_algo_2_2);
    g_signal_connect(algo_3_1,"clicked",G_CALLBACK(enter_page),cours_algo_3_1);

    g_signal_connect(archi_1_1,"clicked",G_CALLBACK(enter_page),cours_archi_1_1);
    g_signal_connect(archi_1_2,"clicked",G_CALLBACK(enter_page),cours_archi_1_2);
    g_signal_connect(archi_1_3,"clicked",G_CALLBACK(enter_page),cours_archi_1_3);
    g_signal_connect(archi_1_4,"clicked",G_CALLBACK(enter_page),cours_archi_1_4);

    g_signal_connect(elec_1_1,"clicked",G_CALLBACK(enter_page),cours_elec_1_1);

    g_signal_connect(phy_1_1,"clicked",G_CALLBACK(enter_page),cours_phy_1_1);
    g_signal_connect(phy_1_2,"clicked",G_CALLBACK(enter_page),cours_phy_1_2);



    g_signal_connect(quit_math_1_1,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_1_2,"clicked",G_CALLBACK(enter_page),mathsWindow);    
    g_signal_connect(quit_math_2_1,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_2_2,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_3_1,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_3_2,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_3_3,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_4_1,"clicked",G_CALLBACK(enter_page),mathsWindow);
    g_signal_connect(quit_math_4_2,"clicked",G_CALLBACK(enter_page),mathsWindow);
     
    g_signal_connect(quit_algo_1_1,"clicked",G_CALLBACK(enter_page),algoWindow);
    g_signal_connect(quit_algo_2_1,"clicked",G_CALLBACK(enter_page),algoWindow);
    g_signal_connect(quit_algo_2_2,"clicked",G_CALLBACK(enter_page),algoWindow);
    g_signal_connect(quit_algo_3_1,"clicked",G_CALLBACK(enter_page),algoWindow);
    
    g_signal_connect(quit_archi_1_1,"clicked",G_CALLBACK(enter_page),archiWindow);
    g_signal_connect(quit_archi_1_2,"clicked",G_CALLBACK(enter_page),archiWindow);
    g_signal_connect(quit_archi_1_3,"clicked",G_CALLBACK(enter_page),archiWindow);   
    g_signal_connect(quit_archi_1_4,"clicked",G_CALLBACK(enter_page),archiWindow);
    
    g_signal_connect(quit_elec_1_1,"clicked",G_CALLBACK(enter_page),elecWindow);

    g_signal_connect(quit_phy_1_1,"clicked",G_CALLBACK(enter_page),phyWindow);    
    g_signal_connect(quit_phy_1_2,"clicked",G_CALLBACK(enter_page),phyWindow);    
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void get_mcq_object()
{
    // For qcm_mt1
    question_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "question_mt1"));
    im_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "im_mt1"));
    re_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "re_mt1"));
    answer_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "answer_mt1"));
    valide_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_mt1"));

    question_number_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "question_number_mt1"));
    score_mt1 = GTK_WIDGET(gtk_builder_get_object(builder, "score_mt1"));

    prev_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "prev_mt1"));
    next_mt1 = GTK_BUTTON(gtk_builder_get_object(builder, "next_mt1"));

    // For qcm_ct1
    valide_ct1 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_ct1"));
    question_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "question_ct1"));
    user_answer_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "user_answer_ct1"));
    answer_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "answer_ct1"));

    question_number_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "question_number_ct1"));
    score_ct1 = GTK_WIDGET(gtk_builder_get_object(builder, "score_ct1"));

    prev_ct1 = GTK_BUTTON(gtk_builder_get_object(builder, "prev_ct1"));
    next_ct1 = GTK_BUTTON(gtk_builder_get_object(builder, "next_ct1"));

    // For qcm_ct2
    valide_ct2 = GTK_BUTTON(gtk_builder_get_object(builder, "valide_ct2"));
    question_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "question_ct2"));
    user_answer_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "user_answer_ct2"));
    answer_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "answer_ct2"));

    question_number_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "question_number_ct2"));
    score_ct2 = GTK_WIDGET(gtk_builder_get_object(builder, "score_ct2"));

    prev_ct2 = GTK_BUTTON(gtk_builder_get_object(builder, "prev_ct2"));
    next_ct2 = GTK_BUTTON(gtk_builder_get_object(builder, "next_ct2"));
}

void mcq_prev(GtkButton* button, gpointer user)
{
    User *client = user;
    client->mcq = client->mcq->previous_question;

    client->mcq->activate_next_button = 1;
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),TRUE);

    if (!client->mcq->previous_question)
    {
        gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),FALSE);
    }

    char question_number_buffer[32];

    sprintf(question_number_buffer,"Question n° %i",client->mcq->question_number);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_number_text),question_number_buffer);

    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_text),client->mcq->question);
    
    gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),client->mcq->user_answer1);

    if(strlen(client->mcq->answer2) != 0)
    {
        gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object2),client->mcq->user_answer2);
        gtk_widget_set_sensitive(client->mcqObject->user_answer_object2,FALSE);
    }

    gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),client->mcq->correction);

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),FALSE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,FALSE);
    

    if (client->mcq->activate_prev_button)
    {
        gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),TRUE);
    }
}

void mcq_next(GtkButton* button, gpointer user)
{
    User *client = user;
    client->mcq = client->mcq->next_question;

    client->mcq->activate_prev_button = 1;

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),TRUE);
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),client->mcq->already_done && client->mcq->next_question);
    
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),client->mcq->activate_validate_button);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,client->mcq->activate_validate_button);

    if (strlen(client->mcq->answer2) != 0)
    {
        gtk_widget_set_sensitive(client->mcqObject->user_answer_object2,client->mcq->activate_validate_button);

        if (client->mcq->activate_validate_button)
        {
            gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object2),"");
        }
    }

    if (client->mcq->activate_validate_button)
    {
        gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),"");
        gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),"");
    }

    char question_number_buffer[32];

    sprintf(question_number_buffer,"Question n° %i",client->mcq->question_number);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_number_text),question_number_buffer);

    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_text),client->mcq->question);
    
    if (!client->mcq->activate_validate_button)
    {
        gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),client->mcq->user_answer1);

        if (strlen(client->mcq->answer2) != 0)
        {
            gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object2),client->mcq->user_answer2);
        }

        gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),client->mcq->correction);
    }
}

void check_reponse(GtkButton* button, gpointer user)
{
    User *client = user;
    char score_buffer[256];

    sprintf(client->mcq->user_answer1,"%s",gtk_entry_get_text(GTK_ENTRY(client->mcqObject->user_answer_object1)));

    if (strlen(client->mcq->answer2) == 0)
    {
        if (strlen(client->mcq->user_answer1) != 0)
        { 
            if (strcmp(client->mcq->user_answer1,client->mcq->answer1) == 0)
            {
                client->score += 2;

                sprintf(score_buffer,"Score: %i/20",client->score);
                gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),(const gchar*)score_buffer);
            }

            else
            {
                client->score -= 1;

                sprintf(score_buffer,"Score: %i/20",client->score);
                gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),score_buffer);
            }
        }
        gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),(const gchar*) client->mcq->correction);      
    }

    else
    {
        sprintf(client->mcq->user_answer2,"%s",gtk_entry_get_text(GTK_ENTRY(client->mcqObject->user_answer_object2)));

        if (strlen(client->mcq->user_answer1) != 0 || strlen(client->mcq->user_answer2) != 0)
        { 
            if (strcmp(client->mcq->user_answer1,client->mcq->answer1) == 0 && strcmp(client->mcq->user_answer2,client->mcq->answer2) == 0)
            {
                client->score += 2;

                sprintf(score_buffer,"Score: %i/20",client->score);
                gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),(const gchar*)score_buffer);
            }

            else
            {
                client->score -= 1;

                sprintf(score_buffer,"Score: %i/20",client->score);
                gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),score_buffer);
            }
        }

        gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),(const gchar*) client->mcq->correction);
        gtk_widget_set_sensitive(client->mcqObject->user_answer_object2,FALSE);
    }
    
    client->mcq->activate_validate_button = 0;
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),FALSE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,FALSE);

    client->mcq->already_done = 1;
    
    if (client->mcq->next_question != NULL) // avoid the case of question 11
    {
        client->mcq->activate_next_button = 1;
        gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),TRUE);
    }
}


void enter_mcq_mt1(GtkButton* button, gpointer user)
{
    gtk_widget_hide(GTK_WIDGET(current_window));
    gtk_widget_show(GTK_WIDGET(qcm_mt1));

    current_window = qcm_mt1;

    User* client = user;
    client->score = 0;

    client->mcq =  calloc(1,sizeof(Mcq));

    if (!client->mcq)
    {
        return;
    }
    client->mcqObject = calloc(1,sizeof(McqObject));

    if (!client->mcqObject)
    {
        return;
    }

    init_mcq_mt1(client->mcq);

    client->mcqObject->answer_text = answer_mt1;
    client->mcqObject->next_button = next_mt1;
    client->mcqObject->prev_button = prev_mt1;
    client->mcqObject->question_number_text = question_number_mt1;
    client->mcqObject->score_text = score_mt1;
    client->mcqObject->user_answer_object1 = im_mt1;
    client->mcqObject->user_answer_object2 = re_mt1;
    client->mcqObject->valide_button = valide_mt1;
    client->mcqObject->question_text = question_mt1;

    char question_number_buffer[32];
    char score_buffer[32];

    sprintf(question_number_buffer,"Question n° %i",client->mcq->question_number);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_number_text),question_number_buffer);

    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_text),client->mcq->question);

    sprintf(score_buffer,"Score: %i/20",client->score);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),score_buffer);

    client->mcq->activate_prev_button = 0;

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),FALSE);

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),TRUE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,TRUE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object2,TRUE);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),"");
    gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),"");
    gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object2),"");
}

void enter_mcq_ct1(GtkButton* button, gpointer user)
{   
    gtk_widget_hide(GTK_WIDGET(current_window));
    gtk_widget_show(GTK_WIDGET(qcm_archi1));

    current_window = qcm_archi1;

    User *client = user;
    client->score = 0;

    client->mcq =  calloc(1,sizeof(Mcq));

    if (!client->mcq)
    {
        return;
    }
    client->mcqObject = calloc(1,sizeof(McqObject));

    if (!client->mcqObject)
    {
        return;
    }

    init_mcq_ct1(client->mcq);
    
    client->mcqObject->answer_text = answer_ct1;
    client->mcqObject->next_button = next_ct1;
    client->mcqObject->prev_button = prev_ct1;
    client->mcqObject->question_number_text = question_number_ct1;
    client->mcqObject->score_text = score_ct1;
    client->mcqObject->user_answer_object1 = user_answer_ct1;
    client->mcqObject->valide_button = valide_ct1;
    client->mcqObject->question_text = question_ct1;

    char question_number_buffer[32];
    char score_buffer[32];

    sprintf(question_number_buffer,"Question n° %i",client->mcq->question_number);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_number_text),question_number_buffer);

    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_text),client->mcq->question);

    sprintf(score_buffer,"Score: %i/20",client->score);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),score_buffer);

    client->mcq->activate_prev_button = 0;

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),FALSE);

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),TRUE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,TRUE);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),"");
    gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),"");
}

void enter_mcq_ct2(GtkButton* button, gpointer user)
{   
    gtk_widget_hide(GTK_WIDGET(current_window));
    gtk_widget_show(GTK_WIDGET(qcm_archi2));

    current_window = qcm_archi2;

    User *client = user;
    client->score = 0;

    client->mcq =  calloc(1,sizeof(Mcq));

    if (!client->mcq)
    {
        return;
    }

    client->mcqObject = calloc(1,sizeof(McqObject));

    if (!client->mcqObject)
    {
        return;
    }

    init_mcq_ct2(client->mcq);
    
    client->mcqObject->answer_text = answer_ct2;
    client->mcqObject->next_button = next_ct2;
    client->mcqObject->prev_button = prev_ct2;
    client->mcqObject->question_number_text = question_number_ct2;
    client->mcqObject->score_text = score_ct2;
    client->mcqObject->user_answer_object1 = user_answer_ct2;
    client->mcqObject->valide_button = valide_ct2;
    client->mcqObject->question_text = question_ct2;

    char question_number_buffer[32];
    char score_buffer[32];

    sprintf(question_number_buffer,"Question n° %i",client->mcq->question_number);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_number_text),question_number_buffer);

    gtk_label_set_text(GTK_LABEL(client->mcqObject->question_text),client->mcq->question);

    sprintf(score_buffer,"Score: %i/20",client->score);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->score_text),score_buffer);

    client->mcq->activate_prev_button = 0;

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->prev_button),FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->next_button),FALSE);

    gtk_widget_set_sensitive(GTK_WIDGET(client->mcqObject->valide_button),TRUE);
    gtk_widget_set_sensitive(client->mcqObject->user_answer_object1,TRUE);
    gtk_label_set_text(GTK_LABEL(client->mcqObject->answer_text),"");
    gtk_entry_set_text(GTK_ENTRY(client->mcqObject->user_answer_object1),"");
}

// Function G_signal that launch mcq

void training_signal(User *user)
{
    g_signal_connect(open_mt1,"clicked",G_CALLBACK(enter_mcq_mt1),user);
    
    g_signal_connect(open_at1,"clicked",G_CALLBACK(enter_page),qcm_at1);

    g_signal_connect(open_ct1,"clicked",G_CALLBACK(enter_mcq_ct1),user);
    g_signal_connect(open_ct2,"clicked",G_CALLBACK(enter_mcq_ct2),user);



    g_signal_connect(quit_qcm_mt1,"clicked",G_CALLBACK(enter_page),mainWindow);

    g_signal_connect(quit_qcm_at1,"clicked",G_CALLBACK(enter_page),mainWindow);

    g_signal_connect(quit_qcm_ct1,"clicked",G_CALLBACK(enter_page),mainWindow); 
    g_signal_connect(quit_qcm_ct2,"clicked",G_CALLBACK(enter_page),mainWindow);

}

void training_update_signal(User* user)
{
    g_signal_connect(valide_mt1,"clicked",G_CALLBACK(check_reponse),(gpointer) user);
    g_signal_connect(prev_mt1,"clicked",G_CALLBACK(mcq_prev),(gpointer) user);
    g_signal_connect(next_mt1,"clicked",G_CALLBACK(mcq_next),(gpointer) user);

    g_signal_connect(valide_ct1,"clicked",G_CALLBACK(check_reponse),(gpointer) user);
    g_signal_connect(prev_ct1,"clicked",G_CALLBACK(mcq_prev),(gpointer) user);
    g_signal_connect(next_ct1,"clicked",G_CALLBACK(mcq_next),(gpointer) user);

    g_signal_connect(valide_ct2,"clicked",G_CALLBACK(check_reponse),(gpointer) user);
    g_signal_connect(prev_ct2,"clicked",G_CALLBACK(mcq_prev),(gpointer) user);
    g_signal_connect(next_ct2,"clicked",G_CALLBACK(mcq_next),(gpointer) user);
}

// Function and G_signal for tools

// List

void ui_list_append(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    const gchar* number = gtk_entry_get_text(GTK_ENTRY(tool_list_append_entry));

    list_append(list,atoi(number));

    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);

    gtk_entry_set_text(GTK_ENTRY(tool_list_append_entry),"");
}

void ui_list_pop(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    list_pop(list);
    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);
}

void ui_list_insert(GtkButton* button, gpointer user)
{
    List* list = user;
    char buff[32];

    const gchar* number1 = gtk_entry_get_text(GTK_ENTRY(tool_list_insert_entry1));
    const gchar* number2 = gtk_entry_get_text(GTK_ENTRY(tool_list_insert_entry2));

    list_insert(list,atoi(number1),atoi(number2));

    gtk_label_set_text(GTK_LABEL(tool_list_list_text),list_to_string(list));

    sprintf(buff,"Taille de la liste: %i",list_len(list));
    gtk_label_set_text(GTK_LABEL(tool_list_len_text),buff);

    gtk_entry_set_text(GTK_ENTRY(tool_list_insert_entry1),"");
    gtk_entry_set_text(GTK_ENTRY(tool_list_insert_entry2),"");
}

void list_signal()
{
    List* list = init_list();

    g_signal_connect(tool_list_append_button,"clicked",G_CALLBACK(ui_list_append),list);
    g_signal_connect(tool_list_pop_button,"clicked",G_CALLBACK(ui_list_pop),list);
    g_signal_connect(tool_list_insert_button,"clicked",G_CALLBACK(ui_list_insert),list);
}


GtkBuilder *init_gui()
{
    gtk_init(NULL, NULL);
    builder = gtk_builder_new ();
    GError* error = NULL;

    if (gtk_builder_add_from_file(builder, "../res/EpiLearn.glade", &error) == 0)
    {
        g_printerr("Error loading file: %s\n", error->message);
        g_clear_error(&error);
        return NULL;
    }

    User* client = init_user();

    //get GtkWidget

    get_window();
    get_courses_window();
    get_courses_page();
    get_training_window();

    get_main_enter_button();
    get_main_close_button();

    get_courses_enter_button();
    get_courses_close_button();

    get_courses_page_enter_button();
    get_courses_page_close_button();

    get_enter_training_button();
    get_close_training_button();

    get_tools_object();

    get_mcq_object();

    open_calculator = GTK_MENU_ITEM(gtk_builder_get_object(builder, "open_calculator"));
    open_graph = GTK_MENU_ITEM(gtk_builder_get_object(builder, "open_graph"));

    open_list = GTK_MENU_ITEM(gtk_builder_get_object(builder, "open_list"));
    open_fifo_lifo = GTK_MENU_ITEM(gtk_builder_get_object(builder, "open_fifo_lifo"));
    open_binary_tree = GTK_MENU_ITEM(gtk_builder_get_object(builder, "open_binary_tree"));
    open_paint = GTK_MENU_ITEM(gtk_builder_get_object(builder,"open_paint"));

    //UI signals

    main_signal();
    courses_signal();
    courses_page_signal();
    training_signal(client);
    training_update_signal(client);

    g_signal_connect(open_calculator,"activate",G_CALLBACK(open_calculator_fct),NULL);
    g_signal_connect(open_graph,"activate",G_CALLBACK(open_graph_fct),NULL);

    g_signal_connect(open_list,"activate",G_CALLBACK(open_page),listWindow);
    list_signal();

    // Connects event handlers.
    g_signal_connect(mainWindow,"destroy", G_CALLBACK(gtk_main_quit), NULL);
    gtk_widget_show(GTK_WIDGET(loginWindow));
    // Run the main window.
    gtk_main();
    
    return builder;
}