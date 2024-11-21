#include <stdio.h>
#include <stdlib.h> // for malloc()

typedef struct STACK {
    int top;
    int* st;
} STACK;

// Function to initialize the stack
void initStack(struct STACK* stack, int size) {
    stack->top = -1;
    stack->st = (int*)malloc(size * sizeof(int)); // Allocate memory for the stack
}

// Function to push an element onto the stack
void push(struct STACK* stack, int x, int size) {
    if (stack->top == size - 1) {
        printf("Stack Overflow\n");
        return;
    } else {
        stack->top++;
        stack->st[stack->top] = x;
    }
}

// Function to pop an element from the stack
int pop(struct STACK* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->st[stack->top--];
    }
}

// Function to check if the stack is empty
int isEmpty(struct STACK* stack) {
    return stack->top == -1;
}

// Function to get the top element of the stack
int peek(struct STACK* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->st[stack->top];
}

int main() {
    printf("Enter stack size: ");
    int n;
    scanf("%d", &n);

    STACK st;
    initStack(&st, n); // Initialize the stack

    // Example usage
    push(&st, 1, n);
    push(&st, 2, n);
    printf("Top element is: %d\n", peek(&st));
    printf("Popping element: %d\n", pop(&st));
    printf("Top element after pop: %d\n", peek(&st));

    // Free dynamically allocated memory
    free(st.st);

    return 0;
}