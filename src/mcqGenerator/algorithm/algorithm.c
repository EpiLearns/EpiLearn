#include "algorithm.h"

void min_index_at1_qcm(List* list,int* answer,int* p1,int* p2,int* p3)
{
    *answer = get_min_index(list);

    size_t len = list_len(list);

    do
    {
        *p1 = rand()%len;

    } while(*p1 == *answer);

    do
    {
        *p2 = rand()%len;

    } while(*p2 == *answer || *p2 == *p1);

    do
    {
        *p3 = rand()%len;

    } while(*p3 == *answer || *p3 == *p1 || *p3 == *p2);
}

void max_index_at1_qcm(List* list,int* answer,int* p1,int* p2,int* p3)
{
    *answer = get_max_index(list);

    size_t len = list_len(list);

    do
    {
        *p1 = rand()%len;

    } while(*p1 == *answer);

    do
    {
        *p2 = rand()%len;

    } while(*p2 == *answer || *p2 == *p1);

    do
    {
        *p3 = rand()%len;

    } while(*p3 == *answer || *p3 != *p1 || *p3 == *p2);
}

void min_val_at1_qcm(List* list,int* answer,int* p1,int* p2,int* p3)
{
    size_t index = get_min_index(list);
    *answer = get_val_in_i(list,index);

    do
    {
        *p1 = rand()%31;

    } while(*p1 == *answer);

    do
    {
        *p2 = rand()%31;

    } while(*p2 == *answer||*p2 == *p1);

    do
    {
        *p3 = rand()%31;

    } while(*p3 == *answer || *p3 == *p1 || *p3 == *p2);
}

void max_val_at1_qcm(List* list,int* answer,int* p1,int* p2,int* p3)
{
    size_t index = get_max_index(list);
    *answer = get_val_in_i(list,index);

    do
    {
        *p1 = rand()%31;

    } while(*p1 == *answer);

    do
    {
        *p2 = rand()%31;

    } while(*p2 == *answer||*p2 == *p1);

    do
    {
        *p3 = rand()%31;

    } while(*p3 == *answer || *p3 == *p1 || *p3 == *p2);
}

void val_in_i_at1_qcm(List* list,size_t index,int* answer,int* p1,int* p2,int* p3)
{
    *answer = get_val_in_i(list,index);

    size_t len = list_len(list);

    size_t tmp1;
    size_t tmp2;
    size_t tmp3;

    do
    {
        tmp1 = rand()%len;

    } while(tmp1 == index);

    *p1 = get_val_in_i(list,tmp1);

    do
    {
        tmp2 = rand()%len;

    } while(tmp2 == index || tmp2 == tmp1);

    *p2 = get_val_in_i(list,tmp2);

    do
    {
        tmp3 = rand()%len;

    } while(tmp3 == index || tmp3 == tmp1 || tmp3 == tmp2);

    *p3 = get_val_in_i(list,tmp3);
}

void len_at1_qcm(List* list,int* answer,int* p1,int* p2,int* p3)
{
    *answer = list_len(list);

    *p1 = *answer -1;
    *p2 = *answer + 1;

    *p3 = *answer + 2;
}

void init_mcq_at1(Mcq* mcq)
{
    int a;
    int b;
    int c;
    int d;
    List* list;
    char* liste;

    mcq->previous_question = NULL;
    mcq->question_number = 1;

    int nbre = rand()%6;

    if (nbre == 0)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est l'indice de la valeur minimale de la liste ?",liste);

        min_index_at1_qcm(list,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 1)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est l'indice de la valeur maximale de la liste ?",liste);

        max_index_at1_qcm(list,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 2)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est la valeur minimale de la liste ?",liste);

        min_val_at1_qcm(list,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 3)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est la valeur maximale de la liste ?",liste);

        max_val_at1_qcm(list,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 4)
    {
        list = random_list();
        liste = list_to_string(list);

        size_t len = list_len(list);
        int index = rand()%len;

        sprintf(mcq->question,"Liste = %s\nQuel est la valeur à l'indice %i de la liste ?",liste,index);

        val_in_i_at1_qcm(list,index,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 5)
    {
        list = random_list();
        liste = list_to_string(list);

        sprintf(mcq->question,"Liste = %s\nQuel est la taille de la liste ?",liste);

        len_at1_qcm(list,&a,&b,&c,&d);

        for (size_t i = 0; i<4; i++)
        {
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(mcq->prop1,"%i",a);
                sprintf(mcq->prop2,"%i",b);
                sprintf(mcq->prop3,"%i",c);
                sprintf(mcq->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(mcq->prop1,"%i",b);
                sprintf(mcq->prop2,"%i",c);
                sprintf(mcq->prop3,"%i",d);
                sprintf(mcq->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(mcq->prop1,"%i",c);
                sprintf(mcq->prop2,"%i",d);
                sprintf(mcq->prop3,"%i",a);
                sprintf(mcq->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(mcq->prop1,"%i",d);
                sprintf(mcq->prop2,"%i",a);
                sprintf(mcq->prop3,"%i",b);
                sprintf(mcq->prop4,"%i",c);
            }
        }

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

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

        int nbre = rand()%6;

        if (nbre == 0)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(mcq->question,"Liste = %s\nQuel est l'indice de la valeur minimale de la liste ?",liste);

            min_index_at1_qcm(list,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        if (nbre == 1)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(mcq->question,"Liste = %s\nQuel est l'indice de la valeur maximale de la liste ?",liste);

            max_index_at1_qcm(list,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        if (nbre == 2)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(mcq->question,"Liste = %s\nQuel est la valeur minimale de la liste ?",liste);

            min_val_at1_qcm(list,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        if (nbre == 3)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(mcq->question,"Liste = %s\nQuel est la valeur maximale de la liste ?",liste);

            max_val_at1_qcm(list,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        if (nbre == 4)
        {
            list = random_list();
            liste = list_to_string(list);

            size_t len = list_len(list);
            int index = rand()%len;

            sprintf(mcq->question,"Liste = %s\nQuel est la valeur à l'indice %i de la liste ?",liste,index);

            val_in_i_at1_qcm(list,index,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        if (nbre == 5)
        {
            list = random_list();
            liste = list_to_string(list);

            sprintf(mcq->question,"Liste = %s\nQuel est la taille de la liste ?",liste);

            len_at1_qcm(list,&a,&b,&c,&d);

            for (size_t i = 0; i<4; i++)
            {
                int choix = rand()%4;

                if (choix == 0)
                {
                    sprintf(mcq->prop1,"%i",a);
                    sprintf(mcq->prop2,"%i",b);
                    sprintf(mcq->prop3,"%i",c);
                    sprintf(mcq->prop4,"%i",d);
                }

                if (choix == 1)
                {
                    sprintf(mcq->prop1,"%i",b);
                    sprintf(mcq->prop2,"%i",c);
                    sprintf(mcq->prop3,"%i",d);
                    sprintf(mcq->prop4,"%i",a);
                }

                if (choix == 2)
                {
                    sprintf(mcq->prop1,"%i",c);
                    sprintf(mcq->prop2,"%i",d);
                    sprintf(mcq->prop3,"%i",a);
                    sprintf(mcq->prop4,"%i",b);
                }

                if (choix == 3)
                {
                    sprintf(mcq->prop1,"%i",d);
                    sprintf(mcq->prop2,"%i",a);
                    sprintf(mcq->prop3,"%i",b);
                    sprintf(mcq->prop4,"%i",c);
                }
            }

            sprintf(mcq->answer1,"%i",a);
            sprintf(mcq->correction,"Correction: %i",a);
        }

        mcq->activate_validate_button = 1;
        mcq->already_done = 0;
        mcq->activate_prev_button = 0;
        mcq->activate_next_button = 0;
    }
}