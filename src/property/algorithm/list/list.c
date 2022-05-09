#include <stdio.h>
#include <string.h>
#include "list.h"
#include <stdlib.h>

List* init_list()
{
	List* res = calloc(1,sizeof(List));

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

void list_append(List* list, int data)
{
	List* new_element = calloc(1,sizeof(List));

	if (!new_element)
	{
		return;
	}

	new_element->data = data;

	while(list->next)
	{
		list = list->next;
	}

	list->next = new_element;
}

void list_pop(List* list)
{
	if (!list->next)
	{
		return;
	}

	while (list->next->next)
	{
		list = list->next;
	}

	List* elt = list->next;

	list->next = NULL;

	free(elt);
}

void list_insert(List* list, size_t index,int data)
{
	List* new_element = calloc(1,sizeof(List));
			
	if (!new_element)
	{
		return;
	}

	new_element->data = data;

	size_t i = 0;

	while (i<index && list->next)
	{
		i++;
		list = list->next;
	}

	new_element->next = list->next;
	list->next = new_element;
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

char* list_to_string(List* list)
{
	size_t len = list_len(list);

	if (len == 0)
	{
		return "Liste = []";
	}

	char buff[8];

	char* res = calloc(1,sizeof(char)*100);

	strcat(res,"Liste = [");
	
	size_t i = 0;

	for (;i<len;i++)
	{
		sprintf(buff,"%i,",list->next->data);
		strcat(res,buff);

		list = list->next;
	}

	len = strlen(res);
	res[len-1] = ']';

	return res;
}


/*int main()
{
	List* res = init_list();

	for (size_t i = 0;i<20;i++)
	{
		list_append(res,i);
	}

	char* liste = list_to_string(res);

	printf("%s\n",liste);

	return 0;
}*/