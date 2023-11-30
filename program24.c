#include<stdio.h>
int calculate(int sum, int n){
	if(n==0){
		return sum;
	}
	sum+=n;
	return calculate(sum,n-1);
}
void main(){
	int n,sum=0;
	printf("Enter the number:");
	scanf("%d",&n);
	sum = calculate(sum,n);
	printf("Summation is: %d ",sum);
	                                                                                                                                 
}
