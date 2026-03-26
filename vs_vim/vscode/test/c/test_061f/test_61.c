#include <stdio.h>
int main() {
    int n;
    int arr[21][21];
    scanf("%d", &n);

    for(int i = 1; i < 21; i++) {
        arr[i][1] = 1;
        arr[i][i] = 1;
    }

    for (int i = 3; i < 21; i++) {
        for (int j = 2; j < i; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < i + 1; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}