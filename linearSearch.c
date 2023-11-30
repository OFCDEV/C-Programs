#include <stdio.h> 

int search(int arr[], int N, int key) 
{ 
	for (int i = 0; i < N; i++) 
		if (arr[i] == key) 
			return i; 
	return -1; 0000000000g
}
void reverse(int arr[], int N){
	printf("Reverse order is: ");
	for(int j=0;j<N/2;j++){
		int temp = arr[j];
		arr[j]=arr[N-1-j];
		arr[N-1-j] = temp;
	}
} 
void duplicate(int arr[],int N){
	for(int k=0;k<N;k++){
		fot(int l=i+1;i<N;l++){
			if(arr[k]==arr[l]){
				printf("%d",arr[k]);
			}
		}
	}
}
int main(void) 
{ 
	int arr[] = { 2, 3, 4, 10, 40 }; 
	int key = 10; 
	int N = sizeof(arr) / sizeof(arr[0]); 

	// Function call 
	int result = search(arr, N, key); 
	(result == -1) 
		? printf("Element is not present in array") 
		: printf("Element is present at index %d", result); 
	reverse(arr,N);
	duplicate(arr,N);
}

