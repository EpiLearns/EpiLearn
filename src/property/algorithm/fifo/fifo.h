#ifndef FIFO_H
#define FIFO_H

typedef struct Fifo
{
    struct Fifo* next;
    int data;

} Fifo;

Fifo* init_fifo();

int fifo_is_empty(Fifo* fifo);

Fifo* fifo_push(Fifo* fifo, int data);

Fifo* fifo_pop(Fifo* fifo);

#endif