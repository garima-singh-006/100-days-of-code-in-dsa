#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ─────────────────────────────────────────
//  Priority Queue Structure
// ─────────────────────────────────────────
typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

// ─────────────────────────────────────────
//  Initialize
// ─────────────────────────────────────────
void init(PriorityQueue* pq) {
    pq->size = 0;
}

// ─────────────────────────────────────────
//  Check if Empty
// ─────────────────────────────────────────
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// ─────────────────────────────────────────
//  Insert: Add element, maintain sorted order
//  (ascending → smallest at index 0 = highest priority)
// ─────────────────────────────────────────
void insert(PriorityQueue* pq, int value) {
    if (pq->size == MAX) {
        printf("Priority Queue is Full!\n");
        return;
    }

    // Find correct position to insert (keep array sorted)
    int i = pq->size - 1;

    // Shift elements right to make room
    while (i >= 0 && pq->data[i] > value) {
        pq->data[i + 1] = pq->data[i];
        i--;
    }

    // Place value at correct position
    pq->data[i + 1] = value;
    pq->size++;
}

// ─────────────────────────────────────────
//  Delete: Remove highest priority (smallest value)
// ─────────────────────────────────────────
int delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        return -1;
    }

    int minVal = pq->data[0];   // Smallest is at index 0

    // Shift all elements left
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
    }
    pq->size--;

    return minVal;
}

// ─────────────────────────────────────────
//  Peek: View highest priority without removing
// ─────────────────────────────────────────
int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        return -1;
    }
    return pq->data[0];   // Smallest element
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    PriorityQueue pq;
    init(&pq);

    int n;
    scanf("%d", &n);

    char operation[10];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {
            scanf("%d", &value);
            insert(&pq, value);

        } else if (strcmp(operation, "delete") == 0) {
            printf("%d\n", delete(&pq));

        } else if (strcmp(operation, "peek") == 0) {
            printf("%d\n", peek(&pq));
        }
    }

    return 0;
}