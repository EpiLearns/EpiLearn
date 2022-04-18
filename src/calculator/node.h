#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    double value;
    double (*operator) (double, double);

    struct Node* left;
    struct Node* right;
}node;

node* calculator_createNode(void);
double calculator_evaluate(node* head);

double calculator_add(double a, double b);
double calculator_sub(double a, double b);
double calculator_mult(double a, double b);
double calculator_divi(double a, double b);
double calculator_power(double a, double b);


#endif