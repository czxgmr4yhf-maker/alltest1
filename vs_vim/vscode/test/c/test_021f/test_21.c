#include<stdio.h>
int main(){
    int n;
    int index = 1;
    
    //input
    scanf("%d", &n);

    //output
    while (n != 0) {
       for (int i = 0; i < n; i++ ) {
        if(index < 10) {
            printf("0%d", index);
        } else {
            printf("%d", index);
        }
        index++;    
       }
        n--; 
        printf("\n");
    }
    
    return 0;
}