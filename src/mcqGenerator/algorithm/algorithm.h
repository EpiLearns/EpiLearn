#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../property/algorithm/list/list.h"

void min_index_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3);

void max_index_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3);

void min_val_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3);

void max_val_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3);

void val_in_i_at1_qcm(List* list,size_t index,int* anwser,int* p1,int* p2,int* p3);

void len_at1_qcm(List* list,int* anwser,int* p1,int* p2,int* p3);

#endif