#include <stdio.h>
#include <stdlib.h>

// ─────────────────────────────────────────
//  Doubly Linked List Node
// ─────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// ─────────────────────────────────────────
//  Circular Queue Structure
// ─────────────────────────────────────────
typedef struct CircularQueue {
    Node* front;   // Points to front node
    Node* rear;    // Points to rear node
    int   size;    // Current number of elements
} CircularQueue;

// ─────────────────────────────────────────
//  Initialize Empty Circular Queue
// ─────────────────────────────────────────
void initQueue(CircularQueue* cq) {
    cq->front = NULL;
    cq->rear  = NULL;
    cq->size  = 0;
}

// ─────────────────────────────────────────
//  Check if Queue is Empty
// ─────────────────────────────────────────
int isEmpty(CircularQueue* cq) {
    return cq->size == 0;
}

// ─────────────────────────────────────────
//  Enqueue: Insert at REAR
// ─────────────────────────────────────────
void enqueue(CircularQueue* cq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;

    if (isEmpty(cq)) {
        // Only node: point to itself (circular link)
        newNode->next = newNode;
        newNode->prev = newNode;
        cq->front     = newNode;
        cq->rear      = newNode;
    } else {
        // Link new node between rear and front (circular)
        newNode->next       = cq->front;   // new → front
        newNode->prev       = cq->rear;    // new ← rear
        cq->rear->next      = newNode;     // rear → new
        cq->front->prev     = newNode;     // front ← new
        cq->rear            = newNode;     // update rear
    }
    cq->size++;
}

// ─────────────────────────────────────────
//  Dequeue: Remove from FRONT
// ─────────────────────────────────────────
int dequeue(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue Underflow! Queue is empty.\n");
        exit(1);
    }

    Node* temp  = cq->front;
    int   value = temp->data;

    if (cq->size == 1) {
        // Last node removed
        cq->front = NULL;
        cq->rear  = NULL;
    } else {
        // Relink: skip front node
        cq->front           = temp->next;    // move front forward
        cq->front->prev     = cq->rear;      // front ← rear (circular)
        cq->rear->next      = cq->front;     // rear → front (circular)
    }

    free(temp);
    cq->size--;
    return value;
}

// ─────────────────────────────────────────
//  Rotate: Dequeue from front, Enqueue at rear
//  (Circular behaviour: element cycles back)
// ─────────────────────────────────────────
void rotate(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty! Cannot rotate.\n");
        return;
    }
    int value = dequeue(cq);
    enqueue(cq, value);
}

// ─────────────────────────────────────────
//  Peek Front
// ─────────────────────────────────────────
int peekFront(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return cq->front->data;
}

// ─────────────────────────────────────────
//  Peek Rear
// ─────────────────────────────────────────
int peekRear(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    return cq->rear->data;
}

// ─────────────────────────────────────────
//  Display: Front → Rear (circular order)
// ─────────────────────────────────────────
void display(CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* curr = cq->front;
    for (int i = 0; i < cq->size; i++) {
        if (i != 0) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// ─────────────────────────────────────────
//  Free All Nodes
// ─────────────────────────────────────────
void freeQueue(CircularQueue* cq) {
    while (!isEmpty(cq))
        dequeue(cq);
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    CircularQueue cq;
    initQueue(&cq);

    int n, m, value;

    // Read and enqueue n elements
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&cq, value);
    }

    // Read m and rotate m times (dequeue front → enqueue rear)
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        rotate(&cq);
    }

    // Display final queue front to rear
    display(&cq);

    freeQueue(&cq);
    return 0;
}