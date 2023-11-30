#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char maxCharF(char str[])
{
	int count[256] = { 0 };
	int length = strlen(str);
	for (int i = 0; i < length; i++)
		count[(int)str[i]]++;
	char maxChar;
	int maxCount = 0;
	for (int i = 0; i < length; i++) {
		if (count[(int)str[i]] > maxCount) {
			maxCount = count[(int)str[i]];
			maxChar = str[i];
		}
	}
	printf("The max charecter occured %d\n",maxCount);
	return maxChar;
}
void subString(char str1[] ){
	char s[100], sub[100];
	int c,length=0,position=0;
	scanf("%d %d",&length,&position);
	int count =0;
	while(c<length){
		sub[c] = s[position+c-1];
		c++;
	}
	sub[c]='\0';
	printf("%s",sub);
	
}

int main()
{
	char str[] = "AABBBBBBBBBCDERF";
	printf("Max occurring character is: %c\n",maxCharF(str));
	subString(str);
	return 0;
	
}

