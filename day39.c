#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ─────────────────────────────────────────
//  Min Heap Structure
// ─────────────────────────────────────────
typedef struct MinHeap {
    int arr[MAX];   // Array to store heap elements
    int size;       // Current number of elements
} MinHeap;

// ─────────────────────────────────────────
//  Index Helpers (1-based indexing)
// ─────────────────────────────────────────
//        parent(i) = i / 2
//   leftChild(i)   = 2 * i
//   rightChild(i)  = 2 * i + 1
// ─────────────────────────────────────────

int parent(int i)     { return i / 2; }
int leftChild(int i)  { return 2 * i; }
int rightChild(int i) { return 2 * i + 1; }

// ─────────────────────────────────────────
//  Swap Two Elements
// ─────────────────────────────────────────
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ─────────────────────────────────────────
//  Initialize Heap
// ─────────────────────────────────────────
void initHeap(MinHeap* h) {
    h->size = 0;
}

// ─────────────────────────────────────────
//  Heapify Up (after insert)
//  Bubble inserted element UP to fix heap
// ─────────────────────────────────────────
void heapifyUp(MinHeap* h, int i) {
    while (i > 1 && h->arr[parent(i)] > h->arr[i]) {
        swap(&h->arr[parent(i)], &h->arr[i]);
        i = parent(i);
    }
}

// ─────────────────────────────────────────
//  Heapify Down (after extractMin)
//  Push root element DOWN to fix heap
// ─────────────────────────────────────────
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left     = leftChild(i);
    int right    = rightChild(i);

    // Find smallest among node, left child, right child
    if (left  <= h->size && h->arr[left]  < h->arr[smallest])
        smallest = left;
    if (right <= h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    // If smallest is not current node, swap and recurse
    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// ─────────────────────────────────────────
//  INSERT: Add element to heap         O(log n)
// ─────────────────────────────────────────
void insert(MinHeap* h, int value) {
    if (h->size >= MAX) {
        printf("Heap Overflow!\n");
        return;
    }
    h->size++;
    h->arr[h->size] = value;   // Add at last position
    heapifyUp(h, h->size);     // Fix heap property upward
}

// ─────────────────────────────────────────
//  PEEK: Return minimum (root) element  O(1)
// ─────────────────────────────────────────
void peek(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", h->arr[1]);  // Root is always minimum
}

// ─────────────────────────────────────────
//  EXTRACT MIN: Remove & return minimum O(log n)
// ─────────────────────────────────────────
void extractMin(MinHeap* h) {
    if (h->size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", h->arr[1]);              // Print min (root)
    h->arr[1] = h->arr[h->size];            // Move last → root
    h->size--;                              // Shrink heap
    heapifyDown(h, 1);                      // Fix heap downward
}

// ─────────────────────────────────────────
//  Display Heap Array (for debugging)
// ─────────────────────────────────────────
void display(MinHeap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap Array: ");
    for (int i = 1; i <= h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    MinHeap h;
    initHeap(&h);

    int n;
    scanf("%d", &n);

    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(&h, val);

        } else if (strcmp(op, "extractMin") == 0) {
            extractMin(&h);

        } else if (strcmp(op, "peek") == 0) {
            peek(&h);

        } else {
            printf("Unknown operation: %s\n", op);
        }
    }

    return 0;
}