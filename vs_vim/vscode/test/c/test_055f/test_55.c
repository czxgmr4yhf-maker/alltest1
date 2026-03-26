#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    FILE *fp = fopen("test.txt", "w");
    if(fp == NULL) return 0;

    char c;
    while((scanf("%c", &c) != 0) && c != '\n') {
        if(islower(c)) fputc(toupper(c), fp);
        else fputc(c, fp);
    }

    fclose(fp);
    printf("File is saved!\n");
}

