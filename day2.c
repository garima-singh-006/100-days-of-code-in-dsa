#include <stdio.h>

int main() {
    int n, pos;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &pos);

    // check valid position
    if (pos < 1 || pos > n) {
        printf("Invalid position");
        return 0;
    }

    // shift left
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    // print updated array
    for (int i = 0; i < n - 1; i++)
        printf("%d ", arr[i]);

    return 0;
}