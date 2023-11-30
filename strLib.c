#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str1[30],str2[30];
	int n;
	printf("Enter string1 and string2: \n");
	fgets(str1,30,stdin);
	scanf("%s",str2);
	//printf("Enter string2: \n");
	//fgets(str2,30,stdin);
	//scanf("%s",str2);
	char str[] = "Good,bye!";
	char sStr[] = "bye";
	char* ptr = strstr(str,sStr);
	int s1 = strcmp(str1,str2);
	int s2 = strncmp(str1,str2,2);
	int s3 = strcasecmp(str1,str2);
	printf("%ld",ptr-str);
	printf("%d %d %d",s1,s2,s3);
	return 0;
}
