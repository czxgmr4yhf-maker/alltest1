#include <stdio.h>

int factorial(int n) {
    if (n == 1 || n == 0) return 1; 
    return n*factorial(n - 1);
}
int main(){
    int n;
    scanf("%d", &n);
    
    int factor = factorial(n);
    printf("%d\n", factor);
}