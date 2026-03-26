#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int upperAlpha = 0;
    int lowerAlpha = 0;
    int digits = 0;

    char ss[50];
    fgets(ss, sizeof(ss), stdin);
    for (int i = 0; ss[i] != '\0'; i++) {
        if(isupper(ss[i])) upperAlpha++;
        if(islower(ss[i])) lowerAlpha++;
        if(isdigit(ss[i])) digits++;
    }

    int length = digits + lowerAlpha + upperAlpha;
    if (length >= 8 && digits && lowerAlpha && upperAlpha) {
        printf("大写字母：%d个, 小写字母: %d个, 数字：%d个;该字符串是强密码\n", 
            upperAlpha, 
            lowerAlpha,
            digits);
    } else {
        printf("大写字母：%d个, 小写字母: %d个, 数字：%d个;该字符串不是强密码\n", 
            upperAlpha, 
            lowerAlpha,
            digits);
    }
}