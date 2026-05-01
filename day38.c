#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─────────────────────────────────────────
//  Doubly Linked List Node
// ─────────────────────────────────────────
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// ─────────────────────────────────────────
//  Deque Structure
// ─────────────────────────────────────────
typedef struct Deque {
    Node* front;
    Node* rear;
    int   size;
} Deque;

// ─────────────────────────────────────────
//  Helper: Create New Node
// ─────────────────────────────────────────
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ─────────────────────────────────────────
//  Initialize Empty Deque
// ─────────────────────────────────────────
void initDeque(Deque* dq) {
    dq->front = NULL;
    dq->rear  = NULL;
    dq->size  = 0;
}

// ─────────────────────────────────────────
//  1. empty(): Check if Deque is Empty
// ─────────────────────────────────────────
int empty(Deque* dq) {
    return dq->size == 0;
}

// ─────────────────────────────────────────
//  2. size(): Return Number of Elements
// ─────────────────────────────────────────
int dequeSize(Deque* dq) {
    return dq->size;
}

// ─────────────────────────────────────────
//  3. push_front(): Insert at Front
// ─────────────────────────────────────────
void push_front(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (empty(dq)) {
        dq->front = newNode;
        dq->rear  = newNode;
    } else {
        newNode->next   = dq->front;
        dq->front->prev = newNode;
        dq->front       = newNode;
    }
    dq->size++;
}

// ─────────────────────────────────────────
//  4. push_back(): Insert at Rear
// ─────────────────────────────────────────
void push_back(Deque* dq, int value) {
    Node* newNode = createNode(value);
    if (empty(dq)) {
        dq->front = newNode;
        dq->rear  = newNode;
    } else {
        newNode->prev  = dq->rear;
        dq->rear->next = newNode;
        dq->rear       = newNode;
    }
    dq->size++;
}

// ─────────────────────────────────────────
//  5. pop_front(): Remove from Front
// ─────────────────────────────────────────
void pop_front(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow! (pop_front on empty deque)\n");
        return;
    }
    Node* temp  = dq->front;
    dq->front   = temp->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;   // Deque became empty

    free(temp);
    dq->size--;
}

// ─────────────────────────────────────────
//  6. pop_back(): Remove from Rear
// ─────────────────────────────────────────
void pop_back(Deque* dq) {
    if (empty(dq)) {
        printf("Deque Underflow! (pop_back on empty deque)\n");
        return;
    }
    Node* temp = dq->rear;
    dq->rear   = temp->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;  // Deque became empty

    free(temp);
    dq->size--;
}

// ─────────────────────────────────────────
//  7. getFront(): Return Front Element
// ─────────────────────────────────────────
int getFront(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty! (front)\n");
        exit(1);
    }
    return dq->front->data;
}

// ─────────────────────────────────────────
//  8. getBack(): Return Rear Element
// ─────────────────────────────────────────
int getBack(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty! (back)\n");
        exit(1);
    }
    return dq->rear->data;
}

// ─────────────────────────────────────────
//  9. clear(): Remove All Elements
// ─────────────────────────────────────────
void clear(Deque* dq) {
    while (!empty(dq))
        pop_front(dq);
}

// ─────────────────────────────────────────
//  10. erase(): Remove Element at Position (0-indexed)
// ─────────────────────────────────────────
void erase(Deque* dq, int pos) {
    if (pos < 0 || pos >= dq->size) {
        printf("Invalid position for erase!\n");
        return;
    }
    // Traverse to position
    Node* curr = dq->front;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    // Unlink node
    if (curr->prev) curr->prev->next = curr->next;
    else            dq->front = curr->next;

    if (curr->next) curr->next->prev = curr->prev;
    else            dq->rear = curr->prev;

    free(curr);
    dq->size--;
}

// ─────────────────────────────────────────
//  11. swap(): Swap Two Deques
// ─────────────────────────────────────────
void swapDeques(Deque* dq1, Deque* dq2) {
    Deque temp = *dq1;
    *dq1 = *dq2;
    *dq2 = temp;
}

// ─────────────────────────────────────────
//  12. resize(): Resize Deque (pad 0 or truncate)
// ─────────────────────────────────────────
void resize(Deque* dq, int newSize) {
    while (dq->size > newSize)
        pop_back(dq);
    while (dq->size < newSize)
        push_back(dq, 0);
}

// ─────────────────────────────────────────
//  13. assign(): Replace all elements with a value
// ─────────────────────────────────────────
void assign(Deque* dq, int count, int value) {
    clear(dq);
    for (int i = 0; i < count; i++)
        push_back(dq, value);
}

// ─────────────────────────────────────────
//  14. reverse(): Reverse the Deque
// ─────────────────────────────────────────
void reverse(Deque* dq) {
    Node* curr = dq->front;
    while (curr != NULL) {
        // Swap prev and next pointers
        Node* temp  = curr->prev;
        curr->prev  = curr->next;
        curr->next  = temp;
        curr        = curr->prev;   // Move forward (now stored in prev)
    }
    // Swap front and rear
    Node* temp  = dq->front;
    dq->front   = dq->rear;
    dq->rear    = temp;
}

// ─────────────────────────────────────────
//  15. sort(): Sort using Bubble Sort
// ─────────────────────────────────────────
void sortDeque(Deque* dq) {
    if (dq->size <= 1) return;
    int swapped;
    do {
        swapped = 0;
        Node* curr = dq->front;
        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                // Swap data only (not nodes)
                int temp        = curr->data;
                curr->data      = curr->next->data;
                curr->next->data = temp;
                swapped = 1;
            }
            curr = curr->next;
        }
    } while (swapped);
}

// ─────────────────────────────────────────
//  Display: Front → Rear
// ─────────────────────────────────────────
void display(Deque* dq) {
    if (empty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Front -> ");
    Node* curr = dq->front;
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next) printf(" <-> ");
        curr = curr->next;
    }
    printf(" <- Rear\n");
}

// ─────────────────────────────────────────
//  Main: Demonstrate All Operations
// ─────────────────────────────────────────
int main() {
    Deque dq;
    initDeque(&dq);

    printf("════════════════════════════════════════\n");
    printf("         DEQUE OPERATIONS DEMO\n");
    printf("════════════════════════════════════════\n\n");

    // ── push_back & push_front ──────────────
    printf("── push_back(10, 20, 30) ──\n");
    push_back(&dq, 10);
    push_back(&dq, 20);
    push_back(&dq, 30);
    display(&dq);

    printf("\n── push_front(5), push_front(1) ──\n");
    push_front(&dq, 5);
    push_front(&dq, 1);
    display(&dq);

    // ── front & back ───────────────────────
    printf("\n── front(): %d ──\n", getFront(&dq));
    printf("── back() : %d ──\n", getBack(&dq));
    printf("── size()  : %d ──\n", dequeSize(&dq));

    // ── pop_front & pop_back ───────────────
    printf("\n── pop_front() ──\n");
    pop_front(&dq);
    display(&dq);

    printf("\n── pop_back() ──\n");
    pop_back(&dq);
    display(&dq);

    // ── reverse ────────────────────────────
    printf("\n── reverse() ──\n");
    reverse(&dq);
    display(&dq);

    // ── sort ───────────────────────────────
    printf("\n── sort() ──\n");
    sortDeque(&dq);
    display(&dq);

    // ── erase at position 1 ────────────────
    printf("\n── erase(pos=1) ──\n");
    erase(&dq, 1);
    display(&dq);

    // ── resize to 5 (pads with 0s) ─────────
    printf("\n── resize(5) ──\n");
    resize(&dq, 5);
    display(&dq);

    // ── assign 3 elements of value 7 ───────
    printf("\n── assign(3, value=7) ──\n");
    assign(&dq, 3, 7);
    display(&dq);

    // ── swap ───────────────────────────────
    printf("\n── swap(dq1, dq2) ──\n");
    Deque dq2;
    initDeque(&dq2);
    push_back(&dq2, 100);
    push_back(&dq2, 200);
    printf("Before swap:\n");
    printf("  dq1: "); display(&dq);
    printf("  dq2: "); display(&dq2);
    swapDeques(&dq, &dq2);
    printf("After swap:\n");
    printf("  dq1: "); display(&dq);
    printf("  dq2: "); display(&dq2);

    // ── clear ──────────────────────────────
    printf("\n── clear() ──\n");
    clear(&dq);
    clear(&dq2);
    printf("empty(): %s\n", empty(&dq) ? "true" : "false");

    return 0;
}