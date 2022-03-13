#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int generate_number(int level)
{
    srand(time(NULL));
    int number = 0;
    int random = 0;
    if (level != 1)
    {
        random = rand() % 9 + 1;
        number = number*10 + random;
        level = level - 1;
    }
    while (level > 0)
    {
        random = rand() % 10;
        number = number*10 + random;
        level = level - 1;
    }
    return number;
}


void setTimeout(int milliseconds)
{
    // If milliseconds is less or equal to 0
    // will be simple return from function without throw error
    if (milliseconds <= 0) {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // a current time of milliseconds
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // needed count milliseconds of return from this timeout
    int end = milliseconds_since + milliseconds;

    // wait while until needed time comes
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}

void time_out(int time) // problem : print all seconds at the end. 
{
    int i = 1;
    while (i <= time)
    {
        printf("%d ",i);
        setTimeout(1000);
        i = i + 1;
    }

    printf("\n");
}

int number_level(int level)
{
    int r;
    //char *p;
    int n = generate_number(level);
    printf("%d\n",n);
    setTimeout(5000);
    //time_out(5);
    system("clear");
    printf("What's the number ? :\n");
    scanf ("%d",&r);
    if (r == n)
    {
        printf("good\n");
        return 1;
    }
    else
    {
        printf("wrong\n");
        return 0;
    }
}

void number_game()
{
    int life = 3;
    int i = 1;
    int correct;
    while (life > 0)
    {
        printf("Level %d\n", i);
        if (life == 1)
        {
            printf("You have %d chance left\n", life);
        }
        else
        {
            printf("You have %d chances left\n", life);
        }
        correct = number_level(i);
        if (correct)
        {
            i = i + 1;
        }
        else
        {
            life = life - 1;
        }
        setTimeout(3000);
        system("clear");
    }
    printf("Level %d reached !!\n", i);
}



/*
int main(int argc, char *argv[])
{
    number_game();
    exit(EXIT_SUCCESS);
}
*/