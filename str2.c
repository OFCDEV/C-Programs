#include<stdio.h>
struct parent{
	int a;
	struct child{
		float f;
		char ch;
	}c;
}p;
void main(){
	struct parent p ={25,76,'A'};
	printf("%f\n",p.c.f);
	printf("%d\n",p.a);
	printf("%c\n",p.c.ch);
	
}
