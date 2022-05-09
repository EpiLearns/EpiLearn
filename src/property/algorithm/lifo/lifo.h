#ifndef LIFO_H
#define LIFO_H

typedef struct Lifo
{
    struct Lifo* next;
    int data;

} Lifo;

Lifo* init_lifo();

int lifo_is_empty(Lifo* lifo);

void lifo_enqueue(Lifo* lifo,int data);

void lifo_dequeue(Lifo* lifo);

char* lifo_to_string(Lifo* lifo);

#endif