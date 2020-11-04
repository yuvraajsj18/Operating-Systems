#include <stdio.h>

typedef struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} process;

int set_WT_TT(process processes[], int num_processes, int order[], int time_quantum);
float get_avg_TT(process processes[], int num_processes);
float get_avg_WT(process processes[], int num_processes);

int main()
{
    printf("Round Robin Scheduling\n");
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    process processes[num_processes];

    int time_quantum;
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("\tArrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("\tBurst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].waiting_time = processes[i].turnaround_time = 0;
    }

    int order[30];
    int order_size = set_WT_TT(processes, num_processes, order, time_quantum);

    printf("Result:\n");
    printf("Order of execution: ");
    for (int i = 0; i < order_size; i++)
        printf("P%d ", order[i]);
    printf("\n");

    printf("Process No.\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n", processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    float avgWT = get_avg_WT(processes, num_processes);
    float avgTT = get_avg_TT(processes, num_processes);

    printf("Average waiting time: %f\n", avgWT);
    printf("Average turnaround time: %f\n", avgTT);

    return 0;
}

int set_WT_TT(process processes[], int num_processes, int order[], int time_quantum)
{
    int burst_time[num_processes];  // save burst time
    for (int i = 0; i < num_processes; i++)
        burst_time[i] = processes[i].burst_time;

    int last = 0;   // last process executed in order of execution

    // calculate turnaround time
    int processes_completed = 0;
    int time = 0;

    process *running_process;
    int i = 0;
    while (processes[i++].arrival_time != 0);
    running_process = &processes[i - 1]; 

    int last_exit_time = 0;
    while (processes_completed != num_processes)
    {
        running_process->burst_time--;
        time++;
        
        if (last == 0)
            order[last++] = running_process->id;
        else if (order[last-1] != running_process->id)
            order[last++] = running_process->id;

        if (running_process->burst_time == 0)
        {
            processes_completed++;
            running_process->turnaround_time = time - running_process->arrival_time;
        }

        if ((time - last_exit_time) % time_quantum == 0 || running_process->burst_time == 0)
        {
            int next_process = running_process->id % num_processes;
            while (processes[next_process].arrival_time <= time && processes[next_process].burst_time == 0 && processes_completed != num_processes)
                next_process = (next_process + 1) % num_processes;

            running_process = &processes[next_process];
            last_exit_time = time;
        }
    }

    // calculate waiting time
    for (int i = 0; i < num_processes; i++)
        processes[i].waiting_time = processes[i].turnaround_time - burst_time[i];

    return last;
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
Round Robin Scheduling
Enter number of processes: 4
Enter Time Quantum: 2
Enter burst time for each process:
Process 1:
        Arrival Time: 0
        Burst Time: 5
Process 2:
        Arrival Time: 1
        Burst Time: 4
Process 3:
        Arrival Time: 2
        Burst Time: 2
Process 4:
        Arrival Time: 3
        Burst Time: 1
Result:
Order of execution: P1 P2 P3 P4 P1 P2 P1 
Process No.             Waiting Time            Turnaround Time
1                       7                       12
2                       6                       10
3                       2                       4
4                       3                       4
Average waiting time: 4.500000
Average turnaround time: 7.500000
*/

