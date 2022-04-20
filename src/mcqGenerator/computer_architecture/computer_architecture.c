#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../property/computer_architecture/integer_representation/integer_representation.h"
#include "../../mcqGenerator/mcqGenerator.h"

void init_mcq_ct1(Mcq *mcq)
{
    mcq->previous_question = NULL;
    mcq->question_number = 1;

    int random_number = rand()%17;

    sprintf(mcq->question,"Combien fait 2^%i",random_number);
    sprintf(mcq->answer1,"%i",1<<random_number);
    sprintf(mcq->correction,"Correction: %i",1<<random_number);

    mcq->activate_validate_button = 1;
    mcq->already_done = 0;
    mcq->activate_prev_button = 0;
    mcq->activate_next_button = 0;

    Mcq *tmp = mcq;
    
    for (int i = 2 ; i<=10 ; i++)
    {
        Mcq *next = calloc(1,sizeof(Mcq));

        next->previous_question = tmp;
        tmp->next_question = next;

        tmp = tmp->next_question;

        tmp->question_number = i;

        int random_number = rand()%17;

        sprintf(tmp->question,"Combien fait 2^%i",random_number);
        sprintf(tmp->answer1,"%i",1<<random_number);
        sprintf(tmp->correction,"Correction: %i",1<<random_number);

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }
}

void init_mcq_ct2(Mcq *mcq)
{
    mcq->previous_question = NULL;
    mcq->question_number = 1;

    int depart = rand()%9 + 2;
    int arrivee = rand()%9 + 2;

    int nbre = rand()%100;

    unsigned long nbre_base_depart = convertirEnbase(depart,(unsigned long)nbre,10);
    unsigned long nbre_base_arrivee = convertirEnbase(arrivee,(unsigned long) nbre,10);

    sprintf(mcq->question,"Donner la représentation en base %i de %lu (en base %i)?",arrivee,nbre_base_depart,depart);
    sprintf(mcq->answer1,"%lu",nbre_base_arrivee);
    sprintf(mcq->correction,"Correction: %lu",nbre_base_arrivee);

    mcq->activate_validate_button = 1;
    mcq->already_done = 0;
    mcq->activate_prev_button = 0;
    mcq->activate_next_button = 0;

    Mcq *tmp = mcq;
    
    for (int i = 2 ; i<=10 ; i++)
    {
        Mcq *next = calloc(1,sizeof(Mcq));

        next->previous_question = tmp;
        tmp->next_question = next;

        tmp = tmp->next_question;

        tmp->question_number = i;

        depart = rand()%9 + 2;
        arrivee = rand()%9 + 2;

        nbre = rand()%100;

        nbre_base_depart = convertirEnbase(depart,(unsigned long)nbre,10);
        nbre_base_arrivee = convertirEnbase(arrivee,(unsigned long) nbre,10);

        sprintf(tmp->question,"Donner la représentation en base %i de %lu (en base %i)?",arrivee,nbre_base_depart,depart);
        sprintf(tmp->answer1,"%lu",nbre_base_arrivee);
        sprintf(tmp->correction,"Correction: %lu",nbre_base_arrivee);

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }
}

void free_qcm_ct1(Mcq* mcq)
{
    Mcq* tmp;

    while (mcq)
    {
        tmp = mcq;
        mcq = mcq->next_question;

        free(tmp);
    }
}

/*int main()
{
    Mcq* mcq1 = calloc(1,sizeof(Mcq));
    Mcq* mcq2 = calloc(1,sizeof(Mcq));

    init_mcq_ct1(mcq1);
    init_mcq_ct2(mcq2);

    for(; mcq1; mcq1 = mcq1->next_question)
    {
        printf("Question n°%i : %s\n",mcq1->question_number,mcq1->question);
        printf("%s\n",mcq1->correction); 
    }

    for(; mcq2; mcq2 = mcq2->next_question)
    {
        printf("Question n°%i : %s\n",mcq2->question_number,mcq2->question);
        printf("%s\n",mcq2->correction); 
    }

    return EXIT_SUCCESS;
}*/