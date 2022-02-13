
   
#include <stdio.h>
#include <stdlib.h>
#include "Calculatrice.h"

int findpivot(const char* chaine,int size)
{
    int i,nbparent,res;
    nbparent = 0;
    res = -1;
    for(i=0;i<size;i++)
    {
        if (chaine[i]=='(')
            nbparent++;
        if (chaine[i]==')')
            nbparent--;
        if (nbparent==0)
        {
            if (chaine[i]=='+' || chaine[i]=='-')
                return i;
            if (chaine[i]=='*' || chaine[i]=='/' || chaine[i] == '^' || chaine[i] == '.')
                res = i;
                
                
        }
                
        
    }
    return res;
}

int sign(const char* chaine,int size)
{
    int i,nbparent,res;
    nbparent = 0;
    res = -1;
    for(i=0;i<size;i++)
    {
        if (chaine[i]=='(')
            nbparent++;
        if (chaine[i]==')')
            nbparent--;
        if (nbparent==0)
        {
            if (chaine[i]=='+' || chaine[i]=='-' || chaine[i]=='*' || chaine[i]=='/')
                return i;
        }
    }
    
    return nbparent;
}


int puissance(int a, int b)
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

double calculR(const char* chaine,int size, int x)
 

{
    int pos;
    double op1,op2;
    int j = 0;
    if (chaine[0]=='(' && chaine[size-1]==')' && sign(chaine, size) == 0 )
        { 
            //printf("étape : %i\n",x);
            return calculR(chaine+1,size-2,x+1);
        }
                        
    pos = findpivot(chaine,size);
    if (pos==-1)
    { 
        //printf("étape : %i\n",x);
        return atoi(chaine);
    }
    op1 = calculR(chaine,pos,x+1);
    op2 = calculR(chaine+pos+1,size-pos-1,x+1);
    switch(chaine[pos])
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
        return puissance(op1,op2);
    default:
        break;
    }
    assert(0);
    return 0;
}
 
double calcul(const char* chaine)
{
    return calculR(chaine,strlen(chaine),0);
}
 

void decimal(int d, double res)
{
    switch (d)
    {
    case 1:
        printf("%.2g\n", res);
        break;
    case 2:
        printf("%.3g\n", res);
        break;
    case 3:
        printf("%.4g\n", res);
        break;
    case 4:
        printf("%.5g\n", res);
        break;
    case 5:
        printf("%.6g\n", res);
        break;
    case 6:
        printf("%.7g\n", res);
        break;
    case 7:
        printf("%.8g\n", res);
        break;
    case 8:
        printf("%.9g\n", res);
        break;
    case 9:
        printf("%.10g\n", res);
        break;
    default:
        printf("%.1g\n", res);
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
    
    decimal(d,res);
    return 0;
}

