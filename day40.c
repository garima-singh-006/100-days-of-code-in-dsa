#include <stdio.h>

// ─────────────────────────────────────────
//  Helper: Swap Two Elements
// ─────────────────────────────────────────
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ─────────────────────────────────────────
//  Heapify: Maintain Max Heap Property
//  i    = current node index
//  n    = current heap size
// ─────────────────────────────────────────
void heapify(int arr[], int n, int i) {
    int largest = i;           // Assume current node is largest
    int left    = 2 * i + 1;  // Left  child index
    int right   = 2 * i + 2;  // Right child index

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root → swap and recurse
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);   // Fix the affected subtree
    }
}

// ─────────────────────────────────────────
//  Build Max Heap from Unsorted Array
//  Start from last non-leaf node → index (n/2 - 1)
// ─────────────────────────────────────────
void buildMaxHeap(int arr[], int n) {
    // Last non-leaf node is at index (n/2 - 1)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// ─────────────────────────────────────────
//  Heap Sort
//  1. Build max heap
//  2. Extract max (root) one by one
// ─────────────────────────────────────────
void heapSort(int arr[], int n) {
    // Phase 1: Build Max Heap
    buildMaxHeap(arr, n);

    // Phase 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (maximum) to end
        swap(&arr[0], &arr[i]);

        // Heapify reduced heap (exclude sorted elements)
        heapify(arr, i, 0);
    }
}

// ─────────────────────────────────────────
//  Display Array
// ─────────────────────────────────────────
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

// ─────────────────────────────────────────
//  Print Heap as Tree (Visual)
// ─────────────────────────────────────────
void printHeapTree(int arr[], int n) {
    int level = 0, count = 1, idx = 0;
    printf("\n  MAX HEAP TREE:\n  ");
    while (idx < n) {
        for (int i = 0; i < count && idx < n; i++, idx++) {
            printf("%d ", arr[idx]);
        }
        printf("\n  ");
        level++;
        count *= 2;
    }
    printf("\n");
}

// ─────────────────────────────────────────
//  Main
// ─────────────────────────────────────────
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal Array  : ");
    display(arr, n);

    // ── Phase 1: Build Max Heap ─────────────
    buildMaxHeap(arr, n);
    printf("After BuildHeap : ");
    display(arr, n);
    printHeapTree(arr, n);

    // ── Phase 2: Heap Sort ──────────────────
    printf("  Step-by-step extraction:\n");
    printf("  %-5s %-25s %s\n", "Step", "Array State", "Action");
    printf("  ──────────────────────────────────────────────\n");

    // Re-build to show steps (sort on copy)
    int brr[n];
    for (int i = 0; i < n; i++) brr[i] = arr[i];

    // arr already max-heapified, show extraction steps
    for (int i = n - 1; i > 0; i--) {
        printf("  %-5d ", n - i);
        printf("Swap arr[0]=%d <-> arr[%d]=%d  →  ",
               arr[0], i, arr[i]);
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        display(arr, n);
    }

    printf("\nSorted Array    : ");
    display(arr, n);

    return 0;
}