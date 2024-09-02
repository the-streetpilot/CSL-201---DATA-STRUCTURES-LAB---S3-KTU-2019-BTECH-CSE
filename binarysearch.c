#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) {
            return m;  // Return the index of the target
        }
        if (arr[m] < target) {
            l = m + 1;  // Search in the right half
        } else {
            r = m - 1;  // Search in the left half
        }
    }
    return -1;  // Target not found
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {10, 22, 35, 40, 45, 50, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 35;

    printf("Array: ");
    printArray(arr, n);

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }
    return 0;
}

