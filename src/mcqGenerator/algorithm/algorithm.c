#include "algorithm.h"

void min_index_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3)
{
    *anwser = get_min_index(list);

    size_t len = list_len(list);

    do
    {
        *p1 = rand()%len;

    } while(*p1 != *anwser)

    do
    {
        *p2 = rand()%len;

    } while(*p2 != *anwser && *p2 != *p1)

    do
    {
        *p3 = rand()%len;

    } while(*p3 != *anwser && *p3 != *p1 && *p3 != *p2)
}

void max_index_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3)
{
    *anwser = get_max_index(list);

    size_t len = list_len(list);

    do
    {
        *p1 = rand()%len;

    } while(*p1 != *anwser)

    do
    {
        *p2 = rand()%len;

    } while(*p2 != *anwser && *p2 != *p1)

    do
    {
        *p3 = rand()%len;

    } while(*p3 != *anwser && *p3 != *p1 && *p3 != *p2)
}

void min_val_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3)
{
    size_t index = get_min_index(list);
    *answer = get_val_in_i(list,index);

    size_t len = list_len(list);

    size_t tmp1;
    size_t tmp2;
    size_t tmp3;

    do
    {
        tmp1 = rand()%len;

    } while(tmp1 != index)

    *p1 = get_val_in_i(list,tmp1);

    do
    {
        tmp2 = rand()%len;

    } while(tmp2 != index && tmp2 != tmp1)

    *p2 = get_val_in_i(list,tmp2);

    do
    {
        tmp3 = rand()%len;

    } while(tmp3 != index && tmp3 != tmp1 && tmp3 != tmp2)

    *p3 = get_val_in_i(list,tmp3);
}

void max_val_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3)
{
    size_t index = get_max_index(list);
    *answer = get_val_in_i(list,index);

    size_t len = list_len(list);

    size_t tmp1;
    size_t tmp2;
    size_t tmp3;

    do
    {
        tmp1 = rand()%len;

    } while(tmp1 != index)

    *p1 = get_val_in_i(list,tmp1);

    do
    {
        tmp2 = rand()%len;

    } while(tmp2 != index && tmp2 != tmp1)

    *p2 = get_val_in_i(list,tmp2);

    do
    {
        tmp3 = rand()%len;

    } while(tmp3 != index && tmp3 != tmp1 && tmp3 != tmp2)

    *p3 = get_val_in_i(list,tmp3);
}

void val_in_i_at1_qcm(List* list,size_t index,int* anwser,int* p1,int* p2,int* p3)
{
    *answer = get_val_in_i(list,index);

    size_t len = list_len(list);

    size_t tmp1;
    size_t tmp2;
    size_t tmp3;

    do
    {
        tmp1 = rand()%len;

    } while(tmp1 != index)

    *p1 = get_val_in_i(list,tmp1);

    do
    {
        tmp2 = rand()%len;

    } while(tmp2 != index && tmp2 != tmp1)

    *p2 = get_val_in_i(list,tmp2);

    do
    {
        tmp3 = rand()%len;

    } while(tmp3 != index && tmp3 != tmp1 && tmp3 != tmp2)

    *p3 = get_val_in_i(list,tmp3);
}

void len_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3)
{
    *answer = list_len(list);

    *p1 = *answer -1;
    *p2 = *answer + 1;

    *p3 = *answer + 2;
}