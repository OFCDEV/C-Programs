#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    pid_t fc,sc,tc;
    fc = fork();
    if (fc == 0)
    {
        sc = fork();
        if (sc == 0)
        {
            printf("Process1\n");
        }else{
            wait(NULL);
            printf("Process2\n");
        }
    }
    else{
        tc = fork();
        if (tc == 0)
        {
            printf("Process3\n");
        }else{
            wait(NULL);
            printf("Process4\n");
        }
        
    }
    return 0;
}