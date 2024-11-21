#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    char s[100];
    printf("Enter the INFIX expression: ");
    scanf("%s", s);

    //? Wrap the input expression with parentheses
    char expression[102];  // To accommodate '(' and ')'
    expression[0] = '(';
    strcpy(expression + 1, s);
    strcat(expression, ")");

    struct Stack st;
    initStack(&st);  // Initialize the stack

    char result[100] = "";  // Resultant postfix expression

    //? Iterate over the input expression
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        // If the character is an operand, add it to the result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            int len = strlen(result);
            result[len] = c;
            result[len + 1] = '\0';
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            push(&st, c);
        }
        // If the character is ')', pop until '(' is found
        else if (c == ')') {
            while (peek(&st) != '(') {
                int len = strlen(result);
                result[len] = peek(&st);
                result[len + 1] = '\0';
                pop(&st);
            }
            pop(&st);  // Pop the '(' from the stack
        }
        // Operator encountered
        else {
            while (!isEmpty(&st) && precedence(c) <= precedence(peek(&st))) {
                int len = strlen(result);
                result[len] = peek(&st);
                result[len + 1] = '\0';
                pop(&st);
            }
            push(&st, c);
        }
    }

    // Output the resulting postfix expression
    printf("Postfix expression: %s\n", result);

    // Free the dynamically allocated memory
    free(st.st);

    return 0;
}
