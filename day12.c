#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[100][100];

    // input matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    // must be square
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != arr[j][i]) {
                printf("Not a Symmetric Matrix");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix");
    return 0;
}