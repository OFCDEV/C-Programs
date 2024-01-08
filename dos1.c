#include <stdio.h>
#include <stdlib.h>
struct Process{
int process_id;
int arrival_time;
int burst_time;
};
struct Process* create_process(int process_id, int arrival_time, int burst_time){
struct Process* process = (struct Process*)malloc(sizeof(struct Process));
process->process_id = process_id;
process->arrival_time = arrival_time;
process->burst_time = burst_time;
return process;
}
void FCFS(struct Process* processes, int num_processes){
for(int i=0; i < num_processes;i++){
for(int j=i+1; j < num_processes; j++){
if(processes[j].arrival_time < processes[i].arrival_time){
struct Process temp = processes[j];
processes[j] = processes[i];
processes[i] = temp;
}
}
printf("Executing process %d form time %d to %d\n", processes[i].process_id,
processes[i].arrival_time,processes[i].arrival_time + processes[i].burst_time);
}
}
void Round_Robin(struct Process* processes, int num_processes, int time_quantum) {
int* remaining_burst_time = (int*)malloc(sizeof(int) * num_processes);
for (int i = 0; i < num_processes; i++) {
remaining_burst_time[i] = processes[i].burst_time;
}
int current_time = 0;
while (1) {
int done = 1;
for (int i = 0; i < num_processes; i++) {
if (remaining_burst_time[i] > 0) {
done = 0;
if (remaining_burst_time[i] >= time_quantum) {
current_time += time_quantum;
remaining_burst_time[i] -= time_quantum;
printf("Executing process %d from time %d to %d\n", processes[i].process_id,
current_time - time_quantum, current_time);
}
else {
current_time += remaining_burst_time[i];
int temp = remaining_burst_time[i];
remaining_burst_time[i] = 0;
printf("Executing process %d from time %d to %d \n", processes[i].process_id,
current_time - temp, current_time);
}
}
}
if (done == 1) {break;}
}
free(remaining_burst_time);
}
int main(){
struct Process processes[] = {{1, 0, 10},{2, 1, 1},{3, 2, 2},{2, 3, 1},{3, 6, 5}};
int num_processes = sizeof(processes) / sizeof(processes[0]);
printf("\nRound Robin:\n");
Round_Robin(processes, num_processes, 2);
printf("\nFCFS:\n");
FCFS(processes, num_processes);
return 0;
}