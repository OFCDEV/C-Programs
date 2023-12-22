#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main(){
	getchar();
	kill(getpid(),SIGTERM);
	return 0;
}
