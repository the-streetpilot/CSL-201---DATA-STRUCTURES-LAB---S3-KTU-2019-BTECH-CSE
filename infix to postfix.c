#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation
char pop() {
    return stack[top--];
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix to postfix
void infixToPostfix(char* expression) {
    char result[MAX];
    int k = 0;

    for (int count = 0; expression[count]; count++) {
        char ch = expression[count];

        // If the character is an operand, add it to the result
        if (isalnum(ch)) {
            result[k++] = ch;
        }
        // If the character is '(', push it to the stack
        else if (ch == '(') {
            push(ch);
        }
        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                result[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                result[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0'; // Null terminate the result

    printf("Postfix Expression: %s\n", result);
}

int main() {
    char expression[MAX];
    printf("Enter an infix expression: ");
    gets(expression);

    infixToPostfix(expression);

    return 0;
}
