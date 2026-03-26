#include<stdio.h>
int main() {
    int n, x;
    int arr[10] = {0};
    int num = 0;

    scanf("%d %d", &n, &x);

    for (int i = 1; i  <= n; i++) {
        int k = i;
        int index = 0;

        while (k > 0) {
            arr[index++] = k % 10;
            if (arr[index - 1] == x) {
                num += 1;
            }
            k /= 10;
        }
    }

    printf("%d", num);
    return 0;
}