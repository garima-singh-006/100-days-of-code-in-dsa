#include <stdio.h>
#include <stdlib.h>

// ─────────────────────────────────────────
//  Linked List Node
// ─────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ─────────────────────────────────────────
//  Queue Structure (front & rear pointers)
// ─────────────────────────────────────────
typedef struct Queue {
    Node* front;
    Node* rear;
    int   size;
} Queue;

// ─────────────────────────────────────────
//  Initialize Empty Queue
// ─────────────────────────────────────────
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear  = NULL;
    q->size  = 0;
}

// ─────────────────────────────────────────
//  Check if Queue is Empty
// ─────────────────────────────────────────
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// ─────────────────────────────────────────
//  Enqueue: Insert at REAR
// ─────────────────────────────────────────
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear  = newNode;
    } else {
        q->rear->next = newNode;
        q->rear       = newNode;
    }
    q->size++;
}

// ─────────────────────────────────────────
//  Dequeue: Remove from FRONT
// ─────────────────────────────────────────
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        exit(1);
    }
    Node* temp  = q->front;
    int   value = temp->data;
    q->front    = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return value;
}

// ─────────────────────────────────────────
//  Display: Front → Rear
// ─────────────────────────────────────────
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    Node* curr = q->front;
    while (curr != NULL) {
        if (curr != q->front)
            printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// ─────────────────────────────────────────
//  Free All Remaining Nodes
// ─────────────────────────────────────────
void freeQueue(Queue* q) {
    while (!isEmpty(q))
        dequeue(q);
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    Queue q;
    initQueue(&q);

    int n, value;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(&q, value);
    }

    display(&q);

    freeQueue(&q);
    return 0;
}