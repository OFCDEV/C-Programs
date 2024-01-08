#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int end_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};
void fcfs_schedule(struct Process *processes, int num_processes);
void rr_schedule(struct Process *processes, int num_processes, int time_quantum);
int main()
{
    int num_processes, choice, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct Process *processes = (struct Process *)malloc(num_processes * sizeof(struct Process));
    printf("Enter process details:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time =
            processes[i].burst_time;
    }

    do
    {
        printf("\nChoose a scheduling policy:\n");
        printf("1. First Come First Served (FCFS)\n");
        printf("2. Round Robin (RR)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fcfs_schedule(processes, num_processes);
            break;
        case 2:
            printf("Enter the time quantum for Round Robin: .");
            scanf("%d", &time_quantum);
            rr_schedule(processes, num_processes,
                        time_quantum);
            break;
        case 3:
            printf("Exiting from the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);
    free(processes);
    return 0;
}
void fcfs_schedule(struct Process *processes, int num_processes)
{
    int total_waiting_time = 0, total_turnaround_time = 0,
        total_response_time = 0;
    // Sort processes based on arrival time
    for (int i = 0; i < num_processes - 1; i++)
    {
        for (int j = i + 1; j < num_processes; j++)
        {
            if (processes[i].arrival_time >
                processes[j].arrival_time)
            { // Swap processes
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    // FCFS scheduling logic
    for (int i = 0; i < num_processes; i++)
    {
        if (i == 0 || processes[i].arrival_time > processes[i - 1].end_time)
        {
            processes[i].start_time =
                processes[i].arrival_time;
        }
        else
        {
            processes[i].start_time = processes[i - 1].end_time;
        }
        processes[i].end_time = processes[i].start_time +
                                processes[i].burst_time;
        processes[i].waiting_time = processes[i].start_time -
                                    processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;
        processes[i].response_time = processes[i].start_time - processes[i].arrival_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time +=
            processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
        printf("P%d: %d-%d\t", processes[i].process_id,processes[i].start_time, processes[i].end_time);
    }
    // Calculate averages
    double avg_waiting_time = (double)total_waiting_time / num_processes;
    double avg_turnaround_time =
        (double)total_turnaround_time / num_processes;
    double avg_response_time = (double)total_response_time / num_processes;
    num_processes;
    // Display averages 
    printf("\nAverage Waiting Time: %.2lf\n",
avg_waiting_time);
printf("Average Turnaround Time: %.2lf\n",
       avg_turnaround_time);
printf("Average Response Time: %.2lf\n",
       avg_response_time);
}
void rr_schedule(struct Process *processes, int num_processes, int time_quantum)
{
    int total_waiting_time = 0, total_turnaround_time = 0,
        total_response_time = 0;
    // RR scheduling logic 
    int *remaining_time = (int *)malloc(num_processes *
sizeof(int));
for (int i = 0; i < num_processes; i++)
{
    remaining_time[i] = processes[i].burst_time;
}
printf("Round Robin Schedule (Time Quantum: %d):\n",
       time_quantum);
int time = 0;
while (1)
{
    int done = 1;
    for (int i = 0; i < num_processes; i++)
    {
        if (remaining_time[i] > 0)
        {
            done = 0;
            int start_time = (processes[i].arrival_time >
                              time)
                                 ? processes[i].arrival_time
                                 : time;

            int end_time = (remaining_time[i] >
                            time_quantum)
                               ? start_time + time_quantum
                               : start_time + remaining_time[i];
            printf("P%d: %d-%d\t",
                   processes[i].process_id, start_time, end_time);
            processes[i].waiting_time += start_time -
                                         time;
            processes[i].turnaround_time += end_time -
                                            processes[i].arrival_time;
            processes[i].response_time += (start_time == processes[i].arrival_time)? 0 : start_time - processes[i].arrival_time;
            time = end_time;
            remaining_time[i] -= time_quantum;
        }
    }
    if (done == 1)
    {
        break;
    }
}
// Calculate averages
 for (int i = 0; i < num_processes; i++) { total_waiting_time += processes[i].waiting_time; total_turnaround_time +=
processes[i].turnaround_time;
total_response_time += processes[i].response_time;
}
double avg_waiting_time = (double)total_waiting_time /

                          num_processes;
double avg_turnaround_time =
    (double)total_turnaround_time / num_processes;
double avg_response_time = (double)total_response_time /
                           num_processes;
// Display averages
 printf("\nAverage Waiting Time: %.2lf\n",avg_waiting_time);
printf("Average Turnaround Time: %.2lf\n",avg_turnaround_time);
printf("Average Response Time: %.2lf\n",
       avg_response_time);
free(remaining_time);
}
