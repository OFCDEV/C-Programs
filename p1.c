#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("\n I am main process pid = (%d)\n",getpid());
	execl("/home/student/OSW-2141002098/p2.out","hello","world","arg3",NULL);
	
	printf("This line will not be printed...");
	return 0;
}
