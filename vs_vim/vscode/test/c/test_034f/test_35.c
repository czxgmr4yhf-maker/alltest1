#include <stdio.h>
#include <math.h>

int square(int n);

int main() {
    //初始化
    int a, b;
    scanf("%d %d", &a, &b);
    int total = 0;

    //循环
    for (int i = a; i <= b; i++) {
        total += square(i);
    }

    //输出
    printf("%d", total);
    return 0;
}

int square(int n) {
    return n*n;
}