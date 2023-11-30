#include<stdio.h>
void main(int argc, char* argv[]){
	//argc-> dentotes the number of number of arguments passed.
	//argv[]->denotes the pointer to array that in storing each argument
	//argv[0]->holds the name of the program
	//argv[1]->holds the 1st argument that is passed.
	//argv[n]->last arg that is passed
	if(argc<2){
		printf("No arguments has been passed.");
	}
	else{
		for(int i=0;i<argc;i++){
			printf("%s",argv[i]);
		}
	}
}
