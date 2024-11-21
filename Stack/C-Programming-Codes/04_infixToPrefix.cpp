#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Stack {
    int top;
    char* st;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
    stack->st = (char*)malloc(100 * sizeof(char));  // Allocate memory for 100 characters
    if (stack->st == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to push an element onto the stack
void push(struct Stack* stack, char x) {
    stack->top++;
    stack->st[stack->top] = x;
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (stack->top != -1) {
        stack->top--;
    }
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    if (stack->top == -1) {
        return '\0';  // Return null character for empty stack
    }
    return stack->st[stack->top];
}

// Function to define precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to reverse a string
void reverse(char* exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    struct Stack st;
    initStack(&st);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(&st, c);
        }
        // If the character is ')', pop until '(' is found
        else if (c == ')') {
            while (!isEmpty(&st) && peek(&st) != '(') {
                postfix[j++] = peek(&st);
                pop(&st);
            }
            pop(&st);  // Pop the '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c)) {
            while (!isEmpty(&st) && precedence(c) <= precedence(peek(&st))) {
                postfix[j++] = peek(&st);
                pop(&st);
            }
            push(&st, c);
        }
    }

    // Pop the remaining operators from the stack
    while (!isEmpty(&st)) {
        postfix[j++] = peek(&st);
        pop(&st);
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Reverse the infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the modified infix expression to postfix
    char postfix[100];
    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get the prefix expression
    reverse(postfix);

    // Copy the result to the prefix output
    strcpy(prefix, postfix);
}

int main() {
    char infix[100];
    printf("Enter the INFIX expression: ");
    scanf("%s", infix);

    char prefix[100];
    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
