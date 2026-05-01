#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL)
            head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int countKey(struct Node* head, int key) {
    int count = 0;

    while (head != NULL) {
        if (head->data == key)
            count++;
        head = head->next;
    }

    return count;
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node* head = createList(n);

    scanf("%d", &key);

    printf("%d", countKey(head, key));

    return 0;
}