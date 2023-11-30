#include<stdio.h>
struct Student{
	int roll;
	char section;
	float mark;
}
	main(){
	struct Student S1;
	S1.roll = 2;
	S1.section = 'k';
	S1.mark = 99.9;
	
	printf("%d",S1.roll);
	printf("%c",S1.section);
	printf("%f",S1.mark);
}
