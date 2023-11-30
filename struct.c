#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct students{
	char name[50];
	int roll;
}
typedf struct{
	student st;
}
void main(){
	struct students s1;
	s1.name = "Debasish";
	s1.roll = "5";
	printf("%d",s1.roll);
}
