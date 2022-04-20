#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../property/mathematics/complex_number/complex_number.h"
#include "../../mcqGenerator/mcqGenerator.h"

void init_mcq_mt1(Mcq *mcq);

void free_mcq_mt1(Mcq *mcq);

#endif