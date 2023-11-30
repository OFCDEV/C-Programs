/*two types of structure
1.Separated nested str
2.Embedding nested str */
#include<stdio.h>
struct child{
	int a;
	char ch;
};
struct parent{
	float f;
	struct child c;
};
void main(){
	struct parent p ={25,76,'A'};
	printf("%f\n",p.f);
	printf("%d\n",p.c.a);
	printf("%c\n",p.c.ch);
	
}
