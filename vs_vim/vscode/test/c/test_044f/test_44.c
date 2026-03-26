#include <stdio.h>


int main() {
    const int hour = 24;
    const int minute = 60;
    const int second = 60;
    int h, m, s;
    char daytime;
    scanf("%d %d %d %c", &h, &m, &s, &daytime);

    int sumSecond = 0;
    if (daytime == 'P') sumSecond = hour * minute * second / 2;
    sumSecond += h * minute * second + m * second + s;

    printf("%d\n", sumSecond);
    return 0;
}