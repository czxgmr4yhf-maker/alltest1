#include <stdio.h>
#include <math.h>
int main() {
    double m1, m2;
    printf("m1 = ");
    scanf("%lf", &m1);
    printf("m2 = ");
    scanf("%lf", &m2);

    double v1, v2;
    printf("v1 = ");
    scanf("%lf", &v1);
    printf("v2 = ");
    scanf("%lf", &v2);

    
    
    double energyLoss = 0.5 * (m1 * m2) / (m1 + m2) * pow((v1 - v2), 2);
    double energyTotal = 0.5 * m1 * pow(v1, 2) + 0.5 * m2 * pow(v2, 2);
    double energyPercent = energyLoss / energyTotal * 100;

    printf("energyLoss = %.2f J\n", energyLoss);
    printf("energyLoss = %.2f %%\n", energyPercent);
    return 0;
}