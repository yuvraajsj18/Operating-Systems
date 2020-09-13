#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* sum_of_n(void* param);
void* sum_of_sq(void* param);

int sum_n;
int sum_sq;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: ./thread1 <integer value> <integer value>\n");
        return -1;
    }

    if (atoi(argv[1]) < 0 || atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_t tid0;
    pthread_attr_t attr0;

    pthread_attr_init(&attr0);
    pthread_create(&tid0, &attr0, sum_of_n, argv[1]);

    pthread_t tid1;
    pthread_attr_t attr1;

    pthread_attr_init(&attr1);
    pthread_create(&tid1, &attr1, sum_of_sq, argv[2]);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    printf("Sum of n = %d\n", sum_n);
    printf("Sum of squares = %d\n", sum_sq);

    return 0;
}

void* sum_of_n(void* param)
{
    int upper = atoi(param);
    sum_n = 0;
    for (int i = 1; i <= upper; i++)
        sum_n += i;

    pthread_exit(0);
}

void* sum_of_sq(void* param)
{
    int upper = atoi(param);
    sum_sq = 0;
    for (int i = 1; i <= upper; i++)
        sum_sq += i * i;

    pthread_exit(0);
}

/* ./thread1 2 3
Sum of n = 3
Sum of squares = 14
*/

