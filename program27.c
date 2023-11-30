#include<stdio.h>
int GCD(int a,int b){
	while(a != b)
	{
		if(a>b)
		{
			return GCD(a-b,b);
		}
		else{
			return GCD(a,b-a);
		}
	}
	return a;
}
void main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int res = GCD(a,b);
	printf("%d",res);
}
