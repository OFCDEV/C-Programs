#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("\n I am main process pid = (%d)\n",getpid());
	execl("/home/debasish/C-Programs/p2.out","hello","world","arg3",NULL);
	
	printf("This line will not be printed...");
	return 0;
}
