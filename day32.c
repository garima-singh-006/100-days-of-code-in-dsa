#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n, m, value;

    // Read n and push elements
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Read m and pop elements
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining elements from top to bottom
    for (int i = top; i >= 0; i--) {
        if (i != top)
            printf(" ");
        printf("%d", stack[i]);
    }
    printf("\n");

    return 0;
}