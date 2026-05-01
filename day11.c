#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[100][100], B[100][100], C[100][100];

    // Input first matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Input second matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Addition
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Output result matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}