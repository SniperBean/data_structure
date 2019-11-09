#include "stdlib.h"
#include "stdio.h"

int findSetCollapsing(int* subset, int i){
	int root;
	for(root = i; subset[root] >=0; root = subset[root]);

	while(i != root){
		int parent = subset[i];
		subset[i] = root;
		i = parent;
	}
	return root;
}
void unionSet(int* subset, int x, int y){
	int xroot = findSetCollapsing(subset, x),
	    yroot = findSetCollapsing(subset, y);
	
	if(subset[xroot] <= subset[yroot]){
		subset[xroot] += subset[yroot];
		subset[yroot] = xroot;
	}
	else{
		subset[yroot] += subset[xroot];
		subset[xroot] = yroot;
	}

}
void printArray(int* array, int size){
	int i;
	for(i = 0; i<size; i++){ 
		printf("%d\t",i);}
	printf("\n");
	for(i = 0; i<size; i++){
		printf("%d\t",array[i]);
	}
	printf("\n");
}

int main(){
	const int size = 6;
	int array[] = {-1, -1, -1, -1, -1, -1};
	printArray(array, size);

	unionSet(array, 1, 2);
	printf("After union(1, 2)\n");
	printArray(array, size);

	unionSet(array, 0, 2);
	printf("After union(0, 2)\n");
	printArray(array, size);

	unionSet(array, 3, 5);
	printf("After union(3, 5)\n");
	printArray(array, size);

	unionSet(array, 2, 5);
	printf("After union(2, 5)\n");
	printArray(array, size);
	
	findSetCollapsing(array, 5);
	printf("After collapsing element(5)\n");
	printArray(array, size);
	

}
