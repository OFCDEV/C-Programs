#include<stdio.h>
#include<string.h>
int main(){
	char str[] = "ITER-IBCS-SOA-SUM-IDS";
	char ptr[] = "iter-ibcs-soa-sum-ids-CSE";
	char *token,*ptoken,*sptr1,*sptr2;
	token = strtok_r(str,"-",&sptr1);
	ptoken = strtok_r(ptr,"-",&sptr2);
	while(token != NULL){
		printf("Token=%s\n",token);
		token = strtok_r(NULL,"-",&sptr1);
	}
	while(ptoken != NULL){
		printf("pToken=%s\n",ptoken);
		ptoken = strtok_r(NULL,"-",&sptr2);
	}
	return 0;
}
