#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to enqueue an element to the queue
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        struct Node* temp = front;
        int dequeuedData = temp->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
        return dequeuedData;
    }
}

// Function to display the queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Application: Simulate a basic print queue
void simulatePrintQueue() {
    int data;
    char choice;

    do {
        printf("Enter job to enqueue (number): ");
        scanf("%d", &data);
        enqueue(data);

        printf("Do you want to add another job (y/n)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nProcessing print queue...\n");

    while (front != NULL) {
        data = dequeue();
        if (data != -1) {
            printf("Printing job: %d\n", data);
        }
    }
}

// Menu-driven main function for queue operations
int main() {
    int choice, data;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Simulate Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                simulatePrintQueue();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
