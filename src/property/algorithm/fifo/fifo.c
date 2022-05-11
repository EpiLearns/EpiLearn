#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void fifo_push(Fifo* fifo, int data)
{
    Fifo* new_element = calloc(1,sizeof(Fifo));

    if (!new_element)
    {
        return;
    }

    new_element->data = data;
    new_element->next = fifo->next;

    fifo->next = new_element;
}

void fifo_pop(Fifo* fifo)
{
    if(fifo_is_empty(fifo))
    {
        return;
    }

    Fifo* remove = fifo->next;

    fifo->next = fifo->next->next;

    free(remove);
}

char* fifo_to_string(Fifo* fifo)
{
	if(fifo_is_empty(fifo))
	{
		return "Pile = []";
	}

	char buff[8];

	char* res = calloc(1,sizeof(char)*100);

	strcat(res,"Pile = [");

	for (;fifo->next;fifo = fifo->next)
	{
		sprintf(buff,"%i,",fifo->next->data);
		strcat(res,buff);
	}

	size_t len = strlen(res);
	res[len-1] = ']';

	return res;
}

/*int main()
{
	Fifo* res = init_fifo();

	for (size_t i = 0;i<20;i++)
	{
		fifo_push(res,i);
	}

    fifo_pop(res);

	char* liste = fifo_to_string(res);

	printf("%s\n",liste);

	return 0;
}*/