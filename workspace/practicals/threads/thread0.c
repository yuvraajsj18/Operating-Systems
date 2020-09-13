#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int sum;    // data shared between threads
void *runner(void *param); // thread call this function

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./thread0 <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_t tid;  // thread identifier
    pthread_attr_t attr; // set of thread attribute

    // get the default attributes
    pthread_attr_init(&attr);

    // create the thread
    pthread_create(&tid, &attr, runner, argv[1]);
    
    // wait for the thread to exit
    pthread_join(tid, NULL);

    printf("sum = %d\n", sum);

    return 0;
}

// The thread will begin control in this function
void *runner(void *param)
{
    int upper = atoi(param);
    sum = 0;

    for (int i = 1; i <= upper; i++)
        sum += i;

    pthread_exit(0);
}

/* ./thread0 5
sum = 15
*/
