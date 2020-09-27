// Premptive Priority Scheduling

#include <stdio.h>

typedef struct process
{   
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} process;

int set_WT_TT(process processes[], int num_processes, int order[]);
process* choose_process(process processes[], int num_processes, int time);
float get_avg_TT(process processes[], int num_processes);
float get_avg_WT(process processes[], int num_processes);

int main()
{
    printf("Premptive Priority Scheduling\n");
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    process processes[num_processes];

    printf("Enter arrival time, burst time, and priority for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("\tArrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("\tBurst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("\tPriority: ");
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
        processes[i].waiting_time = processes[i].turnaround_time = 0;
    }

    int order[30];
    int order_size = set_WT_TT(processes, num_processes, order);

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

int set_WT_TT(process processes[], int num_processes, int order[])
{
    int burst_time[num_processes];  // save burst time
    for (int i = 0; i < num_processes; i++)
        burst_time[i] = processes[i].burst_time;

    int last = 0;   // last process executed in order of execution

    // calculate turnaround time
    int processes_completed = 0;
    int time = 0;
    while (processes_completed != num_processes)
    {
        // choose process to run at time 'time'
        process *running_process = choose_process(processes, num_processes, time); 
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
    }

    // calculate waiting time
    for (int i = 0; i < num_processes; i++)
        processes[i].waiting_time = processes[i].turnaround_time - burst_time[i];

    return last;
}

process* choose_process(process processes[], int num_processes, int time)
{   
    process* to_run;

    // select first process without bt = 0
    for (int i = 0; i < num_processes; i++)
        if (processes[i].burst_time != 0)
        {
            to_run = &processes[i];
            break;
        }

    for (int i = 0; i < num_processes; i++)
    {
        if (processes[i].arrival_time <= time && processes[i].burst_time > 0)
        {
            if (processes[i].priority < to_run->priority)
                to_run = &processes[i];
        }
    }
    return to_run;
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
Premptive Priority Scheduling
Enter number of processes: 4
Enter arrival time, burst time, and priority for each process:
Process 1:
        Arrival Time: 0
        Burst Time: 5
        Priority: 2
Process 2:
        Arrival Time: 2
        Burst Time: 3
        Priority: 1
Process 3:
        Arrival Time: 5
        Burst Time: 6
        Priority: 3
Process 4:
        Arrival Time: 6
        Burst Time: 2
        Priority: 4
Result:
Order of execution: P1 P2 P1 P3 P4 
Process No.             Waiting Time            Turnaround Time
1                       3                       8
2                       0                       3
3                       3                       9
4                       8                       10
Average waiting time: 3.500000
Average turnaround time: 7.500000
*/
