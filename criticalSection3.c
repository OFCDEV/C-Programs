#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<semaphore.h>
int shrd;
sem_t sem;
void process(int inc){
    sem_wait(&sem);
    int x=shrd;
    x+=inc;
    sleep(1);
    shrd=x;
    printf("Process:Shrd = %d\n",shrd);
}
int main(){
    sem_init(&sem,1,1);
    pid_t pid1 = fork();
    if (pid1 == 0)
    {
        process(1);
    }else{
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            process(-1);
        }else{
            waitpid(pid1,NULL,0);
            waitpid(pid2,NULL,0);
            printf("Final shrd value: %d\n",shrd);
        }
        sem_destroy(&sem);
        return 0;
    }
    
}