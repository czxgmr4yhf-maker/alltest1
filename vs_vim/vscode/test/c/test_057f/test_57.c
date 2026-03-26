#include <stdio.h>
#include <string.h>

int main() {
    char ss[1000];
    fgets(ss, sizeof(ss), stdin);

    FILE *fp = fopen("test.txt", "a+");
    fprintf(fp, "%s", ss);

    char line[1000];
    rewind(fp); //fseek(fp, 0, SEEK_SET);
    printf("文件已经完成修改,当前test.txt内容是:\n\n");
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
    printf("\n文件保存成功!!!\n");
}