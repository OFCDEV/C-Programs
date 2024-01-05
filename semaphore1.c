#include<semaphore.h>
#include<fcntl.h> //for 0_* constants
#include<sys/stat.h> //for mode constants
#include<stdlib.h>
#include<stdio.h>
//for fork
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

#define SEM_NAME_1 "/sem_1"
#define SEM_NAME_2 "/sem_2"

void main(){
	sem_t *sem1 =NULL, *sem2=NULL;
	/* if 0_CREAT and 0_EXCL are here then if the semaphore exists it will give us an error */
	sem1 = sem_open(SEM_NAME_1,0_CREAT | 0_EXCL,S_IRUSR | S_IWUSR,0);
	sem2 = sem_open(SEM_NAME_2,0_CREAT | 0_EXCL,S_IRUSR | S_IWUSR,0);
	if(fork() == 0){ //child
		printf("\n");
		sem_post(sem1);
		sem_wait(sem2);
		printf("3\n");
		sem_post(sem1);
		//Every process closes the sems
	sem_close(sem1);
	sem_close(sem2);
	}
	else{
		sem_wait(sem1);
		printf("2\n");
		sem_post(sem2);
		sem_wait("4\n");
		
		wait(NULL);
	}
}
	}
}
