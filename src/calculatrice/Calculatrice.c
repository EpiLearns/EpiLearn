#include <stdio.h>
#include <stdlib.h>
#include "Calculatrice.h"

int findpivot(const char* chain,int size)
{
    int i,nbparent,res;
    nbparent = 0;
    res = -1;
    for(i=0;i<size;i++)
    {
        if (chain[i]=='(')
            nbparent++;
        if (chain[i]==')')
            nbparent--;
        if (nbparent==0)
        {
            if (chain[i]=='+' || chain[i]=='-')
                return i;
            if (chain[i]=='*' || chain[i]=='/' || chain[i] == '^' || chain[i] == '.')
                res = i;
        }
    }
    return res;
}

int power(int a, int b)
{
    int res = a; 
    switch(b)
    { 
        case 1:
            return a;
        case 0:
            return res;
        default:
            break;
    }
    while (b > 1)
    {
        res = res*a;
        b--;
        
    }
    return res;
}

double calculR(const char* chain,int size, int x)
 

{
    int pos;
    double op1,op2;
    int j = 0;
    if (chain[0]=='(' && chain[size-1]==')')
        { 
            //printf("étape : %i\n",x);
            return calculR(chain+1,size-2,x+1);
        }
                        
    pos = findpivot(chain,size);
    if (pos==-1)
    { 
        //printf("étape : %i\n",x);
        return atoi(chain);
    }
    op1 = calculR(chain,pos,x+1);
    op2 = calculR(chain+pos+1,size-pos-1,x+1);
    switch(chain[pos])
    {
    case '.':
        while( (int)op2%10 != 0)
        {
            (op2 = op2/10);
        }
        return op1+ (op2);        
    case '+':
        //printf("étape : %i\n",x);
        //printf("%.9g + %.9g\n" ,op1,op2);
        return op1+op2;
    case '-':
        //printf("étape : %i\n",x);
        //printf("%.9g - %.9g\n" ,op1,op2);
        return op1-op2;
    case '*':
        //printf("étape : %i\n",x);
        //printf("%.9g * %.9g\n" ,op1,op2);
        return op1*op2;
    case '/':
        //printf("étape : %i\n",x);
        //printf("%.9g / %.9g\n" ,op1,op2);
        return op1/op2;
    case '^':
        //printf("étape : %i\n",x);
        //printf("%.9g ^ %.9g\n" ,op1,op2);
        return power(op1,op2);
    default:
        break;
    }
    assert(0);
    return 0;
}
 
double calcul(const char* chain)
{
    return calculR(chain,strlen(chain),0);
}
 

void decimal(int d, double res)
{
    switch (d)
    {
    case 1:
        printf("%.1g\n", res);
        break;
    case 2:
        printf("%.2g\n", res);
        break;
    case 3:
        printf("%.3g\n", res);
        break;
    case 4:
        printf("%.4g\n", res);
        break;
    case 5:
        printf("%.5g\n", res);
        break;
    case 6:
        printf("%.6g\n", res);
        break;
    case 7:
        printf("%.7g\n", res);
        break;
    case 8:
        printf("%.8g\n", res);
        break;
    case 9:
        printf("%.9g\n", res);
        break;
    default:
        printf("%d\n", (int)res);
        break;
    }
}

int main()
{    
    const char* chain = " ";

    char operation[20] = {0};
    int d = 0;

    printf("how many digits after the decimal point ? \n");
    scanf("%i", &d);

    printf("Please enter an operation \n");
    scanf("%s",operation);
    
    chain = operation;
    
    double res = calcul(chain);
    
    decimal(9,res);
    return 0;
}