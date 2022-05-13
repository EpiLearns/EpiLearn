#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    double value;
    double (*operator) (double, double);

    struct Node* left;
    struct Node* right;
}node;

node* createNode(void);
double calculator_evaluate(node* head);

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double divi(double a, double b);
double power(double a, double b);
double cosinus(double a, double b);
double sinus (double a, double b);
double square_root(double a, double b);
double exponential(double a , double b);
double logarithme(double a, double b);


#endif