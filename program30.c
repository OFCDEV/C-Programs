//calculate a^n using recusrsion
#include<stdio.h>
int power(int a, int n){
	if(n == 0){
		return 1;
	}else{
		return a*power(a,n-1);
	}
}
int main(){
	int a,n;
	printf("Enter the base number: ");
	scanf("%d",&a);
	printf("Enter power number:");
	scanf("%d",&n);
	int result = power(a,n);
	printf("%d^%d=%d",a,n,result);
}
