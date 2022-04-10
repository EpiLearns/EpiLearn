#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// create 1 to length*length
// change list to length*length
// put 0 to error
// put 1 to correct
// put 2 to already marked

int l[26];

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
    int nb = level;
    int i = 1;
    while (i < level) // struct of the grid // <= ?
    {
        if (i%3 == 0)
        {
            length++;
        }
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

void change_color(int level)
{
	int i = 0;
	int length;
	char s[5] = "ME";
	if(level < 3)
	{
		length = 9;
	}
	else
	{
		if (level < 6)
		{
			length = 16;
		}
		else
		{
			length = 25;
		}
	}
	while (i < length)
	{
		if (l[i] == 1)
		{
			switch (i)
			{
			case 0:
				printf("1");
				break;
			case 1:
				printf("2");
				break;
			case 2:
				printf("3");
				break;
			case 3:
				printf("4");
				break;
			case 4:
				printf("5");
				break;
			case 5:
				printf("6");
				break;
			case 6:
				printf("7");
				break;
			case 7:
				printf("8");
				break;
			case 8:
				printf("9");
				break;
			case 9:
				printf("10");
				break;
			case 10:
				printf("0");
				break;
			case 11:
				printf("0");
				break;
			case 12:
				printf("0");
				break;
			case 13:
				printf("0");
				break;
			case 14:
				printf("0");
				break;
			case 15:
				printf("0");
				break;
			case 16:
				printf("0");
				break;
			case 17:
				printf("0");
				break;
			case 18:
				printf("0");
				break;
			case 19:
				printf("0");
				break;
			case 20:
				printf("0");
				break;
			case 21:
				printf("0");
				break;
			case 22:
				printf("0");
				break;
			case 23:
				printf("0");
				break;
			case 24:
				printf("0");
				break;
			default:
				break;
			}
		}
		i = i + 1;	
	}
}

int main()
{
    create_grid2(2,l);
    int i = 0;
    while (i < 25)
    {
        printf("%d ", l[i]);
        i++;
    }
    printf("\n");
    printf("\n");
    change_color(2);
   printf("\n");
    exit(EXIT_SUCCESS);
}
