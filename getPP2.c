#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t childpid;
	childpid = fork();
	if(childpid == -1){
		printf("Error");
		return 1;
	}
	if(childpid == 0){
		printf("Child: %ld\n",(long)getpid());
	}
	else{
		printf("Parent: %ld",(long)getppid());
	}
}
