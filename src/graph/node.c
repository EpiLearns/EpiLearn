#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>



node* graph_createNode(void){
    node* out = malloc(sizeof(node));
    out->left = NULL;
    out->right = NULL;
    out->operator = NULL;
    out->value = 0;
    return out; 
}

double graph_evaluate(node* head){
    if(head == NULL) return 0;
    
    //graph_evaluate operator first, value only if operator is null
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
        return operator(graph_evaluate(left), graph_evaluate(right));
    }
}

double graph_add(double a, double b){
    return a + b;
}
double graph_sub(double a, double b){
    return a - b;
}
double graph_mult(double a, double b){
    return a*b;
}
double graph_divi(double a, double b){
    if (b == 0){
        printf("$: Warning: graph_division by 0. This will return 0 as fallback.\n");
        return 0;
    }
    float test = (float) a/b;
    if (fabs(test - a/b) > 0.00001) printf("$: Warning: graph_division will return rounded down integer value.\n");
    return a/b;
}
double graph_power(double a, double b){
    return pow(a,b);
}
