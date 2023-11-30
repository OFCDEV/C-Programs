#include<stdio.h>
void main(){
	int n;
	int first=0,second=1;
	int next = first+second;
	printf("Enter the length of fibonacci series: ");
	scanf("%d",&n);
	printf("%d\n%d\n",first,second);
	for(int i=3; i<=n;i++){
		printf("%d\n",next);
		first =second;
		second=next;
		next=first+second;
	}
}
