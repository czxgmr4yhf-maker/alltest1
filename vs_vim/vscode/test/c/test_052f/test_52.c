#include <stdio.h>
double cost(double weight, char area);
int  main(){
    char area;
    double weight;
    scanf ("%lf %c", &weight, &area);

    double money = cost(weight, area);

    printf("总运费为: %.1f￥\n", money);
}
double cost(double weight, char area) {
    if (area == 'A') {
        if (weight < 1) {
            return 8;
        } else {
            double sum = 8.0;
            weight -= 1;
            for (int i = 1; i * 0.5 < weight + 0.5; i++) {
                sum += 2;
            }
            return sum;
        }
    } else if (area == 'B') {
        if (weight < 1) {
            return 12;
        } else {
            weight -= 1;
            double sum = 12.0;
            for (int i = 1; i * 0.5 < weight + 0.5; i++) {
                sum += 3;
            }
            return sum;
        }
    }
    return 0;
}