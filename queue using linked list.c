#include <stdio.h>
#include <stdlib.h>
// Define a node structure
typedef struct Node {
   int data;
   struct Node* next;
} Node;
// Define a queue structure
typedef struct Queue {
   Node* front;
   Node* rear;
} Queue;
// Function to create a new node
Node* createNode(int data) {
   Node* newNode = (Node*)malloc(sizeof(Node));
   if (!newNode) {
       printf("Memory allocation failed!\n");
       return NULL;
   }
   newNode->data = data;
   newNode->next = NULL;
   return newNode;
}
// Function to create an empty queue
Queue* createQueue() {
   Queue* q = (Queue*)malloc(sizeof(Queue));
   q->front = q->rear = NULL;
   return q;
}
// Enqueue operation: Add an element to the rear of the queue
void enqueue(Queue* q, int data) {
   Node* newNode = createNode(data);
   if (!newNode) return;
   if (q->rear == NULL) { // If the queue is empty
       q->front = q->rear = newNode;
       return;
   }
   q->rear->next = newNode; // Link the new node at the end of the queue
   q->rear = newNode; // Update the rear pointer
}
// Dequeue operation: Remove an element from the front of the queue
int dequeue(Queue* q) {
   if (q->front == NULL) { // If the queue is empty
       printf("Queue Underflow!\n");
       return -1;
   }
   Node* temp = q->front; // Store the front node temporarily
   int data = temp->data; // Retrieve the data from the front node
   q->front = q->front->next; // Move the front pointer to the next node
   if (q->front == NULL) // If the queue becomes empty, update rear to NULL
       q->rear = NULL;
   free(temp); // Free memory of dequeued node
   return data;
}
// Display operation: Print all elements in the queue
void display(Queue* q) {
   if (q->front == NULL) {
       printf("Queue is Empty!\n");
       return;
   }
   Node* temp = q->front;
   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}
// Main function to demonstrate queue operations
int main() {
   Queue* q = createQueue();
   enqueue(q, 10);
   enqueue(q, 20);
   enqueue(q, 30);
   printf("Queue: ");
   display(q);
   printf("Dequeued: %d\n", dequeue(q));
   printf("Queue after dequeue: ");
   display(q);
   return 0;
}
