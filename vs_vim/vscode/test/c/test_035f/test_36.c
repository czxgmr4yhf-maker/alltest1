#include <stdio.h>

int main() {
    //由数学分析可得，当x/y取得大于1/3的最小值时，得到的s是最大值
    int x, y;
    int x1, y1;
    double product = 1.0/2;

    //判断
    for (int x = 2; x <= 9; x++) {
        for (int y = 2; y <= 9; y++) {
            if ((double)x/y > 1.0/3 && 3*x != y && product > (double)x/y) {
                product = (double)x/y;
                x1 = x;
                y1 = y;
            }
        }
    }

    //输出
    printf("x = %d, y = %d\n", x1, y1);
    return 0;
}