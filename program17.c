#include<stdio.h>
void main(){
	int counter = 1;
	for(int i=1; i<=4;i++){
		for(int j=1;j<=i;j++){
			printf("%d",counter);
			counter++;
		}
		printf("\n");
	}
	
}
