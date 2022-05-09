#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void lifo_enqueue(Lifo* lifo,int data)
{
    Lifo* new_element = calloc(1,sizeof(Lifo));

    if (!new_element)
    {
        return;
    }

    new_element->data = data;
    new_element->next = lifo->next;

    lifo->next = new_element;
}

void lifo_dequeue(Lifo* lifo)
{
    if (lifo_is_empty(lifo))
    {
        return;
    }

    while (lifo->next->next)
    {
        lifo = lifo->next;
    }

    Lifo* remove = lifo->next;
    lifo->next = NULL;

    free(remove);
}

char* lifo_to_string(Lifo* lifo)
{
	if (lifo_is_empty(lifo))
	{
		return "File = []";
	}

	char buff[8];

	char* res = calloc(1,sizeof(char)*100);

	strcat(res,"File = [");

	for (;lifo->next;lifo = lifo->next)
	{
		sprintf(buff,"%i,",lifo->next->data);
		strcat(res,buff);
	}

	size_t len = strlen(res);
	res[len-1] = ']';

	return res;
}


/*int main()
{
	Lifo* res = init_lifo();

	for (size_t i = 0;i<20;i++)
	{
		lifo_enqueue(res,i);
	}

    lifo_dequeue(res);

	char* liste = lifo_to_string(res);

	printf("%s\n",liste);

	return 0;
}*/