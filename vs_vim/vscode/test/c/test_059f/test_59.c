#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverseInt(size_t n, char *ss, char *reverseString) {
    if (!strcmp(ss, "0")) {
        reverseString[0] = ss[0];
        reverseString[1] = '\0';
        return;
    }

    int j = 0;
    for (int i = (int)n - 1; i >= 0; i--) {
        if(!j && ss[i] == '0') continue;
        reverseString[j++] = ss[i];
    }

    reverseString[j] = '\0';
}

bool isZero(char *ss) {
    for (int i = strlen(ss) - 1; i >= 0; i--) {
        if (ss[i] != '0') return false;
    }

    return true;
}
void reverseFloat(size_t n, char *ss, char *reverseString) {
    if (isZero(ss)) {
        reverseString[0] = ss[0];
        reverseString[1] = '\0';
        return;
    }

    int j = 0;
    for (int i = (int)n - 1; i >= 0; i--) {
        reverseString[j++] = ss[i];
    }

    for (int i = (int)n - 1; i >= 0; i--) {
        if(reverseString[i] != '0') {
            reverseString[i + 1] = '\0';
            break;
        }
    }
}
int main(){
    char line[100];
    fgets(line, sizeof(line), stdin);
    // printf("%s\n", line);
    int sign = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '.') sign = 1;
        if (line[i] == '/') sign = 2;
        if (line[i] == '%') sign = 3;
    }
    // printf("%d", sign);

    char a[32];
    char b[32];
    char a_t[32];
    char b_t[32];
    if (sign == 0) {
        sscanf(line, "%31s", a);
        reverseInt(strlen(a), a, a_t);

        printf("%s\n", a_t);        
    } else if(sign == 1) {
        sscanf(line, "%31[^.].%31s", a, b);
        reverseInt(strlen(a), a, a_t);
        reverseFloat(strlen(b), b, b_t);
        
        printf("%s.%s\n", a_t, b_t);
    } else if(sign == 2) {
        sscanf(line, "%31[^/]/%31s", a, b);
        reverseInt(strlen(a), a, a_t);
        reverseInt(strlen(b), b, b_t);

        printf("%s/%s\n", a_t, b_t);
    }else if(sign == 3) {
        sscanf(line, "%31[^%]", a);
        reverseInt(strlen(a), a, a_t);

        printf("%s%%\n", a_t);
    } else{
        printf("您的输入格式有误\n");
    }
}