#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../property/mathematics/complex_number/complex_number.h"
#include "../../mcqGenerator/mcqGenerator.h"

void init_mcq_mt1(Mcq *mcq)
{
    mcq->previous_question = NULL;
    mcq->question_number = 1;

    int n = rand()%3;

    Complex* a = random_comp();
    Complex* b = random_comp();

    Complex* rep; 

    if (n == 0)
    {
        sprintf(mcq->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 + Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
        rep = comp_plus(a,b);

        sprintf(mcq->answer1,"%i",(int) rep->Im);
        sprintf(mcq->answer2,"%i",(int) rep->Re);

        sprintf(mcq->correction,"Correction: %i i + %i",(int) rep->Im, (int)rep->Re);
    }

    if (n == 1)
    {
        sprintf(mcq->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 - Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
        rep = comp_minus(a,b);

        sprintf(mcq->answer1,"%i",(int) rep->Im);
        sprintf(mcq->answer2,"%i",(int) rep->Re);

        sprintf(mcq->correction,"Correction: %i i + %i",(int) rep->Im, (int)rep->Re);
    }

    else
    {
        sprintf(mcq->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 * Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
        rep = comp_mult(a,b);

        sprintf(mcq->answer1,"%i",(int) rep->Im);
        sprintf(mcq->answer2,"%i",(int) rep->Re);

        sprintf(mcq->correction,"Correction: %i i + %i",(int) rep->Im, (int)rep->Re);
    }

    mcq->activate_validate_button = 1;
    mcq->already_done = 0;
    mcq->activate_prev_button = 0;
    mcq->activate_next_button = 0;

    Mcq *tmp = mcq;
    
    for (int i = 2 ; i<=10 ; i++)
    {
        free(a);
        free(b);
        free(rep);

        Mcq *next = calloc(1,sizeof(Mcq));

        next->previous_question = tmp;
        tmp->next_question = next;

        tmp = tmp->next_question;

        tmp->question_number = i;

        n = rand()%3;

        a = random_comp();
        b = random_comp();

        if (n == 0)
        {
            sprintf(tmp->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 + Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
            rep = comp_plus(a,b);

            sprintf(tmp->answer1,"%i",(int) rep->Im);
            sprintf(tmp->answer2,"%i",(int) rep->Re);

            sprintf(tmp->correction,"Correction: %i i + %i",(int) rep->Im, (int)rep->Re);
        }

        if (n == 1)
        {
            sprintf(tmp->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 - Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
            rep = comp_minus(a,b);

            sprintf(tmp->answer1,"%i",(int) rep->Im);
            sprintf(tmp->answer2,"%i",(int) rep->Re);

            sprintf(tmp->correction,"Correction: %i i + %i",(int) rep->Im, (int) rep->Re);
        }

        else
        {
            sprintf(tmp->question,"Soit Z1 = %i i + %i et Z2 = %i i + %i que vaut Z1 * Z2 ?",(int) a->Im,(int) a->Re,(int) b->Im,(int) b->Re);
            rep = comp_mult(a,b);

            sprintf(tmp->answer1,"%i",(int) rep->Im);
            sprintf(tmp->answer2,"%i",(int) rep->Re);

            sprintf(tmp->correction,"Correction: %i i + %i",(int) rep->Im, (int)rep->Re);
        }

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }

    free(a);
    free(b);
    free(rep);
}

void free_mcq_mt1(Mcq *mcq)
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
    Mcq* mcq = calloc(1,sizeof(Mcq));

    init_mcq_mt1(mcq);

    for(; mcq; mcq = mcq->next_question)
    {
        printf("Question n°%i : %s\n",mcq->question_number,mcq->question);
        printf("%s i + %s\n",mcq->answer1,mcq->answer2); 
    }

    return EXIT_SUCCESS;
}*/