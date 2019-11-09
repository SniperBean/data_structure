#include "stdlib.h"
#include "stdio.h"

void merge(int* arr, int front, int mid, int end){
	int Lrange = mid - front+1;
	int Rrange = end - mid ;
	int Larr[Lrange+1];
	int Rarr[Rrange+1];
	int i,j,k;

	for(i=0; i<Lrange; i++){
		Larr[i] = arr[i+front];
	}
	Larr[i] = 99999;
	for(i=0; i<Rrange; i++){
		Rarr[i] = arr[i+mid+1];
	}
	Rarr[i] = 99999;


	i=0;
	j=0;
	for(k = front; k<=end; k++){
		if(Larr[i]<Rarr[j]){
			arr[k] = Larr[i++];		
		}
		else{
			arr[k] = Rarr[j++];
		}
	} 

	
}

void mergeSort(int* arr, int front, int end){
	if(front<end){
		int mid = (front+end)/2;
		mergeSort(arr, front, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, front, mid, end);
	}
}

void printArray(int* arr){
	int i;
	for(i = 0; i<sizeof(arr); i++){
		printf("%d ", arr[i]);		
	}
	printf("\n");
}

int main(){
	int array[] = { 5, 3, 8, 6, 2, 7, 1, 4 };
	printArray(array);
	mergeSort(array, 0, sizeof(array)/sizeof(int)-1);
	printArray(array);
}
