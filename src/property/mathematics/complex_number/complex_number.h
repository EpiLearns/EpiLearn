#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <stdlib.h>

typedef struct Complex
{
    float Re;
    float Im;

} Complex;

Complex* comp_plus(Complex* a,Complex* b);

Complex* comp_minus(Complex* a,Complex* b);

Complex* comp_mult(Complex* a,Complex* b);

Complex* comp_div(Complex* lhs,Complex* rhs);

int comp_equal(Complex* a, Complex* b);

Complex* random_comp();

void print_comp(Complex* a);

#endif
