#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

// Define the number of processes
#define N 6

// Define the messages to be printed
char* messages[N] = {"Coronavirus", "WHO:", "COVID-19", "disease", "pandemic", "\n"};

// Declare the semaphores as global variables
sem_t sems[N];

// A function to print a message to the standard error
void print_message(int i) {
    // Wait on the semaphore corresponding to the process
    sem_wait(&sems[i]);
    // Print the message
    fprintf(stderr, "%s ", messages[i]);
    // Signal the next semaphore
    sem_post(&sems[(i+1) % N]);
}

int main() {
    // Initialize the semaphores
    for (int i = 0; i < N; i++) {
        // The first semaphore is initialized to 1, the rest to 0
        sem_init(&sems[i], 0, i == 0 ? 1 : 0);
    }

    // Create the processes using fork()
    for (int i = 0; i < N; i++) {
        // Fork a new process
        pid_t pid = fork();
        // Check for errors
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        // Check if child process
        if (pid == 0) {
            // Call the print_message function
            print_message(i);
            // Exit the child process
            exit(0);
        }
    }

    // Wait for all the child processes to terminate
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }

    // Destroy the semaphores
    for (int i = 0; i < N; i++) {
        sem_destroy(&sems[i]);
    }

    return 0;
}
