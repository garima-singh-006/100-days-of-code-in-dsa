#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// ─────────────────────────────────────────
//  Linked List Node (Stack Node)
// ─────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ─────────────────────────────────────────
//  Stack Operations (Dynamic Memory)
// ─────────────────────────────────────────

// Push: allocate new node, link at top
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop: remove top node, free memory, return value
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = temp->next;
    free(temp);           // Dynamic deallocation
    return value;
}

// Peek: view top without removing
int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return top->data;
}

// Check if stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// ─────────────────────────────────────────
//  Postfix Evaluator
// ─────────────────────────────────────────
int evaluatePostfix(char* expr) {
    Node* top = NULL;   // Linked list stack (initially empty)

    char* token = strtok(expr, " ");

    while (token != NULL) {

        // ── Operand: push onto stack ──────────
        if (isdigit(token[0]) ||
           (token[0] == '-' && strlen(token) > 1)) {
            push(&top, atoi(token));
        }

        // ── Operator: pop two operands, compute, push result ──
        else {
            int b = pop(&top);   // Second operand (popped first)
            int a = pop(&top);   // First operand  (popped second)
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero!\n");
                        exit(1);
                    }
                    result = a / b;
                    break;
                case '%': result = a % b; break;
                default:
                    printf("Unknown operator: %s\n", token);
                    exit(1);
            }
            push(&top, result);
        }

        token = strtok(NULL, " ");
    }

    int finalResult = pop(&top);  // Last element = answer

    // Free any remaining nodes (safety cleanup)
    while (!isEmpty(top))
        pop(&top);

    return finalResult;
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    char expr[200];

    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';  // Remove trailing newline

    int result = evaluatePostfix(expr);
    printf("%d\n", result);

    return 0;
}