#include <stdlib.h>
#include <time.h>
#include <stdio.h>


void create_grid(int level, int l[])
{
    srand(time(NULL));
    int length;
    int random;
    if (level < 3 )
    {
        length = 9;
    }
    else
    {
        length = 16;
    }
    int check[length];
    int i = 0;
    while (i < level)
    {
        random = rand() % level;
        if (check[random] != 1)
        {
            check[random] = 1;
            l[i] = random;
            i = i + 1;
        }
        
    }
}

int main()
{
    int l[20];
    create_grid(3,l);
    int i = 0;
    while (i < 9)
    {
        printf("%d\n", l[i]);
        i = i + 1;
    }
    
    exit(EXIT_SUCCESS);
}