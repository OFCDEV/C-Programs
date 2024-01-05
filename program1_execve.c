#include<stdio.h> 
#include<unistd.h> 
  

int main(int argc, char *argv[]) 
{ 
    int i; 
      
    printf("I am new program called by execv() "); 
    printf("\n"); 
    for(i = 0; i < argc; i++){
        printf("\n argv[%d] = (%s)\n",i,argv[i]);
    }


    return 0; 
} 
