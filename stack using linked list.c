#include <stdio.h>
#include <stdlib.h>
// Define the structure for a stack node
typedef struct Node {
   int data;
   struct Node* next;
} Node;
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
// Function to check if the stack is empty
int isEmpty(Node* top) {
   return top == NULL;
}
// Function to push an element onto the stack
void push(Node** top, int data) {
   Node* newNode = createNode(data);
   if (!newNode) {
       printf("Stack Overflow!\n");
       return;
   }
   newNode->next = *top;
   *top = newNode;
   printf("Pushed %d onto the stack.\n", data);
}
// Function to pop an element from the stack
int pop(Node** top) {
   if (isEmpty(*top)) {
       printf("Stack Underflow!\n");
       return -1; // Return -1 to indicate underflow
   }
   Node* temp = *top;
   int poppedData = temp->data;
   *top = (*top)->next;
   free(temp);
   return poppedData;
}
// Function to peek at the top element of the stack
int peek(Node* top) {
   if (isEmpty(top)) {
       printf("Stack is empty!\n");
       return -1; // Return -1 to indicate empty stack
   }
   return top->data;
}
// Function to display the stack elements
void display(Node* top) {
   if (isEmpty(top)) {
       printf("Stack is empty!\n");
       return;
   }
   Node* temp = top;
   printf("Stack: ");
   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}
// Main function to demonstrate stack operations
int main() {
   Node* stack = NULL; // Initialize an empty stack
   push(&stack, 10);
   push(&stack, 20);
   push(&stack, 30);
   display(stack);
   printf("Top element is: %d\n", peek(stack));
   printf("Popped element: %d\n", pop(&stack));
   display(stack);
   printf("Popped element: %d\n", pop(&stack));
   display(stack);
   printf("Popped element: %d\n", pop(&stack));
   // Attempting to pop from an empty stack
   pop(&stack);
   return 0;
}
