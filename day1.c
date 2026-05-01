#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);

    int arr[100];  // fixed size (simple for beginners)

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &pos, &x);

    // shift right
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = x;

    // print
    for (int i = 0; i <= n; i++)
        printf("%d ", arr[i]);

    return 0;
}