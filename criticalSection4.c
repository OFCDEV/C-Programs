#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<semaphore.h>

sem_t sync1;
void process1(){
    printf("Process1: a\n");
    sem_post(&sync1);
}
void process2(){
    sem_wait(&sync1);
    printf("Process2: b\n");
}
int main(){
    sem_init(&sync1,0,0);
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        process1();
    }else{
        process2();
        wait(NULL);
    }
    sem_destroy(&sync1);
    return 0;
}