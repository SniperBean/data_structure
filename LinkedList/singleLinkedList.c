#include "stdlib.h"
#include "stdio.h"

struct node{
	int data;
	struct node* next;
};
typedef struct node Node;

//真正的Head Node 
Node* ptr;

void printList(Node* head){	
	printf("\n");
	if(head==NULL || head == 0){
		printf("This List is empty\n");
	}
	while(head!=NULL){
		printf("adress = %p\tdata = %d\tnext = %p\n",head,head->data,head->next);
		head=head->next;
	}
}

void pushFront(int data){
	Node* front = (Node*)malloc(sizeof(Node));
	front->data = data;
	front->next = NULL;
	if(ptr != NULL) front->next = ptr;
	ptr = front;
}

void pushBack(int data){
	Node* back = (Node*)malloc(sizeof(Node));
	Node* head = ptr;
	back->data = data;
	back->next = NULL;
	while(head != NULL)
	{
		if(head->next == NULL){
			head->next = back;
			printf("back\n");
			break;
		}
		else{
			head = head->next;
		}
	}
	
	if(head == NULL) ptr = back;
}

void insert(int newdata,int data){
	Node* head = ptr;
	Node* prev = NULL;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = newdata;	
	while(head != NULL && head->data !=data)
	{
		prev = head;
		head = head->next;
	}

	if(head == NULL){
		printf("Cannot find any data in list\n");
	}
	else if(head == ptr){
		prev = head;
		head = head->next;
		prev->next = temp;
		temp->next = head;
		head = NULL;
	}
	else{
		prev->next = temp;
		temp->next = head;
		head = NULL;
	}
}


void update(int newdata,int data){
	Node* head = ptr;
	Node* prev = NULL;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = newdata;	
	while(head != NULL && head->data !=data)
	{
		prev = head;
		head = head->next;
	}

	if(head == NULL){
		printf("Cannot find any data in list\n");
	}
	else if(head == ptr){
		
		head->data = newdata;
	}
	else{
		prev->next = temp;
		temp->next = head->next;
		head = NULL;
	}
}

void delete(int data){
	Node* head = ptr;
	Node* prev = NULL;
	while(head != NULL && head->data !=data)
	{
		prev = head;
		head = head->next;
	}

	if(head == NULL){
		printf("Cannot find any data in list\n");
	}
	else if(head == ptr){
		ptr = head->next;
		head = NULL;
	}
	else{
		prev->next = head->next;
		head = NULL;
	}
}

void reverse(){
	Node* head = ptr;
	Node* prev = NULL;
	Node* proc = ptr->next;
	while(proc != NULL)
	{
		head->next = prev;
		prev = head;
		head = proc;
		proc = proc->next;
	}

	head->next = prev;
	ptr = head;
}

int main()
{
	Node a,b,c;
	ptr = &a;
	//靜態配置測試
	a.data = 10;
	a.next = &b;
	b.data = 30;
	b.next = &c;
	c.data = 100;
	c.next = NULL;
	
	//在list前插入新的node
	printf("插入123在list最前端");	
	pushFront(123);
	printList(ptr);
	printf("插入321在list最後端");	
	pushFront(321);
	printList(ptr);
	//刪除list中擁有數值的node
	printf("刪除擁有10的node");	
	delete(10);
	printList(ptr);
	printf("刪除擁有321的node");
	delete(321);
	printList(ptr);
	//插入新的node在list中擁有數值的node的後方
	printf("插入412在擁有123的node後方");
	insert(412,123);
	printList(ptr);
	//更新list中擁有數值的node
	printf("以333取代擁有123的node");
	update(333,123);
	printList(ptr);
	//反轉list
	printf("反轉list");
	reverse();
	printList(ptr);
	//插入新的node在list最後方
	printf("新增9453在list最後方");
	pushBack(9453);
	printList(ptr);
	delete(100);
	delete(30);
	delete(9453);
	delete(412);
	delete(333);
	printf("測試空list");
	printList(ptr);
	//測試空list可以將數值push Back or Front
	printf("測試空list可以將數值push Back or Front");
	pushBack(41);
	printList(ptr);
}
