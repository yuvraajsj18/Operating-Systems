// Non premptive priority scheduling
#include <stdio.h>

typedef struct process
{
    int id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} process;

void sort_processes_priority(process processes[], int num_process);
void set_WT_TT(process processes[], int num_processes);
float get_avg_TT(process processes[], int num_processes);
float get_avg_WT(process processes[], int num_processes);

int main()
{
    int num_processes;
    printf("Non-premptive Priority Scheduling\n");
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    process processes[num_processes];

    printf("Enter burst time and priority(rank wise) for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("\tBurst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("\tPriority: ");
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
        processes[i].turnaround_time = processes[i].waiting_time = 0;
    }

    sort_processes_priority(processes, num_processes);

    printf("Order of execution: ");
    for (int i = 0; i < num_processes; i++)
        printf("P%d ", processes[i].id);
    printf("\n");

    set_WT_TT(processes, num_processes);

    printf("Process No\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n", processes[i].id , processes[i].waiting_time, processes[i].turnaround_time);
    }

    float avgWT = get_avg_WT(processes, num_processes);
    float avgTT = get_avg_TT(processes, num_processes);

    printf("Average waiting time: %f\n", avgWT);
    printf("Average turnaround time: %f\n", avgTT);

    return 0;
}

void set_WT_TT(process processes[], int num_processes)
{
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].waiting_time + processes[0].burst_time;
    for (int i = 1; i < num_processes; i++)
    {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void sort_processes_priority(process processes[], int num_process)
{
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < num_process - 1; i++)
        {
            if (processes[i].priority > processes[i + 1].priority)
            {
                process temp = processes[i];
                processes[i] = processes[i + 1];
                processes[i + 1] = temp;
                swapped = 1;
            }
        }
        num_process--;
    } while (swapped == 1);
    
}

float get_avg_TT(process processes[], int num_processes)
{
    float sum_TT = 0.0;
    for (int i = 0; i < num_processes; i++)
    {
        sum_TT += processes[i].turnaround_time;
    }
    float avg_TT = sum_TT / (float)num_processes;
    return avg_TT;
}

float get_avg_WT(process processes[], int num_processes)
{
    float sum_WT = 0.0;
    for (int i = 0; i < num_processes; i++)
    {
        sum_WT += processes[i].waiting_time;
    }
    float avg_WT = sum_WT / (float) num_processes;
    return avg_WT;
}

/*
Non-premptive Priority Scheduling
Enter number of processes: 5
Enter burst time and priority(rank wise) for each process:
Process 1:
        Burst Time: 2
        Priority: 2
Process 2:
        Burst Time: 1
        Priority: 1
Process 3:
        Burst Time: 8
        Priority: 4
Process 4:
        Burst Time: 4
        Priority: 2
Process 5:
        Burst Time: 5
        Priority: 3
Order of execution: P2 P1 P4 P5 P3 
Process No              Waiting Time            Turnaround Time
2                       0                       1
1                       1                       3
4                       3                       7
5                       7                       12
3                       12                      20
Average waiting time: 4.600000
Average turnaround time: 8.600000
*/

