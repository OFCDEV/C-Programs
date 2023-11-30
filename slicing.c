#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void slicing(char* str,char* sub,int s,int e){
	int j=0;
	for(int i=s;i<=e;i++){
		sub[j++]=str[i];
	}
	sub[j]=0;
}
void main(){
	char str[] = "abcd";
	int l =strlen(str);
	char sub[l+1];
	for(int s=0;s<=l-1;s++){
		for(int e=l-1;e>=s;e--){
			slicing(str,sub,s,e);
			printf("%s\n",sub);
		}
	}
}
