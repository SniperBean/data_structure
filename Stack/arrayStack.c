#include "stdlib.h"
#include "stdio.h"
typedef unsigned int bool;
#define false 0
#define true 1

struct stack{
	int top;
	int capacity;
	int* array;
};
typedef struct stack Stack;

Stack table;

void doubleCapacity(){
	int* temparray;
	table.capacity*=2;
	temparray = (int*)malloc(sizeof(int)*table.capacity);
	int i;
	for(i = 0; i < table.capacity/2; i++)
	{temparray[i] = table.array[i];}
	table.array = temparray;

}

bool isEmpty(){
	return (table.top == -1);
}

void push(int data){
	if(table.top == table.capacity-1){
		doubleCapacity();
	}
	table.array[++table.top]=data;
}
void pop(){
	if(isEmpty()){
		printf("Stack was empty\n");
	}
	else{
		printf("Pop out: %d\n",table.array[table.top]);
		table.array[table.top]=0;
		--table.top;
	}
}
void getTop(){
	if(table.top != -1)	printf("Top = %d\n",table.array[table.top]);
	else	printf("Cannot find top, the stack was empty\n");
}

void getSize(){
	printf("Stack size = %d\n",table.top+1);	
}

int main(){
	table.top = -1;
	table.capacity = 2;
	table.array = (int*)malloc(sizeof(int)*table.capacity);
	getTop();
	push(2);
	getTop();
	push(12);
	getTop();
	push(80);
	getTop();
	getSize();
	pop();
	getTop();
	getSize();
	pop();
	getTop();
	getSize();
	pop();
	getTop();
	getSize();
	pop();
	pop();
	getTop();
}
