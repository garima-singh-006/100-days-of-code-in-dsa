#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int a[100], b[100], c[200];

    for (int i = 0; i < p; i++)
        scanf("%d", &a[i]);

    scanf("%d", &q);

    for (int i = 0; i < q; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0, k = 0;

    // merge both arrays
    while (i < p && j < q) {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    // remaining elements
    while (i < p)
        c[k++] = a[i++];

    while (j < q)
        c[k++] = b[j++];

    // print merged array
    for (int x = 0; x < p + q; x++)
        printf("%d ", c[x]);

    return 0;
}