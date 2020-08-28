#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int id = fork();

    int pid = getpid();
    int ppid = getppid();

    if (!id)    // Child
    {
        printf("\nI'm the child, my id is %d\n", pid);
        printf("I'm the child, my parent id is %d\n", ppid);
    }
    else    // Parent
    {
        printf("\nI'm in parent, this command is before wait\n");
        printf("I'm the parent, my id is %d\n", pid);
        printf("I'm the parent, my parent id is %d\n", ppid);
        printf("I'm the parent my child id is %d\n", id);

        wait(NULL);
        printf("I'm in parent, this command is after wait\n");
    }
    
    return 0;
}

/*

I'm in parent, this command is before wait
I'm the parent, my id is 19157
I'm the parent, my parent id is 11148
I'm the parent my child id is 19158

I'm the child, my id is 19158
I'm the child, my parent id is 19157
I'm in parent, this command is after wait
*/