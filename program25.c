#include<stdio.h>
int factorial(int mul,int n){
	if(n==1){
		return mul;
	}
	mul*=n;
	factorial(mul,n-1);
}
void main(){
	int n,mul=1;
	printf("Enter the number:");
	scanf("%d",&n);
	mul=factorial(mul,n);
	printf("The factorial is: %d",mul);
}
