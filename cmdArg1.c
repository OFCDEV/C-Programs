#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[]){
	int sum=0,i,number;
	char* value;
	for(int i=0;i<argc;i++){
		value = argv[i];
		//ascii to int func --> atoi
		number = atoi(value);
		sum+=number;
	}
}
