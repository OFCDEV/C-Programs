#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <unistd.h> 
int main() 
{ 
	for (int i = 0; i < 3; i++) { 
		if (fork() == 0) {  
			printf("child pid %d from the parent pid %d\n",getpid(), getppid());
			exit(0); 
		} 
	} 

	for (int i = 0; i < 3; i++) 
		wait(NULL); 
} 
