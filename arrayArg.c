#include<stdio.h>
#include<string.h>
char **makeargv(char *);
int main(){
	char s[] ="This is a string.";
	char **myargv;
	myargv=makeargv(s);
	if(myargv==NULL){
		fprintf(stderr,"Failed to construc.\n");
	}else{
		for(int i=0;myargv[i]!=NULL;i++){
			printf("Myargv[%d]:\n",myargv[i]);
		}
	}
	return 0;
}
