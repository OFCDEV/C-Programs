#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include <fcntl.h>
int main(){
	pid_t cpid;
	int status =0;
	int num=5;
	cpid= fork();
	if(cpid == -1)
		exit(0);
	if(cpid == 0){
		printf("\nBefore exex\n");
		execl("//home//debasish//C-Programs//execlPr2.exe","arg1","arg2",NULL);
		printf("\n line is not printed\n");
	}
	else{
		printf("\n Parent executing before wait(),child process created by parent is =(%d)\n",cpid);
		cpid=wait(&status); /* waiting for child process to exit */
		printf("\n wait() in parent done\nParent pid=%d\n",getpid());
		printf("\n cpid retuned is (%d)\n",cpid);
		printf("\n status is (%d)\n",status);
	}
	return 0;
}
