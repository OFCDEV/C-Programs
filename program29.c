#include<stdio.h>
#include<stdbool.h>
bool prime(int n, int i){
	if(n<=2){
		return (n==2)?true:false;
	}
	if(n%i==0){
		return false;
	}
	if(i*i>n){
		return true;
	}
	prime(n,i+1);
}
void main(){
	int n,i=2;
	scanf("%d",&n);
	bool res = prime(n,i);
	printf("%d",res);
}

