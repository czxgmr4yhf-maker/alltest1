#include <stdio.h>
int count_paths(int n);
int main() {
    int n;
    scanf("%d", &n);

    int cout = count_paths(n);
    printf("%d\n", cout);
    return 0;
}
int count_paths(int n) {
    if (n == 1 || n == 0) return 1;

    return count_paths(n - 1) + count_paths(n - 2);
}