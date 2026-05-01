#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int left = 0, right = n - 1;

    // two-pointer swap
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    // print reversed array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}