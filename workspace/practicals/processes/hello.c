#include <stdio.h>
// #include <sys/types.h>
#include <unistd.h>

int main()
{
    fork();

    printf("Hello, World!!\n");

    return 0;
}

/*
    Command: gcc -o hello hello.c
            ./hello
    Output:
            Hello, World!!
            Hello, World!!
*/
