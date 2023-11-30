#include<stdio.h>
#include<stdbool.h>
bool check(int n){
	if(n%2 == 0){
		return true;
	}
	else{
		return false;
	}
}
void main(){
	int num;
	scanf("%d",&num);
	bool e = check(num);
	if(e){
		printf("even");
	}
	else{
		printf("odd");
	}
}
