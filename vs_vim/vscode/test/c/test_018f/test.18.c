/*soldiers who pass the river*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    //input 
    int n;
    scanf("%d", &n);

    int *aaArray = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &aaArray[i]);
    }
    
    //search the least number
    for (int i = 0; i < n - 1; i++){
         for (int i = 0; i < n - 1; i++) {
            if (aaArray[i] > aaArray[i + 1]) {
                int m = aaArray[i];
                aaArray[i] = aaArray[i + 1];
                aaArray[i + 1] = m;
            }
        }
    }

    //output
    printf("%d", aaArray[0]);
       
    //free memory
    free(aaArray);
    return 0;
}