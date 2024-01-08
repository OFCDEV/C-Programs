#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main() 
{ 
	int pid; 
	for (int i = 0; i < 3; i++) { 
		pid = fork(); 

		if (pid > 0) { 
			printf("Parent process ID is %d\n",getpid()); 
			break; 
		} 
		else { 
			printf("Child process ID is %d\n",getpid()); 
		} 
	} 

	return 0; 
} 
