#include <stdio.h>
#define MAX 100

int dequeue[MAX];
int front = -1;
int rear = -1;

// Insert at the front
void insertFront() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Dequeue overflow!\n");
    } else {
        printf("Enter value to insert at front: ");
        scanf("%d", &value);
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front--;
        }
        dequeue[front] = value;
        printf("%d inserted at front.\n", value);
    }
}

// Insert at the rear
void insertRear() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Dequeue overflow!\n");
    } else {
        printf("Enter value to insert at rear: ");
        scanf("%d", &value);
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        dequeue[rear] = value;
        printf("%d inserted at rear.\n", value);
    }
}

// Delete from the front
void deleteFront() {
    if (front == -1) {
        printf("Dequeue underflow!\n");
    } else {
        printf("Deleted element from front is %d\n", dequeue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

// Delete from the rear
void deleteRear() {
    if (rear == -1) {
        printf("Dequeue underflow!\n");
    } else {
        printf("Deleted element from rear is %d\n", dequeue[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear--;
        }
    }
}

// Display dequeue
void display() {
    if (front == -1) {
        printf("Dequeue is empty!\n");
    } else {
        printf("Dequeue elements are:\n");
        int count = front;
        while (1) {
            printf("%d\n", dequeue[count]);
            if (count == rear) break;
            count = (count + 1) % MAX;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
