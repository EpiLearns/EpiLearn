#ifndef SEARCH_LIST_H
#define SEARCH_LIST_H

#include <stdlib.h>

typedef struct List
{
    int data;
    struct List* next;
} List;

List* init_list();

int list_is_empty(List* list);

int list_len(List* list);

void list_append(List* list, int data);

void list_pop(List* list);

void list_insert(List* list, size_t index,int data);

void free_list(List* list);

char* list_to_string(List* list);

#endif