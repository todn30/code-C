#include "insert.cpp"
#include "delete.cpp"


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

