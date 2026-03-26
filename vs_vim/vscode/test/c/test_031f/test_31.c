#include <stdio.h>
#include <math.h>

int main() {
    int num;
    scanf("%d", &num);

    int sum = 0;
    int product = 1;
    for (int i = 0; i < 3; i++) {
        sum += num % 10;
        product *= num % 10;
        num /= 10;
    }

    printf("sum = %d\n", sum);
    printf("product = %d\n", product);
    
    return 0;
}