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

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }
}

/*int main()
{
    Mcq* mcq = calloc(1,sizeof(Mcq));

    init_mcq_ct1(mcq);

    for(; mcq; mcq = mcq->next_question)
    {
        printf("Question n°%i : %s\n",mcq->question_number,mcq->question);
        printf("%s\n",mcq->answer1); 
    }

    return EXIT_SUCCESS;
}*/