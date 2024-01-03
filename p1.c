#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("\n I am main process pid = (%d)\n",getpid());
	execl("C:\\Users\\debas\\OneDrive\\Documents\\C-Programs\\p2.exe","hello","world","arg3",NULL);
	
	printf("This line will not be printed...");
	return 0;
}
