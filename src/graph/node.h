#ifndef NODE_H
#define NODE_H

typedef struct Node
{
    double value;
    double (*operator) (double, double);

    struct Node* left;
    struct Node* right;
}node;

node* graph_createNode(void);
double graph_evaluate(node* head);

double graph_add(double a, double b);
double graph_sub(double a, double b);
double graph_mult(double a, double b);
double graph_divi(double a, double b);
double graph_power(double a, double b);

#endif