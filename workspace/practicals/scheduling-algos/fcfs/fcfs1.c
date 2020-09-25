#include <stdio.h>

typedef struct process
{
    int process_no;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void set_WT_TT(process processes[], int num_of_processes);
float get_avg_TT(process processes[], int num_of_processes);
float get_avg_WT(process processes[], int num_of_processes);
void sort_processes_arrival(process processes[], int num_of_processes);

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
        processes[i].process_no = i;
        // set TT and WT to 0 initially
        processes[i].turnaround_time = processes[i].waiting_time = 0;
    }

    sort_processes_arrival(processes, num_of_processes);

    set_WT_TT(processes, num_of_processes);

    printf("\nResult:\n");

    printf("Order of execution: ");
    for (int i = 0; i < num_of_processes; i++)
        printf("Process %d, ", processes[i].process_no + 1);
    printf("\n");

    printf("Process No.\t\tWaiting Time\t\tTurnaround Time\n");
    for (int i = 0; i < num_of_processes; i++)
    {
        printf("%d\t\t\t%d\t\t\t%d\n", processes[i].process_no + 1, processes[i].waiting_time, processes[i].turnaround_time);
    }

    float avgTT = get_avg_TT(processes, num_of_processes);
    float avgWT = get_avg_WT(processes, num_of_processes);

    printf("Average waiting time is %f\n", avgWT);
    printf("Average turnaround time is %f\n", avgTT);

    return 0;
}

void set_WT_TT(process processes[], int num_of_processes)
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

void sort_processes_arrival(process processes[], int num_of_processes)
{
    int swapped;
    do
    {
        swapped = 0;
        for (int i = 0; i < num_of_processes - 1; i++)
        {
            if (processes[i].arrival_time > processes[i + 1].arrival_time)
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
Enter arrival time and burst time for each process:
Process 1
    Arrival time: 3
    Burst time: 5
Process 2
    Arrival time: 1
    Burst time: 4
Process 3
    Arrival time: 2
    Burst time: 9
Process 4
    Arrival time: 0
    Burst time: 8

Result:
Order of execution: Process 4, Process 2, Process 3, Process 1, 
Process No.             Waiting Time            Turnaround Time
1                       0                       8
2                       7                       11
3                       10                      19
4                       18                      23
Average waiting time is 8.750000
Average turnaround time is 15.250000
*/
