#ifndef CALCULATRICE_H
#define CALCULATRICE_H

#include <string.h>
#include <assert.h>
#include <math.h>
#include <err.h>

int findpivot(const char* chain,int size);
int power(int a, int b);
double calculR(const char* chain,int size,int x);
double calcul(const char* chaine);
void decimal(int d, double res);

#endif



