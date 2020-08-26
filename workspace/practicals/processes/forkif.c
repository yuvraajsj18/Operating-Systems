#include <stdio.h>
#include <unistd.h>

int main()
{
    int id = fork();
    if (!id)
    {
        printf("Hello from the Child %d\n", id);
    }
    else
    {
        printf("Hello from the Parent %d\n", id);
    }
    
    return 0;
}

/*
    Command: gcc -o forkif forkif.c
             ./forkif
    Output:
            Hello from the Parent 18149
            Hello from the Child 0
*/