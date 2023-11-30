#include<stdio.h>
void main(){
	int N,isPrime;
	for(int i=1; i<=N;i++){
		isPrime = 1;
		for(int j=2; j=i/2; j++){
			if(i%j == 0){
				isPrime = 0;
				break;
			}
			if(isPrime == 1){
				printf("%d\n",i);
			}
		}
	}
}
