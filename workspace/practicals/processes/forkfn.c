#include <stdio.h>
#include <unistd.h>

void makeFork(int num);

int main()
{
    makeFork(50);

    return 0;
}

void makeFork(int num)
{
    if (!fork())
    {
        printf("Value of num in Child is %d\n", ++num);
    }
    else
    {
        printf("Value of num in Parent is %d\n", --num);
    }
}

/*
    Command: gcc -o forkfn forkfn.c
            ./forkfn
        Output:
            Value of num in Parent is 49
            Value of num in Child is 51
*/