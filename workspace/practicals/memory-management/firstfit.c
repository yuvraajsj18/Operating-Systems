#include <stdio.h>
#include <stdlib.h>

void fill_holes(int mem_holes[], int num_holes, int processes_size[], int num_processes);

int main()
{
    printf("First Fit Memory Allocation\n");

    int num_holes;
    printf("Enter number of holes: ");
    scanf("%d", &num_holes);

    int *mem_holes = malloc(sizeof(int) * num_holes);

    // input hole's size
    for (int i = 0; i < num_holes; i++)
    {
        printf("Enter size of hole %d: ", i + 1);
        scanf("%d", &mem_holes[i]);
    }

    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    int *processes_size = malloc(sizeof(int) * num_processes);
    
    // input process's size
    for (int i = 0; i < num_processes; i++)
    {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processes_size[i]);
    }

    fill_holes(mem_holes, num_holes, processes_size, num_processes);

    return 0;
}

void fill_holes(int mem_holes[], int num_holes, int processes_size[], int num_processes)
{
    printf("\n\nProcess\t\tHole Number\t\tSpace Left\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t\t", i + 1);    // Process number

        // find hole number to fit
        int hole_num = -1;
        for (int j = 0; j < num_holes; j++)
            if (mem_holes[j] >= processes_size[i])
            {
                hole_num = j;
                break;
            }

        if (hole_num != -1)
        {
            printf("%d\t\t\t", hole_num + 1);    // Hole Number

            mem_holes[hole_num] = mem_holes[hole_num] - processes_size[i];    // find space left
            printf("%d\n", mem_holes[hole_num]);   // space left
        }
        else
            printf("No hole of enough size found\n");
    }

    printf("\nHole Number\t\tSpace Left\n");
    for (int i = 0; i < num_holes; i++)
        printf("%d\t\t\t%d\n", i + 1, mem_holes[i]);
}

/* OUTPUT:
First Fit Memory Allocation
Enter number of holes: 5
Enter size of hole 1: 20
Enter size of hole 2: 10
Enter size of hole 3: 20
Enter size of hole 4: 10
Enter size of hole 5: 20
Enter number of processes: 5
Enter size of process 1: 10
Enter size of process 2: 20
Enter size of process 3: 5
Enter size of process 4: 30
Enter size of process 5: 10


Process         Hole Number             Space Left
1                       1                       10
2                       3                       0
3                       1                       5
4                       No hole of enough size found
5                       2                       0

Hole Number             Space Left
1                       5
2                       0
3                       0
4                       10
5                       20
*/
