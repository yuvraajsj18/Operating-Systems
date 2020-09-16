#include <stdio.h>

typedef struct process
{
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void set_WT_BT(process processes[], int num_of_processes);
float get_avg_TT(process processes[], int num_of_processes);
float get_avg_WT(process processes[], int num_of_processes);

int main()
{
    int num_of_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_of_processes);

    process processes[num_of_processes];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < num_of_processes; i++)
    {
        printf("Process %d\n", i + 1);
        printf("    Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("    Burst time: ");
        scanf("%d", &processes[i].burst_time);
        // set TT and WT to 0 initially
        processes[i].turnaround_time = processes[i].waiting_time = 0;
    }

    set_WT_BT(processes, num_of_processes);

    printf("Result:\n");
    for (int i = 0; i < num_of_processes; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("   Arrival Time: %d\n", processes[i].arrival_time);
        printf("   Burst Time: %d\n", processes[i].burst_time);
        printf("   Waiting Time: %d\n", processes[i].waiting_time);
        printf("   Turnaround Time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }

    float avgTT = get_avg_TT(processes, num_of_processes);
    float avgWT = get_avg_WT(processes, num_of_processes);

    printf("Average waiting time is %f\n", avgWT);
    printf("Average turnaround time is %f\n", avgTT);

    return 0;
}

void set_WT_BT(process processes[], int num_of_processes)
{
    // init first process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].waiting_time + processes[0].burst_time;

    // eval other processes
    for (int i = 1; i < num_of_processes; i++)
    {
        processes[i].waiting_time = processes[i - 1].turnaround_time + processes[i - 1].arrival_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}


float get_avg_TT(process processes[], int num_of_processes)
{
    float sum_TT = 0.0;
    for (int i = 0; i < num_of_processes; i++)
    {
        sum_TT += processes[i].turnaround_time;
    }
    float avg_TT = sum_TT / (float)num_of_processes;
    return avg_TT;
}
float get_avg_WT(process processes[], int num_of_processes)
{
    float sum_WT = 0.0;
    for (int i = 0; i < num_of_processes; i++)
    {
        sum_WT += processes[i].waiting_time;
    }
    float avg_WT = sum_WT / (float) num_of_processes;
    return avg_WT;
}



