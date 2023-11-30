#include<stdio.h>
int reverse(int n,int rev){
	if(n==0){
		return rev;
	}
	int k=n%10;
	return reverse(n/10,(rev*10)+k);
}
void main(){
	int n,rev=0;
	scanf("%d",&n);
	int result = reverse(n,rev);
	printf("%d",result);
}
