#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {
    if (size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    int count;
    for (count = size - 1; count >= 0; count--) {
        if (value > pq[count]) {
            pq[count + 1] = pq[count];
        } else {
            break;
        }
    }
    pq[count + 1] = value;
    size++;
    printf("%d inserted into priority queue.\n", value);
}

int delete() {
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
        return -1;
    }
    return pq[--size];
}

int peek() {
    if (size == 0) {
        printf("Priority Queue is Empty!\n");
        return -1;
    }
    return pq[size - 1];
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Delete\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Highest priority value: %d\n", value);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
