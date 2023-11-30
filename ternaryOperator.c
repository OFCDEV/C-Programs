#include<stdio.h>
void main(){
	int n1,n2;
	printf("Enter the value of n1 and n2: ");
	scanf("%d%d", &n1,&n2);
	char ch;
	scanf("%c",&ch);
	int res = (ch == '+')?(n1+n2):(n1-n2);
	printf("%d",res);
}
