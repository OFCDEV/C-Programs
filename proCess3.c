#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
	pid_t pid;
	int status;
	if((pid=fork()) <0){
		printf("Error");
	}else if(pid ==0){
		sleep(5);
		exit();
	}else do{
		if(pid=waitpid(pid,&status,WNOHANG) == -1){
			printf("Error");
		}else if(pid == 0){
			printf("Child is running.");
		}
	}while(pid == 0);
}
