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
        execlp("/bin/ls", "ls", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }
    

    return 0;
}


/*
a.out   execlp0    execlp1    execlp.c  forkfn.c  forkif.c  getPid.c  hello.c     helloworld.c                     temp
execlp  execlp0.c  execlp1.c  forkfn    forkif    getPid    hello     helloworld  process-assignment-2-28-aug.txt
Child Complete

*/

