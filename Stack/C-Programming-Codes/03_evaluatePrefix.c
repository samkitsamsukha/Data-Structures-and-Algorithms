#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()

struct Stack {
    int top;
    int* st;

    // Constructor equivalent in C
    void initStack(struct Stack* stack) {
        stack->top = -1;
        stack->st = (int*)malloc(100 * sizeof(int));  // Allocate memory for the stack
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
};

int main() {
    char s[100];
    printf("Enter the PREFIX expression: ");
    scanf("%s", s);

    struct Stack st;
    st.initStack(&st);  // Initialize the stack

    int l = strlen(s);

    // Iterate the prefix expression from right to left
    for (int i = l - 1; i >= 0; i--) {
        char c = s[i];

        // If the character is a digit, push it onto the stack
        if (isdigit(c)) {
            int x = c - '0';  // Convert character to integer
            st.push(&st, x);
        } 
        // If the character is an operator, pop two operands and apply the operator
        else {
            int o1 = st.peek(&st);
            st.pop(&st);
            int o2 = st.peek(&st);
            st.pop(&st);

            // Perform the appropriate operation and push the result back onto the stack
            if (c == '+') {
                st.push(&st, o1 + o2);
            } else if (c == '-') {
                st.push(&st, o1 - o2);
            } else if (c == '*') {
                st.push(&st, o1 * o2);
            } else if (c == '/') {
                st.push(&st, o1 / o2);
            }
        }
    }

    // The final result is at the top of the stack
    printf("Answer: %d\n", st.peek(&st));

    return 0;
}
