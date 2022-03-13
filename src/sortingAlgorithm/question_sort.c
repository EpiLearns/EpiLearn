#include <stdio.h>
#include <stdlib.h>
#include "question_sort.h"

void bubble_sorting(struct question T[], int N)
{
    struct question c;
    int i,j,k;

    for(i=1;i<N;i++) 
    {

        if ( &T[i].difficulty > &T[i-1].difficulty ) 
        { // if the element is misplaced

            j = 0;

            while ( T[j].difficulty > T[i].difficulty ) j++; // this loop exits with j = the new position of the element
 
            c = T[i]; // these 2 lines are used to translate the cells forward in order to insert the element at its new position
            for( k = i-1 ; k >= j ; k-- ) T[k+1] = T[k];
            T[j] = c; // insertion
        }
    }
}

int main()
{
    question q[7];
    int len = 7;
    q[0].difficulty = 5;
    q[0].name = "question_1";
    q[1].difficulty = 3;
    q[1].name = "question_2";
    q[2].difficulty = 1;
    q[2].name = "question_3";
    q[3].difficulty = 3;
    q[3].name = "question_4";
    q[4].difficulty = 4;
    q[4].name = "question_5";
    q[5].difficulty = 6;
    q[5].name = "question_6";
    q[6].difficulty = 2;
    q[6].name = "question_7";

    for( int i = 0; i < len; i ++)
    {
        printf("q[%d] = (%d,%s)\n", i,q[i].difficulty, q[i].name);
    }
    
    printf("============================================\n");
    bubble_sorting(q, 7);
    
    for( int i = 0; i < len; i ++)
    {
        printf("q[%d] = (%d,%s)\n", i,q[i].difficulty, q[i].name);
    }
    return 0;
}

