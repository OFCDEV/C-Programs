#include<stdio.h>
#include<stdlib.h>
void main(){
	int n1,n2;
	scanf("%d\n",&n1);
	int *ptr = (int*)malloc(n1*sizeof(int));
	for(int i=0;i<n1;i++){
		printf("%pc \n",ptr+i);
	}
	scanf("%d",&n2);
	ptr=realloc(ptr,n2);
	for(int i=0;i<n2;i++){
		printf("%pc \n",ptr+i);
	}
}
