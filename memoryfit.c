#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100  // Size of the memory

int memory[MEMORY_SIZE];  // Array to represent memory (0: free, 1: occupied)

// Initialize memory with all free blocks
void initializeMemory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;  // 0 indicates free
    }
}

// Display the current state of memory
void displayMemory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 1) {
            printf("Occupied ");
        } else {
            printf("Free ");
        }
    }
    printf("\n");
}

// First-Fit Allocation
int firstFit(int size) {
    int start = -1;
    int i = 0;

    while (i < MEMORY_SIZE) {
        if (memory[i] == 0) {  // Free block
            start = i;
            int freeSize = 0;
            while (i < MEMORY_SIZE && memory[i] == 0) {
                freeSize++;
                if (freeSize == size) {
                    break;
                }
                i++;
            }
            if (freeSize >= size) {
                for (int j = start; j < start + size; j++) {
                    memory[j] = 1;  // Mark as occupied
                }
                return start;
            }
        } else {
            i++;
        }
    }
    return -1;  // Not enough memory
}

// Best-Fit Allocation
int bestFit(int size) {
    int bestStart = -1;
    int minWaste = MEMORY_SIZE + 1;  // Larger than any possible waste

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) {  // Free block
            int start = i;
            int freeSize = 0;
            while (i < MEMORY_SIZE && memory[i] == 0) {
                freeSize++;
                if (freeSize >= size) {
                    int waste = freeSize - size;
                    if (waste < minWaste) {
                        bestStart = start;
                        minWaste = waste;
                    }
                    break;
                }
                i++;
            }
        }
    }

    if (bestStart != -1) {
        for (int j = bestStart; j < bestStart + size; j++) {
            memory[j] = 1;  // Mark as occupied
        }
    }
    return bestStart;
}

// Worst-Fit Allocation
int worstFit(int size) {
    int worstStart = -1;
    int maxFreeSize = -1;

    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) {  // Free block
            int start = i;
            int freeSize = 0;
            while (i < MEMORY_SIZE && memory[i] == 0) {
                freeSize++;
                if (freeSize >= size) {
                    if (freeSize > maxFreeSize) {
                        worstStart = start;
                        maxFreeSize = freeSize;
                    }
                    break;
                }
                i++;
            }
        }
    }

    if (worstStart != -1) {
        for (int j = worstStart; j < worstStart + size; j++) {
            memory[j] = 1;  // Mark as occupied
        }
    }
    return worstStart;
}

// Deallocate memory block
void deallocate(int start, int size) {
    if (start >= 0 && start + size <= MEMORY_SIZE) {
        for (int i = start; i < start + size; i++) {
            memory[i] = 0;  // Mark as free
        }
        printf("Deallocated block starting at %d\n", start);
    } else {
        printf("Invalid start index or size\n");
    }
}

// Main simulation function
void simulateAllocations() {
    int choice, size, start;

    while (1) {
        printf("\nMemory Allocation Simulation\n");
        printf("1. First-Fit Allocation\n");
        printf("2. Best-Fit Allocation\n");
        printf("3. Worst-Fit Allocation\n");
        printf("4. Deallocate Block\n");
        printf("5. Display Memory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter block size to allocate: ");
                scanf("%d", &size);
                start = firstFit(size);
                if (start != -1) {
                    printf("Allocated at index %d\n", start);
                } else {
                    printf("Not enough memory available\n");
                }
                break;

            case 2:
                printf("Enter block size to allocate: ");
                scanf("%d", &size);
                start = bestFit(size);
                if (start != -1) {
                    printf("Allocated at index %d\n", start);
                } else {
                    printf("Not enough memory available\n");
                }
                break;

            case 3:
                printf("Enter block size to allocate: ");
                scanf("%d", &size);
                start = worstFit(size);
                if (start != -1) {
                    printf("Allocated at index %d\n", start);
                } else {
                    printf("Not enough memory available\n");
                }
                break;

            case 4:
                printf("Enter start index and size to deallocate: ");
                scanf("%d %d", &start, &size);
                deallocate(start, size);
                break;

            case 5:
                displayMemory();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}

// Main function
int main() {
    initializeMemory();
    simulateAllocations();
    return 0;
}
