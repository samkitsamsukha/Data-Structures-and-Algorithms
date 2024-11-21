#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int top;
    char* st[100];  // Stack to store strings (operands and sub-expressions)
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char* x) {
    stack->top++;
    stack->st[stack->top] = x;
}

// Function to pop an element from the stack
char* pop(struct Stack* stack) {
    if (stack->top != -1) {
        return stack->st[stack->top--];
    }
    return NULL;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert a postfix expression to an infix expression
void postfixToInfix(char* postfix, char* infix) {
    struct Stack st;
    initStack(&st);

    int length = strlen(postfix);

    // Iterate over the postfix expression from left to right
    for (int i = 0; i < length; i++) {
        char c = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(c)) {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = c;
            operand[1] = '\0';
            push(&st, operand);
        }
        // If the character is an operator, pop two operands from the stack, combine them with the operator, and push the result back to the stack
        else if (isOperator(c)) {
            char* operand2 = pop(&st);
            char* operand1 = pop(&st);

            // Create a new string to store the infix expression
            char* temp = (char*)malloc(strlen(operand1) + strlen(operand2) + 4);
            sprintf(temp, "(%s%c%s)", operand1, c, operand2);

            // Push the new infix expression back to the stack
            push(&st, temp);

            // Free the memory of the popped operands
            free(operand1);
            free(operand2);
        }
    }

    // The final infix expression is stored at the top of the stack
    strcpy(infix, pop(&st));
}

int main() {
    char postfix[100];
    printf("Enter the POSTFIX expression: ");
    scanf("%s", postfix);

    char infix[100];
    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}
