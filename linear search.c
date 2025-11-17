#include <stdio.h>
#include <stdlib.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int n, key;

    // Input array size
    printf("Enter number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    // Input key to search
    printf("Enter the element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    // Perform search
    int result = linearSearch(arr, n, key);

    // Output result
    if (result != -1) {
        printf("Element %d found at position %d (index %d).\n", key, result + 1, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
