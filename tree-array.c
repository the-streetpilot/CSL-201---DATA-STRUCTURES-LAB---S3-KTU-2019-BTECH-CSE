#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Array-based binary tree
int tree[MAX_SIZE];
int size = 0;

// Function to insert a node in a binary tree
void insertNode(int data) {
    if (size >= MAX_SIZE) {
        printf("Tree is full\n");
        return;
    }
    tree[size++] = data;
}

// Function to print a binary tree
void printTree() {
    if (size == 0) {
        printf("Tree is empty\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d -> ", tree[i]);
    }
    printf("NULL\n");
}

// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(int index) {
    if (index >= size) return;
    inorderTraversal(2 * index + 1); // Left child
    printf("%d -> ", tree[index]);
    inorderTraversal(2 * index + 2); // Right child
}

// Function for preorder traversal (Root, Left, Right)
void preorderTraversal(int index) {
    if (index >= size) return;
    printf("%d -> ", tree[index]);
    preorderTraversal(2 * index + 1); // Left child
    preorderTraversal(2 * index + 2); // Right child
}

// Function for postorder traversal (Left, Right, Root)
void postorderTraversal(int index) {
    if (index >= size) return;
    postorderTraversal(2 * index + 1); // Left child
    postorderTraversal(2 * index + 2); // Right child
    printf("%d -> ", tree[index]);
}

// Menu-driven main function for binary tree operations (array-based)
int main() {
    int choice, data;

    while (1) {
        printf("\nBinary Tree (Array) Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Print Tree\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                printTree();
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(0);
                printf("NULL\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorderTraversal(0);
                printf("NULL\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorderTraversal(0);
                printf("NULL\n");
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
