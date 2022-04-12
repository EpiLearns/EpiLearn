#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "question_sort.h"

void bubble_sorting(struct question T[], int N)
{
    struct question c;
    int i,j;

    for(j=1;j<=N;j++)
    {     
        for(i=0;i<N-1;i++)
        { 
            if ( T[i].difficulty > T[i+1].difficulty ) 
            {
                c = T[i];
                T[i] = T[i+1];
                T[i+1] = c;
            }
        }  
    }      
}

int answer(struct question T[], char *a[], size_t len)
{
    int res = 0;
    
    for (size_t i = 0; i< len; i++)
    {
        int tmp = 0;
        tmp = strcmp(T[i].answer,a[i]);
        if (tmp != 0)
        {
            res = tmp;
        }
    }
    
    return res;

}



size_t count(struct question T[], int d, size_t len)
{
    size_t i = 0;
    size_t count = 0;
    while (i < len &&T[i].difficulty <=  d)
    {
        if (T[i].difficulty <= d)
        {
            count++;
        }
        i++;

    }
    return count;
}

struct question give(struct question T[], int difficulty, size_t len, struct question res[])
{
    size_t i = 0;
    size_t j = 0;
    while (i < len )
    {
        if (T[i].difficulty <= difficulty)
        {
            res[j] = T[i];
            j++;
        }
        i++;
    }
    return *res;
}

int launch(struct question q[], int lvl)
{
    bubble_sorting(q,7);
    size_t c = count(q,lvl,7);
    char *rep[7];
    struct question *res = calloc(c, sizeof(question));
    give(q,lvl,7,res);
    for (size_t i = 0; i < c; i++)
    {   
        char *a = malloc(sizeof(char*));
        printf("res[%li] = %s\n", i, res[i].question);
        scanf("%s", a);
        rep[i] = a;
    }
    if(answer(res,rep,c) == 0)
    {
        lvl++;
        printf("your level: %i\n", lvl);
        printf("correct result\n");
    }
    else
    {
        printf("bad result\n");
    }
        
    
    
    free(res);
    return lvl;

}

int main()
{
    struct question *q = calloc(7, sizeof(question));
    struct student thomas;
    thomas.level = 0;
    int continu = 0;
    
    q[0].difficulty = 0;
    q[0].question = "combien font 2*2\n";
    q[0].answer = "4";
    q[1].difficulty = 5;
    q[1].question = "quel est la primitive de sin(x)\n";
    q[1].answer = "-cos(x)";
    q[2].difficulty = 1;
    q[2].question = "2^2 + 4\n";
    q[2].answer = "8";
    q[3].difficulty = 5;
    q[3].question = "dérivé de cos(x)\n";
    q[3].answer = "-sin(x)";
    q[4].difficulty = 4;
    q[4].question = "donnez la formule de la dérivé de uv\n";
    q[4].answer = "u'v+uv'";
    q[5].difficulty = 2;
    q[5].question = "primitive de x\n";
    q[5].answer = "x^2/2";
    q[6].difficulty = 6;
    q[6].question = "formule intégrale par partie (mettre I pour intégrale)\n";
    q[6].answer = "[uv] - I(uv')";
    

    printf("your level : %i\n", thomas.level);
    while(continu == 0)
    {
        thomas.level = launch(q,thomas.level);
        printf("your level : %i\n", thomas.level);
        printf("Would you continue? Yes \n");
        char *a = malloc(sizeof(char));
        scanf("%s",a);

        if(strcmp(a,"Yes") != 0)
        {
            continu = 1;
        }

    }
    return 0;
    


}

