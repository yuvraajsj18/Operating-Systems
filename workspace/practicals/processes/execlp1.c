#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)    // error check
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    if (pid == 0)   // child process
    {
        execlp("/mnt/DC84407A844058E2/CS/learn_cs/OS/workspace/practicals/processes/helloworld", "helloworld", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }
    

    return 0;
}

/*
Hello, World!!
Child Complete

*/

