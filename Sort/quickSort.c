#include "stdlib.h"
#include "stdio.h"

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int front, int end){
	int pivot = arr[end];
	int i = front-1;
	int j;
	for(j = front; j < end; j++){
		if(arr[j]<pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	i++;
	swap(&arr[i], &arr[end]);
	return i;
}

void quickSort(int* arr, int front, int end){
	if(front<end){
		int pivot = partition(arr, front, end);
		quickSort(arr, front, pivot-1);
		quickSort(arr, pivot+1, end);
	}
}

void printArray(int* arr, int size){
	int i;
	for(i = 0; i<size; i++){
		printf("%d ",arr[i]);		
	}
	printf("\n");
}

int main(){
	const int n = 9;
	int array[n] = { 9, 4, 1, 6, 7, 3, 8, 2, 5 };
	printf("Origin:\n");
	printArray(array, n);
	quickSort(array,0,n-1);
	printf("After quick sort:\n");
	printArray(array, n);
}
