/*级数求和*/
#include<stdio.h>
int main() {
    double sum = 0.0;
    int n  = 1;
    int a_init = 1; 

    scanf("%d", &n);

    while (sum <= n) {
        sum += 1.0 / a_init;
        a_init++; 
    }

    printf("%d", a_init - 1);

    return 0;
}