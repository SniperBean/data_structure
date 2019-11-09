#include "stdlib.h"
#include "stdio.h"

void printArray(int* arr){
	int i;
	for(i=0; i<=sizeof(arr); i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxHeapify(int* arr, int root, int size){
	int left = root * 2 + 1;
	int right = root * 2 + 2;
	int largest;

	if(left < size && arr[left] > arr[root]){
		largest = left;
	}
	else{
		largest = root;
	}

	if(right < size && arr[right] > arr[largest]){
		largest = right;
	}

	if(largest!=root){
		swap(&arr[largest], &arr[root]);
		maxHeapify(arr, largest, size);	
	}
}

void buildMaxHeap(int* arr){
	int i;
	for(i = sizeof(arr); i>0; i--){
		maxHeapify(arr, i, sizeof(arr));
	}
}

void heapSort(int* arr){
	int i, size;
	buildMaxHeap(arr);
	size = sizeof(arr)+1;

	for(i = size-1; i>=1; i--){
		swap(&arr[i], &arr[0]);
		maxHeapify(arr, 0, --size);
	}
}

int main(){
	const int size = 9;
	int arr[size] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
	int* array = (int*)malloc(sizeof(int)*size);
	array = arr;
	int a = sizeof(array);
	printf("Origin:\n");
	printArray(array);
	printf("After heap sort:\n");
	heapSort(array);
	printArray(array);
}
