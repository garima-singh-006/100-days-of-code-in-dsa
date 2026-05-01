#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode;

    // Create circular linked list
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    if (temp != NULL)
        temp->next = head;

    // Traverse circular list
    if (head != NULL) {
        struct Node* curr = head;
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != head);
    }

    return 0;
}