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
double evaluate(node* head);

double add(double a, double b);
double sub(double a, double b);
double mult(double a, double b);
double divi(double a, double b);
double power(double a, double b);


#endif