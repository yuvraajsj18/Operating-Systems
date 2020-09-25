// Shortest job first - non premptive, without arrival time

#include <stdio.h>

typedef struct process
{
    int process_no;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void set_WT_TT(process processes[], int num_of_processes);
void sort_processes_burst(process processes[], int num_of_processes);

int main()
{
    int num_of_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_of_processes);

    process processes[num_of_processes];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < num_of_processes; i++)
    {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_no = i;
        processes[i].waiting_time = processes[i].turnaround_time = 0;
    }

    sort_processes_burst(processes, num_of_processes);

    printf("Order of execution: ");
    for (int i = 0; i < num_of_processes; i++)
        printf("Process %d, ", processes[i].process_no + 1);
    printf("\n");

    set_WT_TT(processes, num_of_processes);

    printf("Process No\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < num_of_processes; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n", processes[i].process_no + 1, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}

// set waiting time and turnaround time of processes, after sorting
void set_WT_TT(process processes[], int num_of_processes)
{
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    for (int i = 1; i < num_of_processes; i++)
    {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// sort processes on the basis of burst time
void sort_processes_burst(process processes[], int num_of_processes)
{
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < num_of_processes - 1; i++)
        {
            if (processes[i].burst_time > processes[i + 1].burst_time)
            {
                process temp = processes[i];
                processes[i] = processes[i + 1];
                processes[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

/*
Enter number of processes: 4
Enter burst time for each process:
Process 1 burst time: 6
Process 2 burst time: 8
Process 3 burst time: 7
Process 4 burst time: 3
Order of execution: Process 4, Process 1, Process 3, Process 2, 
Process No              Waiting Time            Turnaround Time
4                       0                       3
1                       3                       9
3                       9                       16
2                       16                      24
*/
