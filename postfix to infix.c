#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char* str) {
    strcpy(stack[++top], str);
}

void pop(char* result) {
    strcpy(result, stack[top--]);
}

void postfixToInfix(char* expression) {
    char operand1[MAX], operand2[MAX], operator[2], temp[MAX];

    for (int count = 0; expression[count]; count++) {
        char ch = expression[count];

        if (isalnum(ch)) {
            operator[0] = ch;
            operator[1] = '\0';
            push(operator);
        } else {
            pop(operand2);
            pop(operand1);
            snprintf(temp, MAX, "(%s%c%s)", operand1, ch, operand2);
            push(temp);
        }
    }

    printf("Infix Expression: %s\n", stack[top]);
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    gets(expression);

    postfixToInfix(expression);

    return 0;
}
