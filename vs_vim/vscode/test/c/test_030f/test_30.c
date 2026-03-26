#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main() {
    double pi = M_PI;
    double r;
    printf("R = ");
    scanf("%lf", &r);

    double perimeter = 2 * pi * r;
    double area = pi * r * r;
    double volume = 4.0 / 3 * pi * pow(r, 3);

    printf("permeter = %.2f\n", perimeter);
    printf("area = %.2f\n", area);
    printf("volume = %.2f\n", volume);

    return 0;
}