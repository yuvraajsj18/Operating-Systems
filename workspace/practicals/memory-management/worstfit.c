#include <stdio.h>
#include <stdlib.h>

void fill_holes(int mem_holes[], int num_holes, int processes_size[], int num_processes);

int main()
{
    printf("Worst Fit Memory Allocation\n");

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

        // find any one hole number to fit
        int hole_num = -1;
        int max_difference = -1;
        for (int j = 0; j < num_holes; j++)
        {
            if (mem_holes[j] - processes_size[i] >= 0)  // find a hole with enough space
            {
                hole_num = j;
                max_difference = mem_holes[j] - processes_size[i];
                break;
            }
        }

        for (int j = 0; j < num_holes; j++) // check if there's a better hole with larger difference
        {
            if (mem_holes[j] - processes_size[i] >= 0 && mem_holes[j] - processes_size[i] > max_difference)
            {
                hole_num = j;
                max_difference = mem_holes[j] - processes_size[i];
            }
        }

        if (hole_num != -1) // if a fitting hole is found
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

/*OUTPUT:
Worst Fit Memory Allocation
Enter number of holes: 5
Enter size of hole 1: 15
Enter size of hole 2: 20
Enter size of hole 3: 10
Enter size of hole 4: 30
Enter size of hole 5: 10
Enter number of processes: 5
Enter size of process 1: 20
Enter size of process 2: 10
Enter size of process 3: 5
Enter size of process 4: 10
Enter size of process 5: 20


Process         Hole Number             Space Left
1                       4                       10
2                       2                       10
3                       1                       10
4                       1                       0
5                       No hole of enough size found

Hole Number             Space Left
1                       0
2                       10
3                       10
4                       10
5                       10
*/
