/*
Demo to use execv()
*/

#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() 
{ 
        printf("\n Main program p1.c\n");
        //A null terminated array of character  pointers 
        char *args[]={"arg1","arg2","arg3",NULL};
        
        //Adding Environment variables
        //char* envp[]={"My","own","environment","variables",NULL};
        
        execvp("pv2.out",args); 
      
        printf("\nThis line is not printed\n"); 
      
    return 0; 
} 
