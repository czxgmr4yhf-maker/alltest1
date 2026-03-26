#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isLeapYear(int n);
int main() {
    int head, tail;
    scanf("%d %d", &head, &tail);

    int sum = 0;
    for (int i = head + 1; i < tail; i++) {
        if (isLeapYear(i)) sum += i;
    }

    printf("%d\n", sum);
}
bool isLeapYear(int n) {
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)  return true;

    return false;
}