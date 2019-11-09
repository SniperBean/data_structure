#include "stdlib.h"
#include "stdio.h"

void insertionSort(int* arr, int size){
	int i;
	for(i = 1; i<size; i++){
		int key	= arr[i];
		int j = i-1;
		while(key < arr[j] && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key; 
	}
}

void printArray(int* arr,int size){
	int i;
	for(i = 0; i<size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	const int size = 6;
	int arr[size] = { 5, 3, 1, 2, 6, 4 };
	printf("Origin:\n");
	printArray(arr, size);
	insertionSort(arr, size);
	printf("After insertion sort:\n");
	printArray(arr, size);
}
