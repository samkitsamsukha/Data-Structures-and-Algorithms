#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    char* st;

    // Constructor equivalent for stack initialization
    void initStack() {
        top = -1;
        st = (char*)malloc(100 * sizeof(char));  // Allocate memory for 100 characters
    }

    // Push an element onto the stack
    void push(char x) {
        top++;
        st[top] = x;
    }

    // Pop an element from the stack
    void pop() {
        if (top != -1) {
            top--;
        }
    }

    // Check if the stack is empty
    int isEmpty() {
        return (top == -1);
    }

    // Peek the top element of the stack
    char peek() {
        if (top == -1) {
            return '\0';  // Return null character for empty stack
        }
        return st[top];
    }
};

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

    // Wrap the input expression with parentheses
    char expression[102];  // To accommodate '(' and ')'
    expression[0] = '(';
    strcpy(expression + 1, s);
    strcat(expression, ")");

    struct Stack st;
    st.initStack();  // Initialize the stack

    char result[100] = "";  // Resultant postfix expression

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        // If the character is an operand, add it to the result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            int len = strlen(result);
            result[len] = c;
            result[len + 1] = '\0';
        }
        // If the character is '(', push to the stack
        else if (c == '(') {
            st.push(c);
        }
        // If the character is ')', pop until '(' is found
        else if (c == ')') {
            while (st.peek() != '(') {
                int len = strlen(result);
                result[len] = st.peek();
                result[len + 1] = '\0';
                st.pop();
            }
            st.pop();  // Pop the '(' from the stack
        }
        // Operator encountered
        else {
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek())) {
                int len = strlen(result);
                result[len] = st.peek();
                result[len + 1] = '\0';
                st.pop();
            }
            st.push(c);
        }
    }

    // Output the resulting postfix expression
    printf("Postfix expression: %s\n", result);

    return 0;
}
