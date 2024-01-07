#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(void)
{
pid_t childpid;
childpid=fork();
if (childpid==0) /*child*/
printf("Inside child \n");
else{
wait(NULL);
printf("In parent\n");
}
return 0;
}