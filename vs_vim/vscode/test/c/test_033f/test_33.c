#include <stdio.h>

int main() {
    //初始化
    int year = 2023;
    int totalBooks = 100; 

    //开始循环
    do {
        year++;
        if( year % 4 == 0) {
            totalBooks += 50;
        } else if(year % 2 == 1) {
            totalBooks += 30;
        } else {
            totalBooks += 40;
        }
    } while (totalBooks <= 500);         //判断是否停止

    //输出
    printf("%d", year);
    return 0;
}