#include <stdio.h>
#include <stdlib.h>
// Define the structure for a doubly linked list node
typedef struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
} Node;
// Function to create a new node
Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->next = NULL;
   newNode->prev = NULL;
   return newNode;
}
// Insert at the beginning
void insertAtBeginning(Node** head, int data) {
   Node* newNode = createNode(data);
   if (*head != NULL) {
       newNode->next = *head;
       (*head)->prev = newNode;
   }
   *head = newNode;
}
// Insert at the end
void insertAtEnd(Node** head, int data) {
   Node* newNode = createNode(data);
   if (*head == NULL) {
       *head = newNode;
       return;
   }
   Node* temp = *head;
   while (temp->next != NULL)
       temp = temp->next;
   temp->next = newNode;
   newNode->prev = temp;
}
// Delete from the beginning
void deleteAtBeginning(Node** head) {
   if (*head == NULL) {
       printf("List is empty.\n");
       return;
   }
   Node* temp = *head;
   *head = (*head)->next;
   if (*head != NULL)
       (*head)->prev = NULL;
   free(temp);
}
// Delete from the end
void deleteAtEnd(Node** head) {
   if (*head == NULL) {
       printf("List is empty.\n");
       return;
   }
   Node* temp = *head;
   while (temp->next != NULL)
       temp = temp->next;
   if (temp->prev != NULL)
       temp->prev->next = NULL;
   else
       *head = NULL; // If only one node exists
   free(temp);
}
// Traverse forward
void traverseForward(Node* head) {
   printf("Forward Traversal: ");
   while (head != NULL) {
       printf("%d ", head->data);
       head = head->next;
   }
   printf("\n");
}
// Traverse backward
void traverseBackward(Node* head) {
   if (head == NULL) {
       printf("List is empty.\n");
       return;
   }
   while (head->next != NULL)
       head = head->next; // Move to the last node
   printf("Backward Traversal: ");
   while (head != NULL) {
       printf("%d ", head->data);
       head = head->prev;
   }
   printf("\n");
}
int main() {
   Node* head = NULL;
   // Perform operations
   insertAtBeginning(&head, 10);
   insertAtBeginning(&head, 20);
   insertAtEnd(&head, 30);
   printf("After Insertions:\n");
   traverseForward(head);
   deleteAtBeginning(&head);
   printf("After Deletion at Beginning:\n");
   traverseForward(head);
   deleteAtEnd(&head);
   printf("After Deletion at End:\n");
   traverseForward(head);
   return 0;
}
