#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
void main(){
	pid_t childpid,value;
	int sum;
	childpid = fork();
	if(childpid>0){
		value = wait(NULL);
		printf("Parent: %d\n", getpid());
		printf("%d",value);
	}else{
		sum = 20+30;
		printf("%d\n",sum);
		printf("Child: %d\n",getpid());
	}
}
