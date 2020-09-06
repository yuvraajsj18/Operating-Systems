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
        execlp("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }
    

    return 0;
}


/*
total 171
-rwxrwxrwx 1 root root 16728 Aug 26 11:03 a.out
-rwxrwxrwx 1 root root 16904 Sep  4 11:07 execlp
-rwxrwxrwx 1 root root 16904 Sep  4 11:12 execlp1
-rwxrwxrwx 1 root root   496 Sep  4 11:09 execlp1.c
-rwxrwxrwx 1 root root   422 Sep  4 11:07 execlp.c
-rwxrwxrwx 1 root root 16768 Aug 26 11:25 forkfn
-rwxrwxrwx 1 root root   464 Aug 26 12:10 forkfn.c
-rwxrwxrwx 1 root root 16736 Aug 26 12:12 forkif
-rwxrwxrwx 1 root root   386 Aug 26 12:26 forkif.c
-rwxrwxrwx 1 root root 16904 Aug 28 12:32 getPid
-rwxrwxrwx 1 root root   945 Aug 28 12:32 getPid.c
-rwxrwxrwx 1 root root 16728 Aug 26 11:04 hello
-rwxrwxrwx 1 root root   268 Sep  4 11:08 hello.c
-rwxrwxrwx 1 root root 16696 Sep  4 11:08 helloworld
-rwxrwxrwx 1 root root    81 Sep  4 11:08 helloworld.c
-rwxrwxrwx 1 root root   686 Aug 28 12:32 process-assignment-2-28-aug.txt
Child Complete

*/

