#include<stdio.h>
#include<stdbool.h>
void swap(int* xp,int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[],int n){
	int i,j;
	bool swapped;
	for(i=0;i<n-1;i++){
		swapped = false;
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}`
}
void printArray(int arr[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
}
void main(){
	int arr[] = {65,34,2,132,32,10};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
}
