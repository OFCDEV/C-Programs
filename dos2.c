#include <stdio.h>
int processes = 5;
int resources = 4;
int available[4] = {6, 7, 12, 12};
int max_claim[5][4] = {{0, 0, 1, 2},
{2, 0, 0, 0},
{0, 0, 3, 4},
{2, 3, 5, 4},
{0, 3, 3, 2}};
int allocation[5][4] = {{0, 0, 1, 2},
{2, 7, 5, 0},
{6, 6, 5, 6},
{4, 3, 5, 6},
{0, 6, 5, 2} };
int need[5][4];
void calculate_need() {
for (int i = 0; i < processes; i++) {
for (int j = 0; j < resources; j++) {
need[i][j] = max_claim[i][j] - allocation[i][j];
}
}
}
int check_safety(int work[], int finish[]) {
int safe_sequence[processes];
int count = 0;
for (int i = 0; i < processes; i++) {
if (finish[i] == 0) {
int safe = 1;
for (int j = 0; j < resources; j++) {
if (need[i][j] > work[j]) {
safe = 0;
break;
}
}
if (safe) {
safe_sequence[count++] = i;
finish[i] = 1;
for (int j = 0; j < resources; j++) {
work[j] += allocation[i][j];
}
i = -1; // Start again from the beginning
}
}
}
// Check if all processes are finished
for (int i = 0; i < processes; i++) {
if (finish[i] == 0) {
return 0; // Unsafe state
}
}
// Print the safe sequence
printf("Safe Sequence: ");
for (int i = 0; i < processes; i++) {
printf("P%d ", safe_sequence[i]);
}
printf("\n");
return 1; // Safe state
}
int main() {
int work[resources];
int finish[processes];
// Initialize work and finish arrays
for (int i = 0; i < resources; i++) {
work[i] = available[i];
}
for (int i = 0; i < processes; i++) {
finish[i] = 0;
}
calculate_need();
// Check if the system is in a safe state
if (check_safety(work, finish)) {
printf("The system is in a safe state.\n");
} else {
printf("The system is in an unsafe state.\n");
}
return 0;
}