#include<stdio.h>
#include<string.h>
int main(){
	char str[] = "ITER-IBCS-SOA-SUM-IDS";
	char ptr[] = "iter-ibcs-soa-sum-ids-CSE";
	char *token,*ptoken;
	token = strtok(str,"-");
	ptoken = strtok(ptr,"-");
	while(token != NULL){
		printf("Token=%s\n",token);
		token = strtok(NULL,"-");
	}
	return 0;
}
