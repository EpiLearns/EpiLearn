#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>



node* createNode(void){
    node* out = malloc(sizeof(node));
    out->left = NULL;
    out->right = NULL;
    out->operator = NULL;
    out->value = 0;
    return out; 
}

double calculator_evaluate(node* head){
    if(head == NULL) return 0;
    
    //evaluate operator first, value only if operator is null
    if(head->operator == NULL){
        double value = head->value;
        free(head);
        return value;
    }
    else{
        double (*operator) (double, double) = head->operator;
        node* left = head->left;
        node* right = head->right;
        free(head);
        return operator(calculator_evaluate(left), calculator_evaluate(right));
    }
}

double add(double a, double b){
    return a + b;
}
double sub(double a, double b){
    return a - b;
}
double mult(double a, double b){
    return a*b;
}
double divi(double a, double b){
    if (b == 0){
        printf("$: Warning: division by 0. This will return 0 as fallback.\n");
        return 0;
    }
    float test = (float) a/b;
    if (fabs(test - a/b) > 0.00001) printf("$: Warning: division will return rounded down integer value.\n");
    return a/b;
}
double power(double a, double b){
    return pow(a,b);
}
double cosinus(double a, double b)
{
    return a+cos(b);
}
double sinus(double a, double b)
{
    return a+sin(b);
}
double square_root(double a, double b)
{
    return a+sqrt(b);
}
double exponential(double a , double b)
{
    return a+exp(b);
    
}

double logarithme(double a, double b)
{
    return a+log(b);
}