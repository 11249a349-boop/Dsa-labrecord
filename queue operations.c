#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct {
   int items[MAX_SIZE];
   int front;
   int rear;
} Queue;
// Initialize the queue
void initializeQueue(Queue* q) {
   q->front = -1;
   q->rear = -1;
}
// Check if the queue is empty
bool isEmpty(Queue* q) {
   return (q->front == -1 || q->front > q->rear);
}
// Check if the queue is full
bool isFull(Queue* q) {
   return (q->rear == MAX_SIZE - 1);
}
// Enqueue operation (Insert element)
void enqueue(Queue* q, int value) {
   if (isFull(q)) {
       printf("Queue Overflow\n");
       return;
   }
   if (q->front == -1) {
       q->front = 0; // Initialize front for the first element
   }
   q->rear++;
   q->items[q->rear] = value;
   printf("Enqueued: %d\n", value);
}
// Dequeue operation (Remove element)
void dequeue(Queue* q) {
   if (isEmpty(q)) {
       printf("Queue Underflow\n");
       return;
   }
   printf("Dequeued: %d\n", q->items[q->front]);
   q->front++;
}
// Peek operation (View front element)
int peek(Queue* q) {
   if (isEmpty(q)) {
       printf("Queue is empty\n");
       return -1;
   }
   return q->items[q->front];
}
// Display the queue
void display(Queue* q) {
   if (isEmpty(q)) {
       printf("Queue is empty\n");
       return;
   }
   printf("Current Queue: ");
   for (int i = q->front; i <= q->rear; i++) {
       printf("%d ", q->items[i]);
   }
   printf("\n");
}
int main() {
   Queue q;
   initializeQueue(&q);
   enqueue(&q, 10);
   enqueue(&q, 20);
   enqueue(&q, 30);
   display(&q);
   printf("Front element: %d\n", peek(&q));
   dequeue(&q);
   display(&q);
   printf("Front element after dequeue: %d\n", peek(&q));
   return 0;
}
