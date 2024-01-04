#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("\n Main Program p1.c\n");
	//A null terminated array of charecter pointers
	char *args[]={"arg1","arg2","arg3",NULL};
	//Adding Environment variables
	char* envp[]={"My","own","environment","var",NULL};
	execve("C:\\Users\\debas\\OneDrive\\Documents\\C-Programs\\execlPr2.exe",args,envp);
	
	printf("\n This line is not");
	return 0;
}
