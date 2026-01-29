#include "setup.h"


Node *createNode(int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL){
	printf("Create node error!");
	exit(1);
	}

newNode->data = data;
newNode->next = NULL;
return newNode;
}

void insertAtHead(Node **head, int data){
	
	Node *newNode = createNode(data);
	newNode->next = *head;
	*head = newNode;
	}
void printList(Node *head){ // ch? qly du?c thang head 
	Node *temp = head;
	while(temp != NULL){
	printf("%d -> ", temp->data);
	temp = temp->next;
	}
	printf("NULL\n");
	}
void insertAtTail(Node **head, int data){ //chèn thêm 1 node n?a và node g?c vd nhu 30 -> 20 -> 10 -> 9(moi) NULL
	Node *newNode = createNode(data);
	if (*head == NULL){
		*head = newNode;
		return;
}

	Node *temp = *head;
	while(temp->next != NULL){
	temp = temp->next;
	}
	temp->next = newNode;
}
void insertAtPosition(Node **head,int data,int Position){
	if(Position == 1){
	insertAtHead(&(*head),data);
	return;	
	}
	Node *temp = *head;
	for(int i=1; i<Position - 1 && temp != NULL;++i){
		temp = temp -> next;
	}
	if(temp == NULL){
		printf("insertAtPosition!!\n");
		return;
	}
	Node *newNode =  createNode(data);
	newNode -> next = temp -> next;
	temp -> next =newNode;
}
void insertAfterKeys(Node **head, int value,int key){
	Node *temp = *head;
	while(temp != NULL){
		if(temp -> data == key){
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next =newNode;
			temp=temp->next;
		}
		temp =temp->next;
	}
}
void insertBeforeKeys(Node **head, int value,int key){
	Node *temp = *head;
	if(temp == NULL){
		return;
	}
	while(temp != NULL)
		if(temp -> data == key){
			Node *newNode = createNode(value);
			newNode->next = temp->next;
			temp->next =newNode;
			temp=temp->next;
		}
		temp =temp->next;
	}

