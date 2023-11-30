#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Parent: %d\n",getpid());
	for(int i=0;i<3;i++){
		int pid =fork();
		if(pid == -1){
		printf("Error");
		}
		else if(pid == 0){
			printf("Child %d from parent process: %d",getpid(),getppid());
			break;
		}
		else{
			printf("Child process: %d",getpid());
		}
	}
	return 0;
}
