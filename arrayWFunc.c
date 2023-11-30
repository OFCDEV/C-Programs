//Passing an array to a function by call by value
#include<stdio.h>
void display(int *n);
void main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		display(&arr[i]);
	}
}
	void display(int *n){
		printf("%d",*n);
	}
