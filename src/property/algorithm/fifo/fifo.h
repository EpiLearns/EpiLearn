#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>

typedef struct Fifo
{
    struct Fifo* next;
    int data;

} Fifo;

Fifo* init_fifo();

int fifo_is_empty(Fifo* fifo);

void fifo_push(Fifo* fifo, int data);

void fifo_pop(Fifo* fifo);

char* fifo_to_string(Fifo* fifo);

Fifo* random_fifo();

#endif