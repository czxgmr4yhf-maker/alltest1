#include <stdio.h>
int main(){
    FILE *fpr = fopen("test.txt", "r");
    if(fpr == NULL) return 0;
    FILE *fpw = fopen("cptest.txt", "w");
    if (fpw == NULL) return 0;

    char line[100];
    while(fgets(line, sizeof(line), fpr)) {
        fprintf(fpw, "%s", line);
    }

    fclose(fpr);
    fclose(fpw);
    printf("文件复制完成!!!\n");
}