#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

Fifo* init_fifo()
{
    Fifo* res = calloc(1,sizeof(Fifo));

    if (!res)
    {
        return NULL;
    }

    return res;
}

int fifo_is_empty(Fifo* fifo)
{
    return fifo->next == NULL;
}

Fifo* fifo_push(Fifo* fifo, int data)
{
    Fifo* new_element = calloc(1,sizeof(Fifo));

    if (!new_element)
    {
        return NULL;
    }

    new_element->data = data;
    new_element->next = fifo->next;

    fifo->next = new_element;

    return fifo;
}

Fifo* fifo_pop(Fifo* fifo)
{
    if(fifo_is_empty(fifo))
    {
        return fifo;
    }

    Fifo* remove = fifo->next;

    fifo->next = fifo->next->next;

    free(remove);

    return fifo;
}