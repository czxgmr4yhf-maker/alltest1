#include <stdio.h>
int digit_sum(int n);
int main() {
    int n;
    scanf("%d", &n);

    int sum = digit_sum(n);
    printf("%d\n", sum);
    return 0;
}
int digit_sum(int n) {
    if (n == 0) return 0;

    return n % 10 + digit_sum(n / 10);
}