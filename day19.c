#include <stdio.h>
#include <stdlib.h>

// comparator for qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // sort array
    qsort(arr, n, sizeof(int), cmp);

    int left = 0, right = n - 1;
    int min_sum = arr[left] + arr[right];
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        // update closest sum
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            x = arr[left];
            y = arr[right];
        }

        // move pointers
        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);

    return 0;
}