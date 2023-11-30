#include<stdio.h>
#include<unistd.h>
void main(){
	printf("I am a process %ld\n",(long)getpid());
	printf("I am a process %ld\n",(long)getppid());
}
