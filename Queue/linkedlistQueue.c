#include "stdlib.h"
#include "stdio.h"
typedef unsigned int bool;
#define false 0
#define true 1
bool IsEmpty();

struct node{
	int data;
	struct node* next;
};
typedef struct node Node;

Node* front;
Node* back;

void push(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	if(IsEmpty()){
		front = temp;
		back = temp;
	}
	else{
		back->next = temp;
		back = back->next;
	}
}
void pop(){
	if(!IsEmpty()){
		Node* head = front;
		printf("Pop out %d\n", head->data);
		front = front->next;
		free(head);
	}
	else{
		printf("The queue was empty!\n");
	}
}
int getFront(){
	if(IsEmpty()) return -1;
	else return front->data;
}
int getBack(){
	if(IsEmpty()) return -1;
	else return back->data;
}

int getSize(){
	int count=1;
	if(IsEmpty()){
		return -1;
	}
	else{
		Node* head = front;
		while(head->next != NULL){
			count++;
			head = head->next;
		}
		return count;
	}
}

bool IsEmpty(){
	return (front==NULL);
}


int main(){
	printf("Size of Queue = %d\n",getSize());
	push(22);
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	push(541);
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	push(123);
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	push(978);
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	pop();
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	pop();
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	pop();
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
	pop();
	printf("Size of Queue = %d\n",getSize());
	printf("front = %d, back = %d\n",getFront(),getBack());
}
