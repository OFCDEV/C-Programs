 #include<stdio.h>
 #include<stdlib.h>
 void main(){
 	int n,num =0;
 	scanf("%d",&n);
 	//int* ptr = (int*)malloc(n*sizeof(int));
 	int* ptr = (int*)calloc(n,sizeof(int));
 	for(int i=0;i<n;i++){
 		scanf("%d",(ptr+i));
 		num+=*(ptr+i);
 	}
 	printf("%d",num);
 	free(ptr);
 }
