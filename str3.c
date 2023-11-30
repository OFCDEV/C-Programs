#include<stdio.h>
struct parent{
	char ch;
	struct child c;
};
struct child{
	int a;
	float b;
}
void main(){
	struct parent p={'a',24,9};
	
}
