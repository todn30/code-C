#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *next;
} Node;

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

void freeList(Node **head){
Node *temp = NULL;
while(*head != NULL){
temp = *head;
*head = temp->next;
free(temp);
}
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
void deleteAtHead(Node **head){
	if(*head == NULL){
		printf("Linked list empty!\n");
		return;
	}
	Node *temp = *head;
	*head = temp-> next;
	free(temp);
}
void deleteAtTail(Node **head){
	if(*head == NULL){
		printf("Linked list empty!\n");
		return;
	}
	Node *temp = *head;
	if (temp -> next ==NULL){
		free(*head);
		*head = NULL;
		return;
	}
	while(temp->next->next != NULL){
		temp = temp ->next;
	}
	free(temp->next);
	temp->next = NULL;
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

//int main(){
//Node *head = NULL;
//insertAtHead(&head, 10);
//insertAtHead(&head, 20);
//insertAtHead(&head, 30);
//
//printList(head); //10 -> 20 -> 30 -> NULL
//deleteAtHead(&head);
//printList(head); //20 -> 30 -> NULL
//deleteAtHead(&head);
//printList(head); //30 -> NULL
//deleteAtHead(&head);
//printList(head); // NULL
//deleteAtHead(&head);// list empty
//
//// 30 -> 20 -> 10 -> NULL
////printList(head);
//freeList(&head);
//
//}
//int main(){
//Node *head = NULL;
//insertAtTail(&head, 10);
//insertAtTail(&head, 20);
//insertAtTail(&head, 30);
//
//printList(head); //10 -> 20 -> 30 -> NULL
//insertAtPosition(&head, 50,10); //insertAtPosition
//insertAtPosition(&head, 40,4);
//printList(head); //10 -> 20 -> 30 -> 40 -> NULL
//insertAtPosition(&head, 25,3);
//printList(head); //10 -> 20 ->25 -> 30-> 40 -> NULL
//insertAtPosition(&head, 5,1);// list empty
//printList(head);
////5-> 10 -> 20 -> 25 -> 30 ->40-> NULL
//printList(head);
//freeList(&head);
//
//}

//có th? thêm nhi?u dadtaa trong struct

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
//int main(){
//	Node *head= NULL;
//	insertAtTail(&head,50);
//	insertAtTail(&head,10);
//	insertAtTail(&head,10);
//	insertAtTail(&head,10);
//	insertAtTail(&head,50);
//	printList(head); //50->10->10->10->50->NULL
//	insertAfterKeys(&head,60,10);
//	printList(head); //50->60->10->60->10->60->10->60->50->NULL
//	
//	freeList(&head);
//}
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
//int main(){
//	Node *head= NULL;
//	insertAtTail(&head,10);
//	insertAtTail(&head,10);
//	insertAtTail(&head,10);
//	insertAtTail(&head,50);
//	
//	printList(head); //10->10->10->50->NULL
//	insertBeforeKeys(&head,60,10);
//	printList(head); //60->10->60->10->60->10->50->NULL
//	
//	freeList(&head);
//}

void deleteAtPosition(Node **head,int data,int Position){
	if(Position == 1){
	deleteAtHead(&(*head));
	return;	
	}
	Node *temp = *head;
	for(int i=1; i<Position - 1 && temp != NULL;++i){
		temp = temp -> next;
	}
	if(temp == NULL){
		printf("Position out of range!!\n");
		return;
	}
	Node *del =  temp->	next;
	temp -> next = del -> next;
	free(del);
}

//int main() {
//Node *head = NULL;
//insertAtTail(&head, 10);
//insertAtTail(&head, 20);
//insertAtTail(&head, 30);
//insertAtTail(&head, 50);
//
//printList(head); //10 -> 20 -> 30 ->50-> NULL
//deleteAtPosition(&head, 10); //OUT	
//deleteAtPosition(&head, 4);
//printList(head); //10 -> 20 -> 30 -> NULL
//deleteAtPosition(&head, 2);
//printList(head); //10 -> 30 -> NULL
//deleteAtPosition(&head, 1);
//printList(head); //30->NULL
//
//printList(head);
//freeList(&head);
//
//}
//void deleteAfterKeys(Node **head, int key){
//Node *temp = *head;
//if (temp == NULL) 
//return;
//while(temp != NULL && temp->next != NULL){
//if(temp->data == key){
//Node *del = temp->next;
//temp->next = del->next;
//if (del->data != key){
//temp = temp->next;
//}
//free(del);
//} else {
//temp = temp->next;
//}
//}
//}

void deleteBeforeKeys(Node **head,int key){
	if(*head == NULL || (*head)->next ==NULL) {
	return;
}
	while((*head)->next->data == key)
	deleteAtHead(&(*head));
	Node *temp = *head;
	while(temp->next->next->data == key){
		Node *del = temp->next;
		temp->next = del->next;
		free(del);
	}
	temp = temp->next;
}
//int main() {
//Node *head = NULL;
//insertAtTail(&head, 8);
//insertAtTail(&head, 3);
//insertAtTail(&head, 5);
//insertAtTail(&head, 6);
//insertAtTail(&head, 3);
//insertAtTail(&head, 6);
//
//printList(head);// 8 -> 3 -> 5 -> 6 -> 3 -> 6 -> NULL
//deleteBeforeKeys(&head, 3); 
//printList(head);    // 3 -> 5 -> 3 -> 6 -> NULL
//
//freeList(&head);
//}
void deleteAllKeys(Node **head,int key){
	while (*head != NULL && (*head)->data == key){
		deleteAtHead(&(*head));
	}
	Node *temp= *head;
	while(temp !=NULL && temp->next != NULL){
		if(temp->next->data==key){
			Node *del =temp->next;
			temp->next = del->next;
			free(del);
		} else{
			temp = temp->next;
		}
	}
}
int main() {
Node *head = NULL;
insertAtTail(&head, 3); 
insertAtTail(&head, 3);
insertAtTail(&head, 6);
insertAtTail(&head, 3);
insertAtTail(&head, 3);
insertAtTail(&head, 8);

printList(head);// 8 -> 3 -> 5 -> 6 -> 3 -> 6 -> NULL
deleteAllKeys(&head, 3); 
printList(head);    // 3 -> 5 -> 3 -> 6 -> NULL

freeList(&head);
}

