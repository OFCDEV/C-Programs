#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int max[MAX_PROCESSES][MAX_RESOURCES];
int alloc[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

void input()
{
    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter maximum available resources:\n");
    for (int i = 0; i < resources; i++)
    {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    printf("Enter maximum resources for each process:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocated resources for each process:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < resources; j++)
        {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void displayNeedMatrix()
{
    printf("Need Matrix:\n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d: ", i + 1);
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int checkSafety()
{
    int work[MAX_RESOURCES], finish[MAX_PROCESSES];

    // Initialize work and finish arrays
    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    for (int i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }

    // Try to find a safe sequence
    for (int i = 0; i < processes; i++)
    {
        if (finish[i] == 0)
        {

            int j;
            for (j = 0; j < resources; j++)
            {
                if (need[i][j] > work[j])
                {
                    break;
                }
            }

            if (j == resources)
            {
                // Process i can finish
                for (int k = 0; k < resources; k++)
                {
                    work[k] += alloc[i][k];
                }
                finish[i] = 1;
                i = -1; // Start over from the beginning
            }
        }
    }

    // Check if all processes finished
    for (int i = 0; i < processes; i++)
    {
        if (finish[i] == 0)
        {
            return 0; // Unsafe state
        }
    }

    return 1; // Safe state
}

void displaySafeSequence()
{
    printf("Safe Sequence: ");
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES], finish[MAX_PROCESSES];

    // Initialize work and finish arrays
    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    for (int i = 0; i < processes; i++)
    {
        finish[i] = 0;
    }

    // Find a safe sequence
    for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < processes; j++)
        {
            if (finish[j] == 0)
            {
                int k;
                for (k = 0; k < resources; k++)
                {
                    if (need[j][k] > work[k])
                    {
                        break;
                    }
                }

                if (k == resources)
                {
                    // Process j can finish
                    for (int l = 0; l < resources; l++)
                    {
                        work[l] += alloc[j][l];
                    }
                    finish[j] = 1;
                    safeSequence[i] = j;
                    break;
                }
            }
        }
    }

    // Display the safe sequence
    for (int i = 0; i < processes; i++)
    {
        printf("P%d", safeSequence[i] + 1);
        if (i < processes - 1)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int requestResources(int process)
{
    int request[MAX_RESOURCES];



printf("Enter resource request for Process %d: ", process +1);

for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
        if (request[i] > need[process][i] || request[i] >

                                                 available[i])
        {
            printf("Invalid request. Exiting.\n");
            return -1; // Invalid request
        }
}

// Attempt to allocate resources
for (int i = 0; i < resources; i++) {
        available[i] -= request[i];
        alloc[process][i] += request[i];
        need[process][i] -= request[i];
}

// Check if the system is still in a safe state
if (checkSafety()) {
        printf("Resource allocation successful. System is in a safe state.\n");
        return 0; // Successful allocation
} else {
        // Rollback the allocation if it leads to an unsafe state
        printf("Resource allocation failed. Rolling back changes.\n");
        for (int i = 0; i < resources; i++)
        {
            available[i] += request[i];

            alloc[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return -1; // Unsafe state after allocation
}
}

int main()
{
    input();
    displayNeedMatrix();
    if (checkSafety())
    {
        printf("The system is in a safe state.\n");
        displaySafeSequence();
    }
    else
    {
        printf("The system is in an unsafe state.\n");
    }

    int process;
    printf("Enter the process to request resources (1 to %d): ", processes);
    scanf("%d", &process);
    process--; // Adjust to 0-based index

    if (process < 0 || process >= processes)
    {
        printf("Invalid process number. Exiting.\n");
        return 1;
    }

    if (requestResources(process) == 0)
    {
        printf("Resource request granted.\n");
    }
    else
    {
        printf("Resource request denied.\n");
    }
    return 0;
}
