#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int arr[n * n];
    for(int i = 0; i < n * n; i++) arr[i] = 0;

    int sum = 0;
    int change = 0;
    int t;
    int start = 0;
    while(scanf("%d", &t) == 1) {
        change++;
        sum += t;
        if (change % 2 == 1) {
            for (int i = start; i < sum) {
                arr[i] = 0;
            }
            start = sum;
        } else {
            for ()
        }
    }
}