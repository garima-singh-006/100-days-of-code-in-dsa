#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100][100];

    // input matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    // check identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (arr[i][j] != 1) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            } else {
                if (arr[i][j] != 0) {
                    printf("Not an Identity Matrix");
                    return 0;
                }
            }
        }
    }

    printf("Identity Matrix");
    return 0;
}