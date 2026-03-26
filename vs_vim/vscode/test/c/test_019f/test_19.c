/*Average by category*/
#include<stdio.h>
#include<stdlib.h>

double average(int *arr, int index);

int main() {
    int n, k;
    int indexA = 0;
    int indexB = 0;

    //input
    // printf("Please input two numbers.\n");
    scanf("%d %d", &n, &k);
    int *number_A = (int *)malloc(n * sizeof(int)); //dynamic array
    int *number_B = (int *)malloc(n * sizeof(int)); //dynamic array ;it points addrees

    //acquire the array
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k == 0) {
            number_A[indexA++] = i +1;
        } else {
            number_B[indexB++] = i + 1;
        }
    }

    
    //acquire average
    double ave_A = average(number_A, indexA);
    double ave_B = average(number_B, indexB);
    
    //print
    printf("%.1f %.1f\n", ave_A, ave_B);

    free(number_A);
    free(number_B);
    return 0;
}

double average(int *arr, int index) {
    int num = 0;
    for (int i = 0; i < index; i++) {
        num += arr[i];
    }
    return (double)num / index;
}