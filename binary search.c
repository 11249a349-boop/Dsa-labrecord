#include <stdio.h>
int main() {
   int arr[10], n, search, first, last, middle;
   // Input the size of the array
   printf("Enter the number of elements (max 10): ");
   scanf("%d", &n);
   // Input the sorted array
   printf("Enter %d elements in ascending order:\n", n);
   for (int i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
   }
   // Input the element to search
   printf("Enter the element to search: ");
   scanf("%d", &search);
   // Initialize variables for binary search
   first = 0;
   last = n - 1;
   middle = (first + last) / 2;
   // Perform binary search
   while (first <= last) {
       if (arr[middle] == search) {
           printf("Element %d found at position %d.\n", search, middle + 1);
           return 0;
       } else if (arr[middle] < search) {
           first = middle + 1; // Search in the right half
       } else {
           last = middle - 1; // Search in the left half
       }
       middle = (first + last) / 2;
   }
   // If element is not found
   printf("Element %d is not present in the array.\n", search);
   return 0;
}
