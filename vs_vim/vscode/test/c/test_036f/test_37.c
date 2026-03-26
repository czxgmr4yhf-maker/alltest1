#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    //初始化
    int num = 0;
    int total = 0;

    //用户进行循环输入
    while(true) {
        int x;
        scanf("%d", &x);
        if (x < 0) {
            break;
        } else {
            total += x;
            num++; 
        }
    }

    double avg = 1.0 * total / num;
    printf("个数:%d 总和:%d 平均值:%.2f", num, total, avg);
    return 0;   
}