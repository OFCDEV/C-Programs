#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t childpid;
    childpid = fork();
    if (childpid==-1)
    {
        printf("Fork error\n");
    }else if (childpid == 0)
    {
        printf("Bacha--> Childpid: %d----PPID:%d",getpid(),getppid());
        sleep(100);
        printf("Childpid: %d----PPID:%d",getpid(),getppid());
    }else
    {
        printf("Baap-->Childpid: %d----PPID:%d",getpid(),getppid());
        exit(0);
    }
    
    
}