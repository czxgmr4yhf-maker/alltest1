#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n);
int main(){
    int maxn;
    int minn;

    char word[100];
    fgets(word, sizeof(word), stdin);

    int alpha[26] = {0};
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            alpha[word[i] - 'a']++;
            minn = maxn = alpha[word[i] - 'a'];
        }
    }

    for (int i = 0; i < 26; i++){
        if (maxn < alpha[i] && alpha[i] > 0) maxn = alpha[i];
        if (minn > alpha[i] && alpha[i] > 0) minn = alpha[i];
    }

    if (isPrime(maxn - minn)) {
        printf("Lucky Word\n%d\n", maxn - minn);
    } else {
        printf("No Answer\n0\n");
    }
       
}
bool isPrime(int n) {
    if (n <= 0 || n == 1) return false;
    if (n == 2 || n % 2 == 0) return true;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) return false;
    }

    return true;
}