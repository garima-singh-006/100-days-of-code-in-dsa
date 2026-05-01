#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (n == 0) return 0;

    int k = 0;  // index for unique elements

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[k]) {
            k++;
            arr[k] = arr[i];
        }
    }

    // print unique elements
    for (int i = 0; i <= k; i++)
        printf("%d ", arr[i]);

    return 0;
}