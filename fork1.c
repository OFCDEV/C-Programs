#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t childpid;
	childpid=fork();
	if(childpid == -1){
		printf("Failed");
		return 1;
	}
	if(childpid== 0){
		printf("%d",getpid());
	}
}
