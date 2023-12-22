#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void exitFunction(){
	printf("Inside Function\n");
}
int main(){
	atexit(exitFunction);
	printf("Inside Main2\n");
	printf("Returning from main\n");
	return 0;
	printf("This will not be printed");
}
