#include<stdio.h>
void main(){
	int mask = 1,n,pos;
	scanf("%d%d",&n,&pos);
	int bitmask = mask<<pos;
	int newmask =~ bitmask;
	int res = n&newmask;
	printf("%d",res);
}
