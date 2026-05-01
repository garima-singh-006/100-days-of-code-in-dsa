#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[100][100];

    // input matrix
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // top row (left → right)
        for (int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        // right column (top → bottom)
        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // bottom row (right → left)
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        // left column (bottom → top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}