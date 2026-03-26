#include <stdio.h>
int main() {
    int a;
    int *p;
    p = &a;
    a = 5;
    
    // printf("%p\t", &a);
    printf("%p\t", p);
    // printf("%p\t", &p);
    // printf("%d\t", *p);
    // printf("%d\n", a);
    return 0; 
}