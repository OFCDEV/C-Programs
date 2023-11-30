#include<stdio.h>
int reverse(int n){
	int rev=0,rem;
	while(n != 0){
		rem = n%10;
		rev = rev*10+rem;
		n = n/10; 
	}
	return rev;
}
int pallindrome(int rev, int n){
	if(n==rev){
		printf("It is a palindrome.");
	}else{
		printf("No No.");
	}
}
void main(){
	int n;
	printf("Enter the number you want to reverse: ");
	scanf("%d",&n);
	int rev = reverse(n);
	printf("%d\n",rev);
	int pal = pallindrome(rev,n);
	printf("%d",pal);
}
