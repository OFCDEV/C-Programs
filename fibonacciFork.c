#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    if (argc != 2 || atoi(argv[1]) <= 0) {
        fprintf(stderr, "Usage: %s <number_of_terms (positive integer)>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) { // Child process
        for (int i = 0; i < n; i++)
            printf("%d ", fibonacci(i));
        printf("\n");
    } else { // Parent process
        wait(NULL);
        printf("Parent process completed.\n");
    }

    return 0;
}