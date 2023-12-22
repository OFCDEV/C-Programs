#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int main(){
	for(int i=0;i<50;i++){
		printf("i =%d\n",i);
		sleep(2);
	}
}
