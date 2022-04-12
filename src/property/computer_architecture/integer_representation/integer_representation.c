#include<stdio.h>
#include "integer_representation.h"

unsigned long power_of_two(unsigned char n)
{
    return (unsigned long) 1 << n;
}

unsigned long convertirEnbase(int base_depart_arrivee, unsigned long n, int base_depart)
{
    unsigned long quotient = n / base_depart_arrivee;
    unsigned long reste = n % base_depart_arrivee;

    if (quotient == 0)
        return reste;

    else
        return convertirEnbase(base_depart_arrivee,quotient, base_depart) * base_depart + reste;
}