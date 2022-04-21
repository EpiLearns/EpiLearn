#include <stdio.h>
#include <stdlib.h>

#include "lifo.h"

Lifo* init_lifo()
{
    Lifo* res = calloc(1,sizeof(Lifo));

    if (!res)
    {
        return NULL;
    }

    return res;
}

int lifo_is_empty(Lifo* lifo)
{
    return lifo->next == NULL;
}

Lifo* lifo_enqueue(Lifo* lifo,int data)
{
    Lifo* new_element = calloc(1,sizeof(Lifo));

    if (!new_element)
    {
        return NULL;
    }

    new_element->data = data;
    new_element->next = lifo->next;

    lifo->next = new_element;

    return lifo;
}

Lifo* lifo_dequeue(Lifo* lifo)
{
    if (lifo_is_empty(lifo))
    {
        return lifo;
    }

    Lifo* tmp = lifo;

    while (tmp->next->next)
    {
        tmp = tmp->next;
    }

    Lifo* remove = tmp->next;
    tmp->next = NULL;

    free(remove);

    return lifo;
}