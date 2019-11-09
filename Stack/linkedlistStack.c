#include "stdlib.h"
#include "stdio.h"
typedef unsigned int bool;
#define false 0
#define true 1
int getTop();

struct node{
	int data;
	struct node* next;
};
typedef struct node Node;

Node* top;

void push(int data){
	Node* head = top;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	while(head != NULL){
		if(head->next == NULL){
			head->next = temp;
			break;
		}
		else{
			head = head->next;
		}
	}
	if(top == NULL){
		top = temp;
		}
}
void pop(){
	Node* head = top;
	Node* prev = (Node*)malloc(sizeof(Node));
	while(head != NULL){

		if(top == head && head->next==NULL){
			printf("Pop out %d\n",getTop());
			top=NULL;
			break;
		}
		else if(head->next == NULL){
			printf("Pop out %d\n",getTop());
			prev->next=NULL;
			break;
		}
		else{
			prev = head;
			head = head->next;
		}
	}
	if(head == NULL) printf("The stack was empty!\n");
}
bool IsEmpty(){
	return (top==NULL);
}
int getTop(){
	Node* head = top;
	while(head != NULL)
	{
		if(head->next != NULL){
			head = head->next;
		}
		else{
			return head->data;
		}
	}

	if(IsEmpty()) return -1;
}
int getSize(){
	int count =0;
	Node* head = top;
	while(head != NULL)
	{
		if(head->next != NULL){
			count++;
			head = head->next;
		}
		else{
			count++;
			break;	
		}
	}
	
	return count;
}

int main(){
	printf("Top = %d\n",getTop());
	printf("Size = %d\n",getSize());
	push(123);
	printf("Top = %d\n",getTop());
	printf("Size = %d\n",getSize());
	push(321);
	printf("Top = %d\n",getTop());
	printf("Size = %d\n",getSize());
	pop();
	printf("Top = %d\n",getTop());
	printf("Size = %d\n",getSize());
	push(435);
	printf("Top = %d\n",getTop());
	pop();
	printf("Top = %d\n",getTop());
	pop();
	printf("Top = %d\n",getTop());
	pop();
	printf("Top = %d\n",getTop());
	pop();
	printf("Top = %d\n",getTop());
	push(9453);
	printf("Top = %d\n",getTop());
	pop();
	printf("Top = %d\n",getTop());
}
