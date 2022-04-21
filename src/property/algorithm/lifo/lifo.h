#ifndef LIFO_H
#define LIFO_H

typedef struct Lifo
{
    struct Lifo* next;
    int data;

} Lifo;

Lifo* init_lifo();

int lifo_is_empty(Lifo* lifo);

Lifo* lifo_enqueue(Lifo* lifo,int data);

Lifo* lifo_dequeue(Lifo* lifo);

#endif