#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

extern char **environ;
int main(int argc, char *argv[]){
	int j;
	char **ep;
	
	printf("\n Executing program2\n");
	for(j=0;j<argc;j++){
		printf("argv[%d]=%s\n",j,argv[j]);
	}
	for(ep=environ; *ep!=NULL;ep++){
		printf("Environ: %s\n",*ep);
	}
	exit(0);
}
