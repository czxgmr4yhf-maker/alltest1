#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[101];
    fgets(s, 101, stdin);

    for (int i = 0; i < 101; i++) {
        if (isalpha((unsigned char)s[i])){
            s[i] = toupper((unsigned char)s[i]);
        }
    }

    printf("%s", s);
}