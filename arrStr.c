#include<stdio.h>
struct str{
	int a;
	char ch;
};
void main(){
	struct str s[10];
	for(int i=0;i<10;i++){
		scanf("%d",&s[i].a);
		scanf("%c",&s[i].ch);
	}
	for(int i=0;i<10;i++){
		printf("%d %c",s[i].a,s[i].chged);
}
