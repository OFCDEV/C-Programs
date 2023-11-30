#include<stdio.h>
#include<unistd.h>
void main(){
	int x;
	x=0;
	fork();
	x=1;
	printf("I am a process: %ld and x is %d",(long)getpid(),x);
}
