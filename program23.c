#include<stdio.h>
void printPrime(){

	for(int i=1;i<=n;i++){
	int flag=0;
		for(int j=2;j<=i/2;j++){
		if(i%j==0){
			flag=0;
			break;
		}
	}
	if(flag==0){
		printf("%d\n",i);
	}
	}
	
}
void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	printPrime(n);
}
