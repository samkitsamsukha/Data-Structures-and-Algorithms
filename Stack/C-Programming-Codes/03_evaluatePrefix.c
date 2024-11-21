#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()
#include <string.h> // for strlen()

struct Stack {
    int top;
    int* st;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
    stack->st = (int*)malloc(100 * sizeof(int));  // Allocate memory for the stack
    if (stack->st == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Push an element onto the stack
void push(struct Stack* stack, int x) {
    stack->top++;
    stack->st[stack->top] = x;
}

// Pop an element from the stack
void pop(struct Stack* stack) {
    if (stack->top != -1) {
        stack->top--;
    }
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (stack->top == -1) {
        return -1;  // Error value, stack is empty
    }
    return stack->st[stack->top];
}

int main() {
    char s[100];
    printf("Enter the PREFIX expression: ");
    scanf("%s", s);

    struct Stack st;
    initStack(&st);  // Initialize the stack

    int l = strlen(s);

    // Iterate the prefix expression from right to left
    for (int i = l - 1; i >= 0; i--) {
        char c = s[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(c)) {
            int x = c - '0';  // Convert character to integer
            push(&st, x);
        } 
        // If the character is an operator, pop two operands and apply the operator
        else {
            int o1 = peek(&st);
            pop(&st);
            int o2 = peek(&st);
            pop(&st);

            // Perform the appropriate operation and push the result back onto the stack
            if (c == '+') {
                push(&st, o1 + o2);
            } else if (c == '-') {
                push(&st, o1 - o2);
            } else if (c == '*') {
                push(&st, o1 * o2);
            } else if (c == '/') {
                push(&st, o1 / o2);
            }
        }
    }
    // The final result is at the top of the stack
    printf("Answer: %d\n", peek(&st));
    // Free dynamically allocated memory
    free(st.st);
    return 0;
}
