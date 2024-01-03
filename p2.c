#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	int i;
	printf("I am a new program called by execl(),my pid is (%d)",getpid());
	printf("\n");
	for(i=0;i<argc;i++){
		printf("\n argv(%d) = (%s)\n",i,argv[i]);
	}
	return 0;
}
