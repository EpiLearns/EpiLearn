#include <stdio.h>
#include <string.h>
#include "search_list.h"
#include <stdlib.h>

int array_min(int array[], size_t len)
{
	int res = array[0];
	
	for(size_t i = 1;i<len;i++)
	{
		if(array[i]<res)
			res = array[i];
	}

	return res;
}

int array_max(int array[], size_t len)
{
	int res = array[0];
	
	for(size_t i = 1;i<len;i++)
	{
		if(array[i]>res)
			res = array[i];
	}

	return res;
}

size_t array_min_index(int array[], size_t len)
{
    size_t res = 0;

    for(size_t i = 1; i<len;i++)
    {
	    if(array[i]<array[res])
		    res = i;
	    
    }

    return res;
}

size_t array_max_index(int array[], size_t len)
{
    size_t res = 0;

    for(size_t i = 1;i<len;i++)
    {
	    if(array[i]>array[res])
		    res = i;
    }

    return res;
}

size_t array_bin_search(int array[], size_t len, int x)
{
	size_t left = 0;
	size_t right = len;

	while(left<right)
	{
		size_t mid = left + (right-left) / 2;
		if(array[mid] == x)
			return mid;
		
		if(x<array[mid])
			right = mid;
		else
			left = mid+1;
	}

	return right;
}

size_t array_find(int array[], size_t len, int x)
{
	for(size_t i = 0;i<len;i++)
	{
		if(array[i] == x)
			return i;
	}
	return len;
}

void array_random_sorted_fill(int array[], size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        int tmp = rand()%30;
        array[i] = tmp;
    }
}