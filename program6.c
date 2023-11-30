#include<stdio.h>
void main(){
	int fact = 1;
	for(int i =10 ; i>=1 ; i--){
		fact*=i;
	}
	printf("%d",fact);
}
