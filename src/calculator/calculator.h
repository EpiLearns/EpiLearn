#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <string.h>
#include <assert.h>
#include <math.h>
#include <err.h>

int findpivot(const char* chain,int size);
int power(int a, int b);
int sign(const char* chain,int size);
double calculR(const char* chain,int size);
double calcul(const char* chain);
void decimal(int d, double res);

#endif



