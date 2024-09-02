#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        struct Node* temp = top;
        int poppedData = temp->data;
        top = top->next;
        free(temp);
        return poppedData;
    }
}

// Function to display the stack
void displayStack() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Application: Check for balanced parentheses
void checkBalancedParentheses(char* expression) {
    for (int count = 0; expression[count]; count++) {
        char ch = expression[count];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == NULL) {
                printf("Unbalanced Parentheses\n");
                return;
            }
            char topChar = pop();
            if ((ch == ')' && topChar != '(') || 
                (ch == '}' && topChar != '{') || 
                (ch == ']' && topChar != '[')) {
                printf("Unbalanced Parentheses\n");
                return;
            }
        }
    }
    if (top == NULL) {
        printf("Balanced Parentheses\n");
    } else {
        printf("Unbalanced Parentheses\n");
    }
}

// Menu-driven main function for stack operations
int main() {
    int choice, data;
    char expression[100];

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Check Balanced Parentheses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter an expression: ");
                scanf("%s", expression);
                checkBalancedParentheses(expression);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
