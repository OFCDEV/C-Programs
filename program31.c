#include<stdio.h>
void printNum(int first, int last){
	if(first > last){
		return;
	}
	if(first % 2 == 0){
		printf("%d",first-1);
	}
	else{
		printf("%d",first+1);
	}
	
	printNum(first+1,last);
}
int main(){
	printf("Answer is\n");
	printNum(1,10);
	return 0;
}
