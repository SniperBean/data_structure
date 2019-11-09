#include "stdlib.h"
#include "stdio.h"
typedef unsigned int bool;
#define false 0
#define true 1

bool IsEmpty();

struct queue{
	int capacity;
	int front;
	int back;
	int* array;
};
typedef struct queue Queue;

Queue aqueue;


void doubleCapacity(){
	if(aqueue.array == NULL){
		aqueue.capacity = 2;
		aqueue.array = (int*)malloc(sizeof(int)*aqueue.capacity);
	}
	else{
		aqueue.capacity *= 2;
		int i;
		int* tempArray = (int*)malloc(sizeof(int)*aqueue.capacity);
		for(i=0; i < aqueue.capacity/2; i++){
			tempArray[i] = aqueue.array[i];
		}
		aqueue.array = (int*)malloc(sizeof(int)*aqueue.capacity);
		aqueue.array = tempArray;
	}
}

void push(int data){
	if(IsEmpty()){
		if(aqueue.array == NULL){
		doubleCapacity();
		}
		aqueue.array[aqueue.front]=data;
	}
	else if(aqueue.capacity == aqueue.back+1){
		doubleCapacity();
		aqueue.back++;
		aqueue.array[aqueue.back]=data;
	}
	else{
		aqueue.back++;
		aqueue.array[aqueue.back]=data;
	}
}

void pop(){
	if(IsEmpty()){
		printf("The queue was empty!\n");
	}
	else if(aqueue.front<aqueue.back){
		printf("Pop out: %d\n", aqueue.array[aqueue.front]);
		aqueue.array[aqueue.front] = 0;
		aqueue.front++;
	}
	else{
		printf("Pop out: %d\n", aqueue.array[aqueue.front]);
		aqueue.array[aqueue.front] = 0;
	}
}

int getFront(){	
	if(IsEmpty()) return -1;
	else return aqueue.array[aqueue.front];

}
int getBack(){
	if(IsEmpty()) return -1;
	else return aqueue.array[aqueue.back];
}
int getSize(){
	if(!IsEmpty())return aqueue.back-(aqueue.front-1);
	else return 0; 
}
bool IsEmpty(){
	if(aqueue.array == NULL){
	       	return true;
	}
	else if(aqueue.front == aqueue.back && aqueue.array[aqueue.front] == 0){
		return true;
	}
	else{ 
		return false;
	}
}

int main(){
	aqueue.front = 0;
	aqueue.back = 0;
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	push(123);
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	push(321);
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	push(534);
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	push(9453);
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	push(87);
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
	pop();
	printf("front = %d\tback = %d\tSize = %d\n", getFront(), getBack(), getSize());
}
