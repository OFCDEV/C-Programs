#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <semaphore.h> 
#include <unistd.h> 


int main(){

    int ret, sval;
    unsigned int value;
    sem_t *sem;

    sem = sem_open("/sem1",  O_RDWR);

    if (sem == SEM_FAILED){
        perror("sem_open fail;");
        return -1;
    }else{
        printf("\n sem_open success\n");
    }

   sem_getvalue(sem , &sval );
   printf("\n sval = (%d)\n",sval);

    ret = sem_wait(sem); //wait state 
    printf("\n ret is (%d)\n",ret);
    printf("\nprocess 3:\n");
    sem_post(sem);

    //sem_unlink("/sem1");

}
