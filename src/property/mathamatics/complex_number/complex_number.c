#include <stdio.h>
#include "complex_number.h"
#include <string.h>

/*int main()
{
    Complex* a = random_comp();
    Complex* b = random_comp();

    print_comp(a);
    print_comp(b);

    printf("plus:");

    Complex* c = comp_plus(a,b);
    print_comp(c);

    printf("moins");
    Complex* d = comp_minus(a,b);
    print_comp(d);

    printf("fois");
    Complex* e = comp_mult(a,b);
    print_comp(e);

    printf("div");
    Complex* f = comp_div(a,b);
    print_comp(f);

    printf("equal");
    int boo = comp_equal(a,b);
    printf("%i",boo);

    free(a);
    free(b);

    return 1;
}*/

void print_comp(Complex* a)
{
    printf("Im = %f Re = %f\n", a->Im,a->Re);
}

Complex* comp_plus(Complex* a,Complex* b)
{
    Complex* res = calloc(1,sizeof(Complex));

    if (!res)
        return NULL;
    
    res->Im = a->Im + b->Im;
    res->Re = a->Re + b->Re;

    return res;
}

Complex* comp_minus(Complex* a,Complex* b)
{
    Complex* res = calloc(1,sizeof(Complex));
    
    if (!res)
        return NULL;

    res->Im = a->Im - b->Im;
    res->Re = a->Re - b->Re;

    return res;
}

Complex* comp_mult(Complex* a,Complex* b)
{
    Complex* res = calloc(1,sizeof(Complex));
    
    if (!res)
        return NULL;

    res->Im = a->Re * b->Im + a->Im * b->Re;
    res->Re = a->Re * b->Re - a->Im * b->Im;

    return res;
}

Complex* comp_div(Complex* lhs,Complex* rhs)
{
    Complex* res = calloc(1,sizeof(Complex));

    if (!res)
        return NULL;
    
    float a = lhs->Re;
    float b = lhs->Im;
    float c = rhs->Re;
    float d = rhs->Im;

    float den = c*c + d*d;

    if (den == 0)
        return NULL;

    res->Im = (b * c - a * d)/den;
    res->Re = (a * c + b * d)/den;

    return res;
}

int comp_equal(Complex* a, Complex* b)
{
    return a->Im == b->Im && a->Re == b->Re;
}

Complex* random_comp()
{
    int a = rand()%30;
    int b = rand()%30;

    Complex* res = calloc(1,sizeof(Complex));
    
    if (!res)
        return NULL;

    res->Im = (float) a;
    res->Re = (float) b;

    return res;
}