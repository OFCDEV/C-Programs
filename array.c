#include<stdio.h>
void main(){
	int arr[5];
	for(int i=0; i<4;i++){
	scanf("%d",&arr[i]);
	printf("%d\n",arr[i]);
	}
	int sum = 0;
	for(int i=0; i<4;i++){
		sum+=arr[i];
	}
	printf("%d\n",sum);
	
	char arr1[] = {'a','b','c'};
	for(int i=0;i<2;i++){
		printf("%c\n",arr1[i]);
	}
	
	int arr2[] = {1,2,3,5,6};
	
	
}
