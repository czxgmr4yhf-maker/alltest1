#include <stdio.h>
#include <math.h>
int main() {
    double s1, s2, s3, s4;
    scanf("%lf %lf %lf %lf", &s1, &s2, &s3, &s4);

    double m1 = s1 * pow(1 + s2/ 100.0, s3);
    double m2 = m1 / (pow(1 + s4/ 100.0, s3));
    double m3 = (pow((m2 / s1), (1.0 / s3)) - 1) * 100;

    printf("%.2f, %.2f, %.2f%%\n", m1, m2, m3);

    return 0;
}