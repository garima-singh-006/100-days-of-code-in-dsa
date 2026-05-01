#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack for operators (char type)
char stack[MAX];
int top = -1;

// Push operator
void push(char c) {
    stack[++top] = c;
}

// Pop operator
char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

// Peek top of stack
char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Get precedence of operator
int precedence(char op) {
    if (op == '^')          return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
void infix_to_postfix(char *expr, char *result) {
    int k = 0;  // Index for result

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        // Case 1: Operand → directly to output
        if (isalnum(c)) {
            result[k++] = c;
        }
        // Case 2: '(' → push onto stack
        else if (c == '(') {
            push(c);
        }
        // Case 3: ')' → pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                result[k++] = pop();
            pop();  // Remove '(' from stack
        }
        // Case 4: Operator
        else {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(c)) {
                result[k++] = pop();
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (top != -1)
        result[k++] = pop();

    result[k] = '\0';  // Null terminate
}

int main() {
    char expr[MAX], result[MAX];

    scanf("%s", expr);
    infix_to_postfix(expr, result);
    printf("%s\n", result);

    return 0;
}