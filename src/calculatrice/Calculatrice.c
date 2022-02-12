#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

 
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
            if (chaine[i]=='*' || chaine[i]=='/' || chaine[i] == '^')
                res = i;
        }
    }
    return res;
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



int calculR(const char* chaine,int size)
{
    int pos,op1,op2;
    if (chaine[0]=='(' && chaine[size-1]==')')
        return calculR(chaine+1,size-2);
    pos = findpivot(chaine,size);
    if (pos==-1)
    { 
        return atoi(chaine);
    }
    op1 = calculR(chaine,pos);
    op2 = calculR(chaine+pos+1,size-pos-1);
    switch(chaine[pos])
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    case '^':
        return puissance(op1,op2);
    default:
        break;
    }
    assert(0);
    return 0;
}
 
int calcul(const char* chaine)
{
    return calculR(chaine,strlen(chaine));
}
 
int main()
{
    int res = calcul("(2+3)*2");
    printf("%d\n",res);
    return 0;
}