#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// create 1 to length*length
// change list to length*length
// put 0 to error
// put 1 to correct
// put 2 to already marked

int *create_grid(int level) // 0 en trop !! 
{
    srand(time(NULL));
    int length = 3;
    int nb = 3;
    int i = 1;
    while (i < level) // struct of the grid // <= ?
    {
        if (i%3 == 0)
        {
            length++;
        }
        nb++; // +1 ?
        i++;
    }

    int length_length = length*length;
    static int  l[20] = { 0 };
    static int M[16] = { 0 }; // need to use malloc
    int a = 0;
    int random;
    while (a < nb)
    {
        random = rand() % length_length + 1;
        if (l[a] == 0 && M[random] == 0)
        {
            l[a] = random;
            M[random] = 1;
            a++;
        }
    }
    
    return l;
    
}

void create_grid2(int level,  int l[]) // 0 en trop !! 
{
    int b = 0;
    while (b < 25)
    {
        l[b] = 0;
        b =b +1;
    }
    

    srand(time(NULL));
    int length = 3;
    int nb = 3;
    int i = 1;
    while (i < level) // struct of the grid // <= ?
    {
        if (i%3 == 0)
        {
            length++;
        }
        nb++; // +1 ?
        i++;
    }

    int length_length = length*length;
    int a = 0;
    int random;
    while (a < nb)
    {
        random = rand() % length_length + 1;
        if (l[random] == 0)
        {
            l[random] = 1;
            a++;
        }
    }
    
}

int main()
{
    int l[26];
    create_grid2(7,l);
    int i = 0;
    while (i < 25)
    {
        printf("%d ", l[i]);
        i++;
    }
    printf("\n");
   
    exit(EXIT_SUCCESS);
}
