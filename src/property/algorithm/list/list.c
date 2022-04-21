#include <stdio.h>
#include <string.h>
#include "list.h"
#include <stdlib.h>

List* init_list()
{
	List* res  = calloc(1,sizeof(List));

	if (!res)
	{
		return NULL;
	}

	return res;
}

int list_is_empty(List* list)
{
	return list->next == NULL;
}

int list_len(List* list)
{
	int res = 0;

	list = list->next;

	while (list)
	{
		res += 1;
		list = list->next;
	}

	return res;
}

List* list_append(List* list, int data)
{
	List* new_element = calloc(1,sizeof(List));

	if (!new_element)
	{
		return NULL;
	}

	new_element->data = data;

	List* tmp = list->next;

	while(tmp)
	{
		tmp = tmp->next;
	}

	tmp = new_element;

	return list;
}

List* list_pop(List* list)
{
	List* tmp = list;

	if (!tmp->next)
	{
		return list;
	}

	while (tmp->next->next)
	{
		tmp = tmp->next;
	}

	List* elt = tmp->next;

	tmp->next = NULL;

	free(elt);

	return list;
}

List* list_insert(List* list, size_t index,int data)
{
	List* tmp = list;

	List* new_element = calloc(1,sizeof(List));
			
	if (!new_element)
	{
		return NULL;
	}

	new_element->data = data;

	size_t i = 0;

	while (i<index && tmp->next)
	{
		i++;
		tmp = tmp->next;
	}

	new_element->next = tmp->next;
	tmp->next = new_element;

	return list;
}

void free_list(List* list)
{
	List* tmp = list;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
