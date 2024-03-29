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

    } while(*p3 == *answer || *p3 == *p1 || *p3 == *p2);
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

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 1)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est l'indice de la valeur maximale de la liste ?",liste);

        max_index_at1_qcm(list,&a,&b,&c,&d);

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
            
        

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 2)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est la valeur minimale de la liste ?",liste);

        min_val_at1_qcm(list,&a,&b,&c,&d);

        
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
        

        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 3)
    {
        list = random_list();
        liste = list_to_string(list);
        sprintf(mcq->question,"Liste = %s\nQuel est la valeur maximale de la liste ?",liste);

        max_val_at1_qcm(list,&a,&b,&c,&d);

        
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


        sprintf(mcq->answer1,"%i",a);
        sprintf(mcq->correction,"Correction: %i",a);
    }

    if (nbre == 5)
    {
        list = random_list();
        liste = list_to_string(list);

        sprintf(mcq->question,"Liste = %s\nQuel est la taille de la liste ?",liste);

        len_at1_qcm(list,&a,&b,&c,&d);

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
            sprintf(tmp->question,"Liste = %s\nQuel est l'indice de la valeur minimale de la liste ?",liste);

            min_index_at1_qcm(list,&a,&b,&c,&d);
        
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }
            

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        if (nbre == 1)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(tmp->question,"Liste = %s\nQuel est l'indice de la valeur maximale de la liste ?",liste);

            max_index_at1_qcm(list,&a,&b,&c,&d);

            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        if (nbre == 2)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(tmp->question,"Liste = %s\nQuel est la valeur minimale de la liste ?",liste);

            min_val_at1_qcm(list,&a,&b,&c,&d);

            
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        if (nbre == 3)
        {
            list = random_list();
            liste = list_to_string(list);
            sprintf(tmp->question,"Liste = %s\nQuel est la valeur maximale de la liste ?",liste);

            max_val_at1_qcm(list,&a,&b,&c,&d);

            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        if (nbre == 4)
        {
            list = random_list();
            liste = list_to_string(list);

            size_t len = list_len(list);
            int index = rand()%len;

            sprintf(tmp->question,"Liste = %s\nQuel est la valeur à l'indice %i de la liste ?",liste,index);

            val_in_i_at1_qcm(list,index,&a,&b,&c,&d);

            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        if (nbre == 5)
        {
            list = random_list();
            liste = list_to_string(list);

            sprintf(tmp->question,"Liste = %s\nQuel est la taille de la liste ?",liste);

            len_at1_qcm(list,&a,&b,&c,&d);
    
            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",a);
                sprintf(tmp->prop2,"%i",b);
                sprintf(tmp->prop3,"%i",c);
                sprintf(tmp->prop4,"%i",d);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",b);
                sprintf(tmp->prop2,"%i",c);
                sprintf(tmp->prop3,"%i",d);
                sprintf(tmp->prop4,"%i",a);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",c);
                sprintf(tmp->prop2,"%i",d);
                sprintf(tmp->prop3,"%i",a);
                sprintf(tmp->prop4,"%i",b);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",d);
                sprintf(tmp->prop2,"%i",a);
                sprintf(tmp->prop3,"%i",b);
                sprintf(tmp->prop4,"%i",c);
            }

            sprintf(tmp->answer1,"%i",a);
            sprintf(tmp->correction,"Correction: %i",a);
        }

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }
}

void init_mcq_at2(Mcq* mcq)
{
    Fifo* fifo;
    Lifo* lifo;
    char* liste;

    mcq->previous_question = NULL;
    mcq->question_number = 1;

    int nbre = rand()%2;

    if (nbre == 0)
    {
        fifo = random_fifo();
        liste = fifo_to_string(fifo);
        sprintf(mcq->question,"%s\nQuel est la sommet de la pile ?",liste);

        int choix = rand()%4;

        if (choix == 0)
        {
            sprintf(mcq->prop1,"%i",fifo->next->data);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 1)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",fifo->next->data);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 2)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",fifo->next->data);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 3)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",fifo->next->data);
        }    

        sprintf(mcq->answer1,"%i",fifo->next->data);
        sprintf(mcq->correction,"Correction: %i",fifo->next->data);
    }

    if (nbre == 1)
    {
        lifo = random_lifo();
        liste = lifo_to_string(lifo);
        sprintf(mcq->question,"%s\nQuel est le dernier élément de la file ?",liste);

        int choix = rand()%4;

        while (lifo->next)
        {
            lifo = lifo->next;
        }

        if (choix == 0)
        {
            sprintf(mcq->prop1,"%i",lifo->data);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 1)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",lifo->data);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 2)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",lifo->data);
            sprintf(mcq->prop4,"%i",rand()%31);
        }

        if (choix == 3)
        {
            sprintf(mcq->prop1,"%i",rand()%31);
            sprintf(mcq->prop2,"%i",rand()%31);
            sprintf(mcq->prop3,"%i",rand()%31);
            sprintf(mcq->prop4,"%i",lifo->data);
        }    

        sprintf(mcq->answer1,"%i",lifo->data);
        sprintf(mcq->correction,"Correction: %i",lifo->data);
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

        nbre = rand()%2;

        if (nbre == 0)
        {
            fifo = random_fifo();
            liste = fifo_to_string(fifo);
            sprintf(tmp->question,"%s\nQuel est la sommet de la pile ?",liste);

            int choix = rand()%4;

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",fifo->next->data);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",fifo->next->data);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",fifo->next->data);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",fifo->next->data);
            }    

            sprintf(tmp->answer1,"%i",fifo->next->data);
            sprintf(tmp->correction,"Correction: %i",fifo->next->data);
        }

        if (nbre == 1)
        {
            lifo = random_lifo();
            liste = lifo_to_string(lifo);
            sprintf(tmp->question,"%s\nQuel est le dernier élément de la file ?",liste);

            int choix = rand()%4;

            while (lifo->next)
            {
                lifo = lifo->next;
            }

            if (choix == 0)
            {
                sprintf(tmp->prop1,"%i",lifo->data);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 1)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",lifo->data);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 2)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",lifo->data);
                sprintf(tmp->prop4,"%i",rand()%31);
            }

            if (choix == 3)
            {
                sprintf(tmp->prop1,"%i",rand()%31);
                sprintf(tmp->prop2,"%i",rand()%31);
                sprintf(tmp->prop3,"%i",rand()%31);
                sprintf(tmp->prop4,"%i",lifo->data);
            }    

            sprintf(tmp->answer1,"%i",lifo->data);
            sprintf(tmp->correction,"Correction: %i",lifo->data);
        }

        tmp->activate_validate_button = 1;
        tmp->already_done = 0;
        tmp->activate_prev_button = 0;
        tmp->activate_next_button = 0;
    }
}

/*int main()
{
    Mcq* mcq = calloc(1,sizeof(Mcq));

    init_mcq_at2(mcq);
}*/