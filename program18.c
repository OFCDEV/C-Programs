#include<stdio.h>

int Sum(int,int);

int Sum(int a, int b){
	int c = a+b;
	return c;
}
 void main(){
	int x,y;
	scanf("%d %d",&x,&y);
	int res = Sum(x,y);
	printf("%d",res);
}
